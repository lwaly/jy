/*******************************************************************************
 * Project:  Nebula
 * @file     Actor.hpp
 * @brief    Nebula构成实体
 * @author   Bwar
 * @date:    2016年8月9日
 * @note     Nebula构成实体
 * Modify history:
 ******************************************************************************/
#ifndef SRC_ACTOR_ACTOR_HPP_
#define SRC_ACTOR_ACTOR_HPP_

#include <memory>
#include <string>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#include "ev.h"
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#include "Error.hpp"
#include "Definition.hpp"
#include "pb/msg.pb.h"
#include "pb/http.pb.h"
#include "util/json/CJsonObject.hpp"
#include "channel/Channel.hpp"

namespace neb
{

class Worker;
class WorkerImpl;
class WorkerFriend;

class SocketChannel;
class RedisChannel;
class ActorCreator;
class Cmd;
class Module;
class Session;
class Timer;
class Context;
class Step;

class Actor: public std::enable_shared_from_this<Actor>
{
public:
    enum ACTOR_TYPE
    {
        ACT_UNDEFINE            = 0,        ///< 未定义
        ACT_CMD                 = 1,        ///< Cmd对象，处理带命令字的pb请求
        ACT_MODULE              = 2,        ///< Module对象，处理带url path的http请求
        ACT_SESSION             = 3,        ///< Session会话对象
        ACT_TIMER               = 4,        ///< 定时器对象
        ACT_PB_STEP             = 5,        ///< Step步骤对象，处理pb请求或响应
        ACT_HTTP_STEP           = 6,        ///< Step步骤对象，处理http请求或响应
        ACT_REDIS_STEP          = 7,        ///< Step步骤对象，处理redis请求或响应
    };

public:
    Actor(ACTOR_TYPE eActorType = ACT_UNDEFINE, ev_tstamp dTimeout = 0.0);
    Actor(const Actor&) = delete;
    Actor& operator=(const Actor&) = delete;
    virtual ~Actor();

protected:
    uint32 GetSequence();
    uint32 GetNodeId() const;
    uint32 GetWorkerIndex() const;
    ev_tstamp GetDefaultTimeout() const;
    const std::string& GetNodeType() const;
    const std::string& GetWorkPath() const;
    const std::string& GetNodeIdentify() const;
    time_t GetNowTime() const;

    /**
     * @brief 获取Server自定义配置
     * @return Server自定义配置
     */
    const CJsonObject& GetCustomConf() const;

    std::shared_ptr<Session> GetSession(uint32 uiSessionId);
    std::shared_ptr<Session> GetSession(const std::string& strSessionId);
    bool ExecStep(uint32 uiStepSeq, int iErrno = ERR_OK, const std::string& strErrMsg = "", void* data = NULL);
    std::shared_ptr<Context> GetContext();
    void SetContext(std::shared_ptr<Context> pContext);

protected:
    /**
     * @brief 连接成功后发送
     * @note 当前Server往另一个Server发送数据而两Server之间没有可用连接时，框架层向对端发起连接（发起连接
     * 的过程是异步非阻塞的，connect()函数返回的时候并不知道连接是否成功），并将待发送数据存放于应用层待发
     * 送缓冲区。当连接成功时将待发送数据从应用层待发送缓冲区拷贝到应用层发送缓冲区并发送。此函数由框架层自
     * 动调用，业务逻辑层无须关注。
     * @param stCtx 消息通道上下文
     * @return 是否发送成功
     */
    bool SendTo(std::shared_ptr<SocketChannel> pChannel);

    /**
     * @brief 发送数据
     * @note 使用指定连接将数据发送。如果能直接得知stCtx（比如刚从该连接接收到数据，欲回确认包），就
     * 应调用此函数发送。此函数是SendTo()函数中最高效的一个。
     * @param stCtx 消息通道上下文
     * @param iCmd 发送的命令字
     * @param uiSeq 发送的数据包seq
     * @param oMsgBody 数据包体
     * @return 是否发送成功
     */
    bool SendTo(std::shared_ptr<SocketChannel> pChannel, int32 iCmd, uint32 uiSeq, const MsgBody& oMsgBody);

    /**
     * @brief 发送数据
     * @param stCtx 消息通道上下文
     * @param oHttpMsg http消息
     * @return 是否发送成功
     */
    bool SendTo(std::shared_ptr<SocketChannel> pChannel, const HttpMsg& oHttpMsg);

    /**
     * @brief 发送数据
     * @note 指定连接标识符将数据发送。此函数先查找与strIdentify匹配的stMsgShell，如果找到就调用
     * SendTo(const tagMsgShell& stMsgShell, int32 iCmd, uint32 uiSeq, const MsgBody& oMsgBody)
     * 发送，如果未找到则调用SendToWithAutoConnect(const std::string& strIdentify,
     * uint32 iCmd, uint32 uiSeq, const MsgBody& oMsgBody)连接后再发送。
     * @param strIdentify 连接标识符(IP:port.worker_index, e.g 192.168.11.12:3001.1)
     * @param iCmd 发送的命令字
     * @param uiSeq 发送的数据包seq
     * @param oMsgBody 数据包体
     * @return 是否发送成功
     */
    bool SendTo(const std::string& strIdentify, int32 iCmd, uint32 uiSeq, const MsgBody& oMsgBody);

    /**
     * @brief 发送数据
     * @param strHost IP地址
     * @param iPort 端口
     * @param strUrlPath 路径
     * @param oHttpMsg http消息
     * @return 是否发送成功
     */
    bool SendTo(const std::string& strHost, int iPort, const std::string& strUrlPath, const HttpMsg& oHttpMsg);

    /**
     * @brief 发送到redis channel
     * @note 只有RedisStep及其派生类才能调用此方法，调用此方法时将调用者自身(RedisStep)添加到
     *       RedisChannel的pipeline中。
     * @param pChannel RedisChannel指针
     */
    bool SendTo(std::shared_ptr<RedisChannel> pChannel);

    /**
     * @brief 发送到redis channel
     * @note 只有RedisStep及其派生类才能调用此方法，调用此方法时将调用者自身(RedisStep)添加到
     *       RedisChannel的pipeline中。
     * @param strIdentify RedisChannel通道标识
     */
    bool SendTo(const std::string& strIdentify);

    /**
     * @brief 发送到redis channel
     * @note 只有RedisStep及其派生类才能调用此方法，调用此方法时将调用者自身(RedisStep)添加到
     *       RedisChannel的pipeline中。
     * @param strHost RedisChannel地址
     * @param iPort RedisChannel端口
     */
    bool SendTo(const std::string& strHost, int iPort);

    /**
     * @brief 发送到下一个同一类型的节点
     * @note 发送到下一个同一类型的节点，适用于对同一类型节点做轮询方式发送以达到简单的负载均衡。
     * @param strNodeType 节点类型
     * @param iCmd 发送的命令字
     * @param uiSeq 发送的数据包seq
     * @param oMsgBody 数据包体
     * @return 是否发送成功
     */
    bool SendRoundRobin(const std::string& strNodeType, int32 iCmd, uint32 uiSeq, const MsgBody& oMsgBody);

    /**
     * @brief 以取模方式选择发送到同一类型节点
     * @note 以取模方式选择发送到同一类型节点，实现简单有要求的负载均衡。
     * @param strNodeType 节点类型
     * @param uiFactor 定向发送因子
     * @param iCmd 发送的命令字
     * @param uiSeq 发送的数据包seq
     * @param oMsgBody 数据包体
     * @return 是否发送成功
     */
    bool SendOriented(const std::string& strNodeType, uint32 uiFactor, int32 iCmd, uint32 uiSeq, const MsgBody& oMsgBody);

    bool SendOriented(const std::string& strNodeType, int32 iCmd, uint32 uiSeq, const MsgBody& oMsgBody);

protected:
    virtual void SetActiveTime(ev_tstamp dActiveTime)
    {
        m_dActiveTime = dActiveTime;
    }

    ev_tstamp GetActiveTime() const
    {
        return(m_dActiveTime);
    }

    ev_tstamp GetTimeout() const
    {
        return(m_dTimeout);
    }

    ACTOR_TYPE GetActorType() const
    {
        return(m_eActorType);
    }

private:
    void SetWorker(Worker* pWorker);

    ev_timer* MutableTimerWatcher();

private:
    ACTOR_TYPE m_eActorType;
    uint32 m_ulSequence;
    ev_tstamp m_dActiveTime;
    ev_tstamp m_dTimeout;
    Worker* m_pWorker;
    ev_timer* m_pTimerWatcher;
    std::string m_strTraceId;       // for log trace
    std::shared_ptr<Context> m_pContext;

    friend class WorkerImpl;
    friend class WorkerFriend;
    friend class Cmd;
    friend class Module;
    friend class Step;
    friend class Session;
};


} /* namespace neb */

#endif /* SRC_ACTOR_ACTOR_HPP_ */
