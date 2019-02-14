/*******************************************************************************
* Project:  DataProxyServer
* @file     DbStorageStep.cpp
* @brief
* @author   xxx
* @date:    2016年3月21日
* @note
* Modify history:
******************************************************************************/
#include "DbStorageStep.hpp"

namespace DataProxy {

    DbStorageStep::DbStorageStep(std::shared_ptr<Step> pNextStep)
        : PbStep(pNextStep,neb::gc_dDefaultTimeout)
    {
    }

    DbStorageStep::DbStorageStep(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody, std::shared_ptr<Step> pNextStep)
        :  PbStep(pChannel, oMsgHead, oMsgBody, pNextStep)
    {
    }

    DbStorageStep::~DbStorageStep()
    {
    }

    bool DbStorageStep::Response(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, int iErrno, const std::string& strErrMsg)
    {
        LOG4_TRACE("error %d: %s", iErrno, strErrMsg.c_str());
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

    bool DbStorageStep::Response(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Result& oRsp)
    {
        LOG4_TRACE("%d: %s", oRsp.err_no(), oRsp.err_msg().c_str());

        MsgBody oOutMsgBody;
        oOutMsgBody.set_data(oRsp.SerializeAsString());

        if (!SendTo(pChannel, oInMsgHead.cmd() + 1, oInMsgHead.seq(), oOutMsgBody)) {
            LOG4_ERROR("send to MsgShell(fd , seq %u) error!", oInMsgHead.seq());
            return (false);
        }
        return (true);
    }


} /* namespace neb */
