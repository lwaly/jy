/*******************************************************************************
* Project:  Beacon
* @file     CmdToClient.cpp
* @brief 
* @author   bwar
* @date:    Feb 14, 2017
* @note
* Modify history:
******************************************************************************/
#include "CmdToClient.hpp"

namespace plugins
{

    CmdToClient::CmdToClient(int32 iCmd)
        : neb::Cmd(iCmd), m_pStep(nullptr)
    {
    }

    CmdToClient::~CmdToClient()
    {
    }

    bool CmdToClient::Init()
    {
        return(true);
    }

    bool CmdToClient::AnyMessage(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody)
    {
        LOG4_TRACE("%s()", __FUNCTION__);
        m_pStep = std::dynamic_pointer_cast<StepToClient>(MakeSharedStep("plugins::StepToClient", pUpstreamChannel, oMsgHead, oMsgBody));
        if ((m_pStep))
        {
            if (neb::CMD_STATUS_RUNNING == m_pStep->Emit(neb::ERR_OK))
            {
                LOG4_TRACE("StepToClient running");
                return(true);
            }
        }
        return(false);
    }

} /* namespace beacon */
