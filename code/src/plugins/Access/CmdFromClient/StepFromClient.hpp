/*******************************************************************************
* Project:  AccessServer
* @file     StepFromClient.hpp
* @brief 
* @author   lbh
* @date:    2015年10月21日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_STEP_FROM_CLIENT_HPP_
#define SRC_STEP_FROM_CLIENT_HPP_

#include <actor/step/PbStep.hpp>
#include "util/json/CJsonObject.hpp"

namespace plugins
{

    class StepFromClient: public neb::PbStep, public neb::DynamicCreator<StepFromClient, std::shared_ptr<neb::SocketChannel>, MsgHead, MsgBody>
    {
    public:
        StepFromClient(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody);
        virtual ~StepFromClient();

        virtual neb::E_CMD_STATUS Emit(int iErrno = 0, const std::string& strErrMsg = "",  void* data = NULL);
        virtual neb::E_CMD_STATUS Callback(        std::shared_ptr<neb::SocketChannel> pUpstreamChannel,        const MsgHead& oInMsgHead,        const MsgBody& oInMsgBody,        void* data = NULL);
        virtual neb::E_CMD_STATUS Timeout();

    private:
        std::string m_strTargetNodeIdentity;
        int32 m_iCmd;
        MsgBody m_oMsgBody;
    };

} /* namespace mg */

#endif /* SRC_CMDFROMCLIENT_STEPFROMCLIENT_HPP_ */
