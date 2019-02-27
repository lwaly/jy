/*******************************************************************************
 * Project:  Nebula
 * @file     PbStep.hpp
 * @brief 
 * @author   Bwar
 * @date:    2016年8月12日
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_ACTOR_STEP_PBSTEP_HPP_
#define SRC_ACTOR_STEP_PBSTEP_HPP_

#include <actor/step/Step.hpp>

namespace neb
{

class WorkerImpl;

class PbStep: public Step
{
public:
    PbStep(std::shared_ptr<Step> pNextStep = nullptr, ev_tstamp dTimeout = gc_dDefaultTimeout);
    PbStep(std::shared_ptr<SocketChannel> pChannel, const MsgHead& oReqMsgHead, const MsgBody& oReqMsgBody,
        std::shared_ptr<Step> pNextStep = nullptr, ev_tstamp dTimeout = gc_dDefaultTimeout);
    PbStep(const PbStep&) = delete;
    PbStep& operator=(const PbStep&) = delete;
    virtual ~PbStep();

    /**
     * @brief 步骤回调函数
     * @note 满足某个条件，比如监控某个文件描述符fd的EPOLLIN事件和EPOLLERR事件，当这个fd的
     * 这两类事件中的任意一类到达时则会调用Callback()。具体使用到哪几个参数与业务逻辑有关，前三个
     * 参数的使用概率高。
     * @param pChannel 消息来源通信通道
     * @param oMsgHead 消息头
     * @param oMsgBody 消息体
     * @param data 数据指针
     */
    virtual E_CMD_STATUS Callback(
            std::shared_ptr<SocketChannel> pChannel,
            const MsgHead& oMsgHead,
            const MsgBody& oMsgBody,
            void* data = NULL) = 0;

protected:  // 请求端的上下文信息，通过Step构造函数初始化，若调用的是不带参数的构造函数Step()，则这几个成员不会被初始化
    std::shared_ptr<SocketChannel> m_pUpstreamChannel;
    MsgHead m_oReqMsgHead;
    MsgBody m_oReqMsgBody;

private:
    friend class WorkerImpl;
};

} /* namespace neb */

#endif /* SRC_ACTOR_STEP_PBSTEP_HPP_ */
