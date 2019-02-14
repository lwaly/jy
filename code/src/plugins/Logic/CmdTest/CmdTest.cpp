/*******************************************************************************
* Project:  Logic
* @file     CmdTest.cpp
* @brief 
* @author   bwar
* @date:    Feb 21, 2017
* @note
* Modify history:
******************************************************************************/
#include "CmdTest.hpp"

namespace logic
{

    CmdTest::CmdTest(int32 iCmd)
        : neb::Cmd(iCmd), m_pStep(nullptr)
    {
    }

    CmdTest::~CmdTest()
    {
    }

    bool CmdTest::Init()
    {
        return(true);
    }

    bool CmdTest::AnyMessage(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody)
    {
        LOG4_TRACE("%s()", __FUNCTION__);
        m_pStep = std::dynamic_pointer_cast<StepTest>(MakeSharedStep("logic::StepTest", pChannel, oMsgHead, oMsgBody));
        
        if ((m_pStep))
        {
            if (neb::CMD_STATUS_RUNNING == m_pStep->Emit(neb::ERR_OK, "", NULL))
            {
                LOG4_TRACE("StepTest running");
                return(true);
            }
        }
        return(false);
    }

} /* namespace logic */
