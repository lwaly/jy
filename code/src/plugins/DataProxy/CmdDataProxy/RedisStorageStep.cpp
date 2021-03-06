/*******************************************************************************
* Project:  DataProxyServer
* @file     StorageStep.cpp
* @brief
* @author   xxx
* @date:    2016年3月21日
* @note
* Modify history:
******************************************************************************/
#include "RedisStorageStep.hpp"

namespace DataProxy {

    RedisStorageStep::RedisStorageStep(std::shared_ptr<Step> pNextStep)
        : RedisStep(pNextStep)
    {
    }

    //  RedisStorageStep::RedisStorageStep(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oReqMsgHead, const MsgBody& oReqMsgBody, std::shared_ptr<Step>* pNextStep)
    //      : RedisStep(stReqMsgShell, oReqMsgHead, oReqMsgBody, pNextStep) {
    //  }

    RedisStorageStep::~RedisStorageStep() {
    }

    bool RedisStorageStep::Response(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, int iErrno, const std::string& strErrMsg) {
        LOG4_TRACE("%d: %s", iErrno, strErrMsg.c_str());
        MsgBody oOutMsgBody;
        neb::Result oRsp;
        oRsp.set_err_no(iErrno);
        oRsp.set_err_msg(strErrMsg);
        oOutMsgBody.set_data(oRsp.SerializeAsString());
        if (!SendTo(pChannel, oInMsgHead.cmd() + 1, oInMsgHead.seq(),oOutMsgBody))
        {
            LOG4_ERROR("send to MsgShell(fd , seq %u) error!", oInMsgHead.seq());
            return (false);
        }
        return (true);
    }

    bool RedisStorageStep::Response(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Result& oRsp)
    {
        LOG4_TRACE("%d: %s", oRsp.err_no(), oRsp.err_msg().c_str());
        MsgBody oOutMsgBody;
        oOutMsgBody.set_data(oRsp.SerializeAsString());
        if (!SendTo(pChannel, oInMsgHead.cmd() + 1, oInMsgHead.seq(), oOutMsgBody))
        {
            LOG4_ERROR("send to MsgShell(fd , seq %u) error!", oInMsgHead.seq());
            return (false);
        }
        return (true);
    }

} /* namespace neb */
