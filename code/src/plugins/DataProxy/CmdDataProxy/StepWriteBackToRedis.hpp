/*******************************************************************************
* Project:  DataProxyServer
* @file     StepWriteBackToRedis.hpp
* @brief
* @author   xxx
* @date:    2016年3月19日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_CMDDATAPROXY_STEPWRITEBACKTOREDIS_HPP_
#define SRC_CMDDATAPROXY_STEPWRITEBACKTOREDIS_HPP_

#include "RedisStorageStep.hpp"
#include "StepSetTtl.hpp"
#include "actor/DynamicCreator.hpp"

namespace DataProxy {

    class StepWriteBackToRedis: public RedisStorageStep, public neb::DynamicCreator<StepWriteBackToRedis, std::shared_ptr<neb::SocketChannel>, MsgHead, neb::Mydis,
        std::shared_ptr<SessionRedisNode>, int, const std::string, const neb::CJsonObject*>
    {
    public:
        StepWriteBackToRedis(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate,
            std::shared_ptr<SessionRedisNode> pNodeSession, int iRelative = RELATIVE_TABLE, const std::string& strKeyField = "", const neb::CJsonObject* pJoinField = NULL);
        virtual ~StepWriteBackToRedis();

        //         virtual neb::E_CMD_STATUS Emit(int iErrno, const std::string& strErrMsg = "", const std::string& strErrShow = "") {
        //             return (neb::CMD_STATUS_COMPLETED);
        //         }

        virtual neb::E_CMD_STATUS Emit(int iErrno = 0, const std::string& strErrMsg = "",  void* data = NULL) {
            return (neb::CMD_STATUS_COMPLETED);
        }

        virtual neb::E_CMD_STATUS Emit(const neb::Result& oRsp);

        virtual neb::E_CMD_STATUS Callback(const redisAsyncContext* c, int status, redisReply* pReply);

    protected:
        bool MakeCmdWithJoin(const neb::Result& oRsp);
        bool MakeCmdWithDataSet(const neb::Result& oRsp);
        bool MakeCmdWithoutDataSet(const neb::Result& oRsp);
        bool MakeCmdForHashWithDataSet(const neb::Result& oRsp);
        bool MakeCmdForHashWithoutDataSet(const neb::Result& oRsp);
        bool MakeCmdForHashWithoutDataSetWithField(const neb::Result& oRsp);
        bool MakeCmdForHashWithoutDataSetWithoutField(const neb::Result& oRsp);

    private:
        std::shared_ptr<neb::SocketChannel> m_pChannel;
        MsgHead m_oReqMsgHead;
        neb::Mydis m_oMemOperate;
        int m_iRelative;
        std::string m_strKeyField;
        neb::CJsonObject m_oJoinField;
        std::string m_strMasterNode;
        std::string m_strSlaveNode;

    public:
        std::shared_ptr<SessionRedisNode> m_pNodeSession;
        std::shared_ptr<StepSetTtl> pStepSetTtl;
    };

} /* namespace neb */

#endif /* SRC_CMDDATAPROXY_STEPWRITEBACKTOREDIS_HPP_ */
