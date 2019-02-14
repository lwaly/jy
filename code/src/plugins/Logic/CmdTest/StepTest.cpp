/*******************************************************************************
* Project:  AccessServer
* @file     StepTest.cpp
* @brief 
* @author   lbh
* @date:    2015Äê10ÔÂ21ÈÕ
* @note
* Modify history:
******************************************************************************/
#include "StepTest.hpp"
#include "mydis/RedisOperator.hpp"

namespace logic
{

    StepTest::StepTest(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody)
        : PbStep(pUpstreamChannel, oMsgHead, oMsgBody)
    {
    }

    StepTest::~StepTest()
    {
    }

    neb::E_CMD_STATUS StepTest::Emit(int iErrno, const std::string& strErrMsg, void* data)
    {
        LOG4_TRACE("%s", __FUNCTION__);
        std::string strDProxyBuffer;
        char szRedisKey[64] = { 0 };
        snprintf(szRedisKey, sizeof(szRedisKey), "%u:%u", 1, 1001);

        neb::RedisOperator oMemOper(1000, szRedisKey, "hset");
        oMemOper.AddRedisField("test", "test");

        MsgHead oMsgHead;
        MsgBody oMsgBody;
        oMsgBody.set_data(oMemOper.MakeMemOperate()->SerializeAsString());
//         oMsgHead.set_cmd(neb::CMD_REQ_STORATE);
//         oMsgHead.set_len(oMsgBody.ByteSize());
//         oMsgHead.set_seq(m_uiSequenece);

        SendPolling("DATAPROXY", neb::CMD_REQ_STORATE, GetSequence(), oMsgBody);
        return (neb::CMD_STATUS_RUNNING);
    }

    neb::E_CMD_STATUS StepTest::Callback(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oInMsgHead, const MsgBody& oInMsgBody, void* data)
    {
        MsgBody lInMsgBody;
        neb::Result oRsp;

        if ((oInMsgBody.data().size() > 0) && oRsp.ParseFromString(oInMsgBody.data()))
        {
            LOG4_TRACE("%s %s %d", __FUNCTION__, oRsp.err_msg(),oRsp.err_no());
            MsgBody_Response* pErrInfo = new MsgBody_Response();
            pErrInfo->set_code(oRsp.err_no());
            pErrInfo->set_msg(oRsp.err_msg());
            lInMsgBody.set_allocated_rsp_result(pErrInfo);
        }
        else
        {
            LOG4_TRACE("%s", __FUNCTION__);
            MsgBody_Response* pErrInfo = new MsgBody_Response();
            pErrInfo->set_code(neb::ERR_REDIS_CMD);
            pErrInfo->set_msg("fail to execution redis command  error");
            lInMsgBody.set_allocated_rsp_result(pErrInfo);
        }

        SendTo(m_pUpstreamChannel, oInMsgHead.cmd(), m_oReqMsgHead.seq(), oInMsgBody);
        return(neb::CMD_STATUS_COMPLETED);
    }

    neb::E_CMD_STATUS StepTest::Timeout()
    {
        LOG4_WARNING("cmd %u, seq %lu, logic timeout!", m_oReqMsgHead.cmd(), m_oReqMsgHead.seq());
        return(neb::CMD_STATUS_FAULT);
    }

} /* namespace mg */
