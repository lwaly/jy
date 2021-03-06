/*******************************************************************************
* Project:  DataProxyServer
* @file     StepReadFromDb.hpp
* @brief
* @author   xxx
* @date:    2016年3月19日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_CMDDATAPROXY_STEPSENDTODBAGENT_HPP_
#define SRC_CMDDATAPROXY_STEPSENDTODBAGENT_HPP_

#include "DbStorageStep.hpp"
#include "StepWriteBackToRedis.hpp"

namespace DataProxy {

    class StepSendToDbAgent: public DbStorageStep, public neb::DynamicCreator<StepSendToDbAgent, std::shared_ptr<neb::SocketChannel>, MsgHead, neb::Mydis
        , std::shared_ptr<SessionRedisNode>, int, const neb::CJsonObject*, std::string, const neb::CJsonObject*>
    {
    public:
        /**
        * @brief 向DbAgent发出数据库操作请求
        * @param stMsgShell 客户端连接通道
        * @param oInMsgHead 客户端请求消息头
        * @param oMemOperate 存储操作请求数据
        * @param pNodeSession redis节点session
        * @param iRelative  redis数据结构与表之间的关系
        * @param pTableField 数据库表字段（json数组）
        * @param strKeyField redis数据结构键字段
        * @param pJoinField  redis数据结构串联字段
        */
        StepSendToDbAgent(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate, std::shared_ptr<SessionRedisNode> pNodeSession = NULL,
            int iRelative = RELATIVE_TABLE, const neb::CJsonObject* pTableField = NULL, const std::string& strKeyField = "", const neb::CJsonObject* pJoinField = NULL);
        virtual ~StepSendToDbAgent();

        //virtual neb::E_CMD_STATUS Emit(int iErrno, const std::string& strErrMsg = "", const std::string& strErrShow = "");
        virtual neb::E_CMD_STATUS Emit(int iErrno = 0, const std::string& strErrMsg = "",  void* data = NULL);
        virtual neb::E_CMD_STATUS Callback(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const MsgBody& oInMsgBody, void* data = NULL);

        virtual neb::E_CMD_STATUS Timeout();

    protected:
        void WriteBackToRedis(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Result& oRsp);

    private:
        std::shared_ptr<neb::SocketChannel> m_pChannel;
        MsgHead m_oReqMsgHead;
        neb::Mydis m_oMemOperate;
        int m_iRelative;
        std::string m_strKeyField;
        neb::CJsonObject m_oTableField;
        neb::CJsonObject m_oJoinField;
        bool m_bFieldFilter;        ///< 是否需要筛选字段返回给请求方
        bool m_bNeedResponse;       ///< 是否需要响应请求方（如果是同时写redis和mysql，写redis已经给了响应，写mysql不再回响应）

    public:
        std::shared_ptr<SessionRedisNode> m_pNodeSession;
        std::shared_ptr<StepWriteBackToRedis> pStepWriteBackToRedis;
    };

} /* namespace neb */

#endif /* SRC_CMDDATAPROXY_STEPSENDTODBAGENT_HPP_ */
