/*******************************************************************************
* Project:  DataProxyServer
* @file     DbStorageStep.hpp
* @brief
* @author   xxx
* @date:    2016年3月21日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_CMDDATAPROXY_DBSTORAGESTEP_HPP_
#define SRC_CMDDATAPROXY_DBSTORAGESTEP_HPP_

#include "actor/step/Step.hpp"
#include "actor/step/PbStep.hpp"
#include "pb/mydis.pb.h"
#include "SessionRedisNode.hpp"

namespace neb {

    class DbStorageStep: public neb::PbStep
    {
    public:
        DbStorageStep(std::shared_ptr<Step> pNextStep = nullptr);
        DbStorageStep(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oReqMsgHead, const MsgBody& oReqMsgBody, std::shared_ptr<Step> pNextStep = nullptr);
        virtual ~DbStorageStep();

    protected:
        bool Response(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, int iErrno, const std::string& strErrMsg);
        bool Response(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Result& oRsp);
    };

} /* namespace neb */

#endif /* SRC_CMDDATAPROXY_DBSTORAGESTEP_HPP_ */
