/*******************************************************************************
* Project:  AccessServer
* @file     StepToClient.cpp
* @brief 
* @author   wfh
* @date:    2016年11月06日
* @note
* Modify history:
******************************************************************************/
#include "StepToClient.hpp"

namespace mg
{

    StepToClient::StepToClient(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody)
        : PbStep(pUpstreamChannel, oMsgHead, oMsgBody)
    {
    }

    StepToClient::~StepToClient()
    {
    }

    neb::E_CMD_STATUS StepToClient::Emit(int iErrno, const std::string& strErrMsg, void* data)
    {
        bool bSendResult = false;
        MsgHead oOutMsgHead = m_oReqMsgHead;
        oOutMsgHead.set_seq(GetSequence());     // 更换消息头的seq后直接转发

        if (m_oReqMsgBody.has_req_target())
        {
            if (m_oReqMsgBody.req_target().route_id() > 0)
            {
                char szIdentify[32] = {0};
                snprintf(szIdentify, sizeof(szIdentify), "%u", m_oReqMsgBody.req_target().route_id());
                bSendResult = SendTo(szIdentify, m_oReqMsgHead.cmd(), GetSequence(), m_oReqMsgBody);
            }
            else if (m_oReqMsgBody.req_target().route().size() > 0)
            {
                bSendResult = SendTo(m_oReqMsgBody.req_target().route(), m_oReqMsgHead.cmd(), GetSequence(), m_oReqMsgBody);
            }
            else
            {
                MsgBody oOutMsgBody;
                oOutMsgBody.set_body("");
                SendTo(m_pUpstreamChannel, neb::CMD_RSP_SYS_ERROR, m_oReqMsgHead.seq(), oOutMsgBody);
                return oss::CMD_STATUS_COMPLETED;
            }
        }

        if (bSendResult)
        {
            return oss::CMD_STATUS_RUNNING;
        }
        else
        {
            MsgBody oOutMsgBody;
            oOutMsgBody.set_body("");
            SendTo(m_pUpstreamChannel, neb::CMD_RSP_SYS_ERROR, m_oReqMsgHead.seq(), oOutMsgBody);
            return oss::CMD_STATUS_COMPLETED;
        }
    }

    neb::E_CMD_STATUS StepToClient::Callback(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oInMsgHead, const MsgBody& oInMsgBody, void* data)
    {
        SendTo(m_pUpstreamChannel, oInMsgHead.cmd(), m_oReqMsgHead.seq(), oInMsgBody);
        return(neb::CMD_STATUS_COMPLETED);
    }

    neb::E_CMD_STATUS StepToClient::Timeout()
    {
        LOG4_WARNING("cmd %u, seq %lu, logic timeout!", m_oReqMsgHead.cmd(), m_oReqMsgHead.seq());
        return oss::CMD_STATUS_FAULT;
    }

} /* namespace mg */
