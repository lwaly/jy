/*******************************************************************************
* Project:  DataProxyServer
* @file     StepReadFromDb.cpp
* @brief
* @author   xxx
* @date:    2016年3月19日
* @note
* Modify history:
******************************************************************************/
#include "StepSendToDbAgent.hpp"

namespace neb {

    StepSendToDbAgent::StepSendToDbAgent(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate,
        std::shared_ptr<SessionRedisNode> pNodeSession, int iRelative, const neb::CJsonObject* pTableField, const std::string& strKeyField, const neb::CJsonObject* pJoinField)
        : m_pChannel(pChannel), m_oReqMsgHead(oInMsgHead), m_oMemOperate(oMemOperate), m_iRelative(iRelative), m_strKeyField(strKeyField)
        , m_oTableField(pTableField), m_oJoinField(pJoinField), m_bFieldFilter(false), m_bNeedResponse(true), m_pNodeSession(pNodeSession), pStepWriteBackToRedis(NULL)
    {
    }

    StepSendToDbAgent::~StepSendToDbAgent()
    {
    }

    E_CMD_STATUS StepSendToDbAgent::Emit(int iErrno, const std::string& strErrMsg, const std::string& strErrShow)
    {
        MsgHead oOutMsgHead;
        MsgBody oOutMsgBody;
        if (neb::Mydis::DbOperate::SELECT != m_oMemOperate.db_operate().query_type() && m_oMemOperate.has_redis_operate())
        {
            m_bNeedResponse = false;
        }
        LOG4_TRACE("%s(m_bNeedResponse = %d)", __FUNCTION__, m_bNeedResponse);
        if (RELATIVE_DATASET == m_iRelative && neb::Mydis::DbOperate::SELECT == m_oMemOperate.db_operate().query_type())
        {
            for (int i = 0; i < m_oMemOperate.db_operate().fields_size(); ++i)
            {
                if ((m_oTableField(i) != m_oMemOperate.db_operate().fields(i).col_name())
                    && (m_oMemOperate.db_operate().fields(i).col_as().size() > 0
                    && m_oTableField(i) != m_oMemOperate.db_operate().fields(i).col_as()))
                {
                    m_bFieldFilter = true;
                    break;
                }
            }
            // 客户端请求表的部分字段，但redis需要所有字段来回写，故修改向数据库的请求数据，待返回结果集再筛选部分字段回复客户端，所有字段用来回写redis
            if (m_bFieldFilter)
            {
                neb::Mydis oMemOperate = m_oMemOperate;
                neb::Mydis::DbOperate* oDbOper = oMemOperate.mutable_db_operate();
                oDbOper->clear_fields();
                for (int i = 0; i < m_oTableField.GetArraySize(); ++i)
                {
                    neb::Field* pField = oDbOper->add_fields();
                    pField->set_col_name(m_oTableField(i));
                }
                oOutMsgBody.set_data(oMemOperate.SerializeAsString());
            }
            else
            {
                oOutMsgBody.set_data(m_oMemOperate.SerializeAsString());
            }
        }
        else
        {
            oOutMsgBody.set_data(m_oMemOperate.SerializeAsString());
        }

        if (m_oMemOperate.db_operate().SELECT == m_oMemOperate.db_operate().query_type())
        {
            if (!SendPolling("DBAGENT_R", CMD_REQ_STORATE, GetSequence(), oOutMsgBody))
            {
                LOG4_ERROR("SendToNext(\"DBAGENT_R\") error!");
                Response(m_pChannel, m_oReqMsgHead, ERR_DATA_TRANSFER, "SendToNext(\"DBAGENT_R\") error!");
                return (neb::CMD_STATUS_FAULT);
            }
        }
        else
        {
            if (!SendPolling("DBAGENT_W", CMD_REQ_STORATE, GetSequence(), oOutMsgBody))
            {
                LOG4_ERROR("SendToNext(\"DBAGENT_W\") error!");
                Response(m_pChannel, m_oReqMsgHead, ERR_DATA_TRANSFER, "SendToNext(\"DBAGENT_W\") error!");
                return (neb::CMD_STATUS_FAULT);
            }
        }
        return (neb::CMD_STATUS_RUNNING);
    }

    E_CMD_STATUS StepSendToDbAgent::Callback(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const MsgBody& oInMsgBody, void* data)
    {
        LOG4_TRACE("%s()", __FUNCTION__);
        MsgHead oOutMsgHead = m_oReqMsgHead;
        MsgBody oOutMsgBody;
        neb::Result oRsp;
        oRsp.set_from(neb::Result::FROM_DB);
        if (!oRsp.ParseFromString(oInMsgBody.data()))
        {
            LOG4_ERROR("DataMem::MemRsp oRsp.ParseFromString() failed!");
            if (m_bNeedResponse)
            {
                oOutMsgBody.set_data(oInMsgBody.data());
                if (!SendTo(m_pChannel, m_oReqMsgHead.cmd() + 1, m_oReqMsgHead.seq(), oOutMsgBody))
                {
                    LOG4_ERROR("send to MsgShell(fd , seq ) error!");
                    return (neb::CMD_STATUS_FAULT);
                }
            }
            return (neb::CMD_STATUS_FAULT);
        }

        WriteBackToRedis(m_pChannel, m_oReqMsgHead, oRsp);

        if (m_bNeedResponse)
        {
            if (m_bFieldFilter)
            {   // 需筛选回复字段
                neb::Result oRspToClient;
                oRspToClient.set_err_no(oRsp.err_no());
                oRspToClient.set_err_msg(oRsp.err_msg());
                std::vector<int> vecColForClient;
                std::vector<int>::iterator iter;
                for (int i = 0; i < m_oMemOperate.db_operate().fields_size(); ++i)
                {
                    for (int j = 0; j < m_oTableField.GetArraySize(); ++j)
                    {
                        if ((m_oTableField(j) == m_oMemOperate.db_operate().fields(i).col_name()) || (m_oTableField(j) == m_oMemOperate.db_operate().fields(i).col_as()))
                        {
                            vecColForClient.push_back(j);
                            break;
                        }
                    }
                }
                for (int i = 0; i < oRsp.record_data_size(); i++)
                {
                    neb::Record* pRecord = oRspToClient.add_record_data();
                    for (iter = vecColForClient.begin(); iter != vecColForClient.end(); ++iter)
                    {
                        neb::Field* pField = pRecord->add_field_info();
                        pField->set_col_value(oRsp.record_data(i).field_info(*iter).col_value());
                    }
                }
                oOutMsgBody.set_data(oRspToClient.SerializeAsString());
            }
            else
            {
                oOutMsgBody.set_data(oInMsgBody.data());
            }

            if (!SendTo(m_pChannel, m_oReqMsgHead.cmd() + 1, m_oReqMsgHead.seq(), oOutMsgBody))
            {
                LOG4_ERROR("send to MsgShell(fd , seq ) error!");
                return (neb::CMD_STATUS_FAULT);
            }
        }
        else
        { // 无需回复请求方
            if (ERR_OK != oRsp.err_no())
            {
                LOG4_ERROR("%d: %s", oRsp.err_no(), oRsp.err_msg().c_str());
            }
        }

        if (oRsp.total_count() == oRsp.current_count())
        {
            return (neb::CMD_STATUS_COMPLETED);
        }
        return (neb::CMD_STATUS_RUNNING);
    }

    E_CMD_STATUS StepSendToDbAgent::Timeout()
    {
        Response(m_pChannel, m_oReqMsgHead, ERR_TIMEOUT, "read from db or write to db timeout!");
        return (neb::CMD_STATUS_FAULT);
    }

    void StepSendToDbAgent::WriteBackToRedis(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Result& oRsp)
    {
        if (m_oMemOperate.has_redis_operate() && (neb::Mydis::RedisOperate::T_READ == m_oMemOperate.redis_operate().op_type()) && (ERR_OK == oRsp.err_no()))
        {
            pStepWriteBackToRedis = std::dynamic_pointer_cast<StepWriteBackToRedis>(MakeSharedStep("dataproxy::StepWriteBackToRedis",pChannel,
                oInMsgHead, m_oMemOperate, m_pNodeSession, m_iRelative, m_strKeyField, &m_oJoinField));
            if (NULL == pStepWriteBackToRedis)
            {
                LOG4_ERROR("malloc space for pStepWriteBackToRedis error!");
                return;
            }
            //Pretreat(pStepWriteBackToRedis);
            pStepWriteBackToRedis->Emit(oRsp);
        }
    }

} /* namespace neb */
