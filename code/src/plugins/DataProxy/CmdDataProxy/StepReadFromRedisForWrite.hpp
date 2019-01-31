/*******************************************************************************
* Project:  DataProxyServer
* @file     StepReadFromRedisForWrite.hpp
* @brief    读取redis中的数据，为下一步写入之用（适用于update dataset情形）
* @author   xxx
* @date:    2016年4月6日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_CMDDATAPROXY_STEPREADFROMREDISFORWRITE_HPP_
#define SRC_CMDDATAPROXY_STEPREADFROMREDISFORWRITE_HPP_

#include "util/json/CJsonObject.hpp"
#include "RedisStorageStep.hpp"
#include "StepSendToDbAgent.hpp"
#include "StepWriteToRedis.hpp"

namespace neb {

    class StepReadFromRedisForWrite: public RedisStorageStep {
    public:
        StepReadFromRedisForWrite(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate,
            SessionRedisNode* pNodeSession, const neb::CJsonObject& oTableFields, const std::string& strKeyField = "");
        virtual ~StepReadFromRedisForWrite();

        virtual E_CMD_STATUS Emit(int iErrno, const std::string& strErrMsg = "", const std::string& strErrShow = "");
        virtual E_CMD_STATUS Callback(const redisAsyncContext* c, int status, redisReply* pReply);
    protected:
        E_CMD_STATUS ExecUpdate(bool bDbOnly = false);

    private:
        std::shared_ptr<neb::SocketChannel> m_pChannel;
        MsgHead m_oReqMsgHead;
        neb::Mydis m_oMemOperate;
        neb::CJsonObject m_oTableFields;
        std::string m_strKeyField;
        std::string m_strMasterNode;
        std::string m_strSlaveNode;

    public:
        SessionRedisNode* m_pRedisNodeSession;
        StepSendToDbAgent* pStepSendToDbAgent;
        StepWriteToRedis* pStepWriteToRedis;
    };

} /* namespace neb */

#endif /* SRC_CMDDATAPROXY_STEPREADFROMREDISFORWRITE_HPP_ */
