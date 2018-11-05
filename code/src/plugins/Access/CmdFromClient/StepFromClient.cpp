/*******************************************************************************
* Project:  AccessServer
* @file     StepFromClient.cpp
* @brief 
* @author   lbh
* @date:    2015年10月21日
* @note
* Modify history:
******************************************************************************/
#include "StepFromClient.hpp"

namespace plugins
{

    StepFromClient::StepFromClient(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody)
    : PbStep(pUpstreamChannel, oMsgHead, oMsgBody)
    {
    }

    StepFromClient::~StepFromClient()
    {
    }

    neb::E_CMD_STATUS StepFromClient::Emit(int iErrno, const std::string& strErrMsg, void* data)
    {
        LOG4_TRACE("%s", __FUNCTION__);

        if (m_oReqMsgBody.has_req_target())
        {
            if (m_oReqMsgBody.req_target().route_id() > 0)
            {
                SendOriented("LOGIC", m_oReqMsgBody.req_target().route_id(), m_oReqMsgHead.cmd(), GetSequence(), m_oReqMsgBody);
            }
            else if (m_oReqMsgBody.req_target().route().size() > 0)
            {
                SendOriented("LOGIC", m_oReqMsgBody.req_target().route().size(), m_oReqMsgHead.cmd(), GetSequence(), m_oReqMsgBody);
            }
            else
            {
                SendPolling("LOGIC", m_oReqMsgHead.cmd(), GetSequence(), m_oReqMsgBody);
            }
        }
        else
        {
            SendPolling("LOGIC", m_oReqMsgHead.cmd(), GetSequence(), m_oReqMsgBody);
        }
        return (neb::CMD_STATUS_RUNNING);
    }

    neb::E_CMD_STATUS StepFromClient::Callback(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oInMsgHead, const MsgBody& oInMsgBody, void* data)
    {
        SendTo(m_pUpstreamChannel, oInMsgHead.cmd(), m_oReqMsgHead.seq(), oInMsgBody);
        return(neb::CMD_STATUS_COMPLETED);
    }

    neb::E_CMD_STATUS StepFromClient::Timeout()
    {
        LOG4_WARNING("cmd %u, seq %lu, logic timeout!", m_oReqMsgHead.cmd(), m_oReqMsgHead.seq());
        return(neb::CMD_STATUS_FAULT);
    }

} /* namespace mg */
