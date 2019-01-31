/*******************************************************************************
* Project:  DataProxyServer
* @file     StepWriteToRedis.hpp
* @brief
* @author   xxx
* @date:    2016年3月19日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_CMDDATAPROXY_STEPWRITETOREDIS_HPP_
#define SRC_CMDDATAPROXY_STEPWRITETOREDIS_HPP_

#include "RedisStorageStep.hpp"
#include "StepSetTtl.hpp"

namespace neb {

    class StepWriteToRedis: public RedisStorageStep {
    public:
        StepWriteToRedis(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis::RedisOperate& oRedisOperate,
            std::shared_ptr<SessionRedisNode> pNodeSession = nullptr, std::shared_ptr<Step> pNextStep = nullptr);
        virtual ~StepWriteToRedis();

        virtual E_CMD_STATUS Emit(int iErrno, const std::string& strErrMsg = "", const std::string& strErrShow = "");

        virtual E_CMD_STATUS Callback( const redisAsyncContext* c, int status, redisReply* pReply);

    protected:
        bool ReadReplyArrayForHashWithoutDataSet(redisReply* pReply);
        bool ReadReplyArrayWithoutDataSet(redisReply* pReply);

    private:
        std::shared_ptr<neb::SocketChannel> m_pChannel;
        MsgHead m_oReqMsgHead;
        neb::Mydis::RedisOperate m_oRedisOperate;
        std::string m_strMasterNode;
        std::string m_strSlaveNode;

    public:
        std::shared_ptr<SessionRedisNode> m_pNodeSession;
        std::shared_ptr<StepSetTtl> pStepSetTtl;
    };

} /* namespace neb */

#endif /* SRC_CMDDATAPROXY_STEPWRITETOREDIS_HPP_ */
