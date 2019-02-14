/*******************************************************************************
* Project:  DataProxyServer
* @file     StepReadFromRedis.hpp
* @brief
* @author   xxx
* @date:    2016年3月19日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_CMDDATAPROXY_STEPREADFROMREDIS_HPP_
#define SRC_CMDDATAPROXY_STEPREADFROMREDIS_HPP_

#include "RedisStorageStep.hpp"

namespace DataProxy {

    class StepReadFromRedis: public RedisStorageStep, public neb::DynamicCreator<StepReadFromRedis, std::shared_ptr<neb::SocketChannel>, MsgHead,
        neb::Mydis::RedisOperate, std::shared_ptr<SessionRedisNode>, bool, const neb::CJsonObject*, std::string, std::shared_ptr<neb::Step>>
    {
    public:
        StepReadFromRedis(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis::RedisOperate& oRedisOperate,
            std::shared_ptr<SessionRedisNode> pNodeSession, bool bIsDataSet = false, const neb::CJsonObject* pTableFields = NULL,
            const std::string& strKeyField = "", std::shared_ptr<neb::Step> pNextStep = nullptr);
        virtual ~StepReadFromRedis();

        //virtual neb::E_CMD_STATUS Emit(int iErrno, const std::string& strErrMsg = "", const std::string& strErrShow = "");
        virtual neb::E_CMD_STATUS Emit(int iErrno = 0, const std::string& strErrMsg = "",  void* data = NULL);
        virtual neb::E_CMD_STATUS Callback(const redisAsyncContext* c, int status, redisReply* pReply);

    protected:
        bool ReadReplyArray(redisReply* pReply);
        bool ReadReplyArrayWithDataSet(redisReply* pReply);
        bool ReadReplyArrayWithoutDataSet(redisReply* pReply);

        bool ReadReplyHash(redisReply* pReply);
        bool ReadReplyArrayForHashWithDataSet(redisReply* pReply);
        bool ReadReplyArrayForHashWithoutDataSet(redisReply* pReply);
        bool ReadReplyArrayForHgetallWithDataSet(redisReply* pReply);
        bool ReadReplyArrayForHgetallWithoutDataSet(redisReply* pReply);

    private:
        std::shared_ptr<neb::SocketChannel> m_pChannel;
        MsgHead m_oReqMsgHead;
        neb::Mydis::RedisOperate m_oRedisOperate;
        bool m_bIsDataSet;
        neb::CJsonObject m_oTableFields;
        std::string m_strKeyField;
        std::string m_strMasterNode;
        std::string m_strSlaveNode;
        int m_iReadNum;
        int m_iTableFieldNum;

    public:
        std::shared_ptr<SessionRedisNode> m_pNodeSession;
        std::shared_ptr<neb::Step> m_pNextStep;
    };

} /* namespace neb */

#endif /* SRC_CMDDATAPROXY_STEPREADFROMREDIS_HPP_ */
