/*******************************************************************************
* Project:  Beacon
* @file     CmdFromClient.cpp
* @brief 
* @author   bwar
* @date:    Feb 14, 2017
* @note
* Modify history:
******************************************************************************/
#include "CmdFromClient.hpp"

namespace plugins
{

    CmdFromClient::CmdFromClient(int32 iCmd)
        : neb::Cmd(iCmd), m_pStep(nullptr)
    {
    }

    CmdFromClient::~CmdFromClient()
    {
    }

    bool CmdFromClient::Init()
    {
        return(true);
    }

    bool CmdFromClient::AnyMessage(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody)
    {
        LOG4_TRACE("%s()", __FUNCTION__);
        m_pStep = std::dynamic_pointer_cast<StepFromClient>(MakeSharedStep("plugins::StepFromClient", pUpstreamChannel, oMsgHead, oMsgBody));
        if ((m_pStep))
        {
            if (neb::CMD_STATUS_RUNNING == m_pStep->Emit(neb::ERR_OK))
            {
                LOG4_TRACE("StepFromClient running");
                return(true);
            }
        }
        return(false);
    }

} /* namespace beacon */
