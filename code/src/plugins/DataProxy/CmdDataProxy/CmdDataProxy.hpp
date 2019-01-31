/*******************************************************************************
* Project:  DataProxyServer
* @file     CmdDataProxy.hpp
* @brief    数据访问代理
* @author   xxx
* @date:    2016年3月18日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_CMDDATAPROXY_CMDDATAPROXY_HPP_
#define SRC_CMDDATAPROXY_CMDDATAPROXY_HPP_

#include <map>
#include <set>

#include "actor/cmd/Cmd.hpp"
#include "mydis/Operator.hpp"
#include "pb/mydis.pb.h"
#include "SessionRedisNode.hpp"
#include "StepReadFromRedis.hpp"
#include "StepSendToDbAgent.hpp"
#include "StepWriteToRedis.hpp"
#include "StepReadFromRedisForWrite.hpp"

#ifdef __cplusplus
extern "C" {
#endif
    neb::Cmd* create();
#ifdef __cplusplus
}
#endif

namespace neb {

    const int gc_iErrBuffSize = 256;

    class CmdDataProxy:  public neb::Cmd, public neb::DynamicCreator<CmdDataProxy, int32>
    {
    public:
        CmdDataProxy(int32 iCmd);
        virtual ~CmdDataProxy();

        virtual bool Init();

        virtual bool AnyMessage(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const MsgBody& oInMsgBody);

    protected:
        bool ReadDataProxyConf();
        bool ReadTableRelation();
         bool Preprocess(neb::Mydis& oMemOperate);
         bool CheckRequest(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate);
         bool CheckRedisOperate(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis::RedisOperate& oRedisOperate);
         bool CheckDbOperate(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis::DbOperate& oDbOperate);
 
         bool CheckDataSet(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate, const std::string& strRedisDataPurpose);
         bool CheckJoinField(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate, const std::string& strRedisDataPurpose);
         bool PrepareForWriteBothWithDataset(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, neb::Mydis& oMemOperate, const std::string& strRedisDataPurpose);
         bool PrepareForWriteBothWithFieldJoin(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, neb::Mydis& oMemOperate, const std::string& strRedisDataPurpose);

         bool RedisOnly(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate);
         bool DbOnly(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate);
         bool ReadEither(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, const neb::Mydis& oMemOperate);
         bool WriteBoth(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, neb::Mydis& oMemOperate);
         bool UpdateBothWithDataset(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, neb::Mydis& oMemOperate);

         void Response(std::shared_ptr<neb::SocketChannel> pChannel, const MsgHead& oInMsgHead, int iErrno, const std::string& strErrMsg);

    private:
        bool GetNodeSession(int32 iDataType, int32 iSectionFactorType, uint32 uiFactor);

    private:
        char* m_pErrBuff;
        std::shared_ptr<SessionRedisNode> m_pRedisNodeSession;
        neb::CJsonObject m_oJsonTableRelative;
        std::map<std::string, std::set<uint32> > m_mapFactorSection; //分段因子区间配置，key为因子类型
        std::map<std::string, std::set<std::string> > m_mapTableFields; //表的组成字段，key为表名，value为字段名集合，用于查找请求的字段名是否存在

    public:
        std::shared_ptr<StepSendToDbAgent> pStepSendToDbAgent;
        std::shared_ptr<StepReadFromRedis> pStepReadFromRedis;
        std::shared_ptr<StepWriteToRedis> pStepWriteToRedis;
        std::shared_ptr<StepReadFromRedisForWrite> pStepReadFromRedisForWrite;
    };

} /* namespace neb */

#endif /* SRC_CMDDATAPROXY_CMDDATAPROXY_HPP_ */
