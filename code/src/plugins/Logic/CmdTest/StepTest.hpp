/*******************************************************************************
* Project:  AccessServer
* @file     StepTest.hpp
* @brief 
* @author   lbh
* @date:    2015Äê10ÔÂ21ÈÕ
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_STEP_TEST_HPP_
#define SRC_STEP_TEST_HPP_

#include <actor/step/PbStep.hpp>
#include "util/json/CJsonObject.hpp"

namespace logic
{

    class StepTest: public neb::PbStep, public neb::DynamicCreator<StepTest, std::shared_ptr<neb::SocketChannel>, MsgHead, MsgBody>
    {
    public:
        StepTest(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody);
        virtual ~StepTest();

        virtual neb::E_CMD_STATUS Emit(int iErrno = 0, const std::string& strErrMsg = "",  void* data = NULL);
        virtual neb::E_CMD_STATUS Callback(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oInMsgHead, const MsgBody& oInMsgBody, void* data = NULL);
        virtual neb::E_CMD_STATUS Timeout();

    private:
        std::string m_strTargetNodeIdentity;
        int32 m_iCmd;
        MsgBody m_oMsgBody;
    };

} /* namespace logic */

#endif /* SRC_STEP_TEST_HPP_ */
