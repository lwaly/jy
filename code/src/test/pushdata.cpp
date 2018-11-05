/*******************************************************************************
* Project:  行情数据推送服务
* @file     pushdata.cpp
* @brief
* @author
* @date:    2018年6月27日
* @note
* Modify history:
******************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <memory>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

#include "pushdata.hpp"
#include "ev.h"
#include "CBuffer.hpp"
#include "lock.h"

#define BIT_ITME 3   ///心跳间隔30秒

#define RC5 1       //加密类型

struct ev_loop *loop = NULL;
ev_timer* timeout_watcher;
ev_io* io_watcher;
linux_mutex_lock g_mutex_lock;

char cToken[129];

const unsigned int gc_uiCmdReq = 0x00000001;          ///< 请求（奇数为请求，偶数为应答，通过 gc_iCmdReq & iCmd 来判断，比%运算快）
const unsigned int gc_uiCmdBit = 0x0000FFFF;          ///< 命令为无符号短整型

unsigned int g_seq = 1;

#pragma pack(1)

/**
* @brief 与服户端通信消息头
*/
struct tagClientMsgHead
{
    unsigned char version;                  ///< 协议版本号（1字节）
    unsigned char encript;                  ///< 压缩加密算法（1字节）
    unsigned short cmd;                     ///< 命令字/功能号（2字节）
    unsigned short checksum;                ///< 校验码（2字节）
    unsigned int body_len;                  ///< 消息体长度（4字节）
    unsigned int seq;                       ///< 序列号（4字节）

    tagClientMsgHead() : version(0), encript(0), cmd(0), checksum(0), body_len(0), seq(0)
    {
    }
};

#pragma pack()

struct conndata
{
    int lastFd;
    CBuffer recvBuff;
    char *connIp;
    int connPort;
    ev_tstamp lastSendTime;
    struct ev_loop *ploop;
    CallbackMethod func;
    char errinfo[32];
    conndata() :connIp(NULL), ploop(NULL), func(NULL),lastFd(0){}
} *pdata = NULL;


char *gerError()
{
    return pdata->errinfo;
}

static int connectSvr(char *ip, int port)
{
    struct sockaddr_in stAddr;
    bzero(&stAddr, sizeof(stAddr));
    stAddr.sin_family = AF_INET;
    stAddr.sin_port = htons(port);
    stAddr.sin_addr.s_addr = inet_addr(ip);
    int Fd = socket(AF_INET, SOCK_STREAM, 0);
    struct timeval timeout = { 2, 0 };
    setsockopt(Fd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(struct timeval));

    if (connect(Fd, (struct sockaddr*)&stAddr, sizeof(stAddr)) < 0)
    {
        return -1;
    }
    int flags = fcntl(Fd, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(Fd, F_SETFL, flags);
    return Fd;
}

static void timeout_cb(EV_P_ ev_timer *timewatcher, int revents)
{
    //printf("func=%s line=%d\n", __FUNCTION__, __LINE__);
    conndata* tempdata = (conndata*)timewatcher->data;
    ev_tstamp after = tempdata->lastSendTime - ev_now(tempdata->ploop) + BIT_ITME;

    if (after > 0)    // IO在定时时间内被重新刷新过，重新设置定时器
    {
        ev_timer_stop(tempdata->ploop, timewatcher);
        ev_timer_set(timewatcher, after + ev_time() - ev_now(tempdata->ploop), 0);
        ev_timer_start(tempdata->ploop, timewatcher);
    }
    else    // IO已超时，发送心跳检查   
    {
        //printf("func=%s line=%d\n", __FUNCTION__, __LINE__);
        //         int iErrno = 0;
        //         tagClientMsgHead stClientMsgHead;
        //         CBuffer oWriteBuff;
        // 
        //         stClientMsgHead.version = 1;        // version暂时无用
        //         stClientMsgHead.encript = (unsigned char)(1);
        //         stClientMsgHead.cmd = htons((unsigned short)(gc_uiCmdBit & 507));
        //         stClientMsgHead.body_len = htonl((unsigned int)0);
        //         // 进入临界区
        //         //EnterCriticalSection(&g_cs);
        //         stClientMsgHead.seq = htonl(g_seq++);
        //         // 离开临界区
        //         //LeaveCriticalSection(&g_cs);
        //         int iNeedWriteLen = sizeof(stClientMsgHead);
        //         oWriteBuff.Write(&stClientMsgHead, iNeedWriteLen);
        // 
        //         int iWriteSize = oWriteBuff.WriteFD(tempdata->lastFd, iErrno);
        //         if (iWriteSize < 0)
        //         {
        //             if (EAGAIN != iErrno && EINTR != iErrno)    // 对非阻塞socket而言，EAGAIN不是一种错误;EINTR即errno为4，错误描述Interrupted system call，操作也应该继续。
        //             {
        //                 if (0 < tempdata->lastFd)
        //                 {
        //                     ev_io_stop(loop, io_watcher);
        //                     close(tempdata->lastFd);
        //                     tempdata->lastFd = 0;
        //                 }
        // 
        //                 tempdata->lastFd = connectSvr(tempdata->connIp, tempdata->connPort);
        //                 if (tempdata->lastFd < 0)
        //                 {
        //                     memcpy(tempdata->errinfo, "fail to reconnect", sizeof(tempdata->errinfo));
        //                 }
        //                 else
        //                 {
        //                     memcpy(tempdata->errinfo, "reconnect successful", sizeof(tempdata->errinfo));
        // 
        //                     ev_io_set(io_watcher, tempdata->lastFd, EV_READ);
        //                     ev_io_start(loop, io_watcher);
        //                 }
        // 
        //                 ev_timer_stop(tempdata->ploop, timewatcher);
        //                 ev_timer_set(timewatcher, BIT_ITME, 0);
        //                 ev_timer_start(tempdata->ploop, timewatcher);
        //                 return;
        //             }
        //         }
        //         pdata->lastSendTime = ev_now(loop);
        SendMsg("", 0, 507);
        ev_timer_stop(tempdata->ploop, timewatcher);
        ev_timer_set(timewatcher, BIT_ITME, 0.0);
        ev_timer_start(tempdata->ploop, timewatcher);
    }
}

static void IoRedata(EV_P_ ev_io *watcher, int revents)
{
    if (revents & EV_READ)
    {
        conndata* tempdata = (conndata*)watcher->data;
        bool isreadsuccess = false;
        int bytes_read = 0;

        int m_read_idx = 0;
        int iErrno = 0;
        tagClientMsgHead oMsgHead;

        int iHeadSize = sizeof(tagClientMsgHead);
        while (true)
        {
            int iReadSize = tempdata->recvBuff.ReadFD(tempdata->lastFd, iErrno);
            if (iReadSize < 0)
            {
                if (EINTR == iErrno)    // 对非阻塞socket而言，EAGAIN不是一种错误;EINTR即errno为4，错误描述Interrupted system call，操作也应该继续。
                {
                    usleep(10);
                    continue;
                }
                else if (EAGAIN == iErrno)
                {
                    return;
                }
                else
                {
                    ev_io_stop(loop, io_watcher);
                    break;
                }
            }
            else if (0 == iReadSize)
            {
                return;
            }
            pdata->lastSendTime = ev_now(loop);
            while (tempdata->recvBuff.ReadableBytes() >= iHeadSize)
            {
                int iReadIdx = tempdata->recvBuff.GetReadIndex();
                tempdata->recvBuff.Read(&oMsgHead, iHeadSize);
                oMsgHead.cmd = ntohs(oMsgHead.cmd);
                oMsgHead.body_len = ntohl(oMsgHead.body_len);
                oMsgHead.seq = ntohl(oMsgHead.seq);
                oMsgHead.checksum = ntohs(oMsgHead.checksum);
                if (tempdata->recvBuff.ReadableBytes() >= oMsgHead.body_len)
                {
                    if (0 != oMsgHead.body_len)
                    {
                        tempdata->func(tempdata->recvBuff.GetRawReadBuffer(), oMsgHead.body_len, oMsgHead.cmd, oMsgHead.seq);
                        tempdata->recvBuff.SkipBytes(oMsgHead.body_len);
                    }
                    if (tempdata->recvBuff.ReadableBytes() >= iHeadSize)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    tempdata->recvBuff.SetReadIndex(iReadIdx);
                    break;
                }
            }
        }
    }
}

void StopSvr()
{
    ev_timer_stop(pdata->ploop, timeout_watcher);
    ev_io_stop(pdata->ploop, io_watcher);
    if (pdata->lastFd > 0)
    {
        close(pdata->lastFd);
    }
    if (pdata != NULL)
    {
        if (NULL != pdata->connIp)
        {
            delete pdata->connIp;
            pdata->connIp = NULL;
        }
        delete pdata;
        pdata = NULL;
    }
    if (timeout_watcher != NULL)
    {
        delete timeout_watcher;
        timeout_watcher = NULL;
    }
    if (io_watcher != NULL)
    {
        delete io_watcher;
        io_watcher = NULL;
    }
    if (loop != NULL)
    {
        ev_loop_destroy(loop);
        loop = NULL;
    }
}

static void* ThreadFunc(void *arg)
{
    conndata *tdata = (conndata*)arg;
    timeout_watcher = new ev_timer();
    ev_timer_init(timeout_watcher, timeout_cb, BIT_ITME, 0.0);
    timeout_watcher->data = (void*)tdata;
    ev_timer_start(loop, timeout_watcher);
    int connfd = connectSvr(tdata->connIp, tdata->connPort);
    if (connfd < 0)
    {
        memcpy(pdata->errinfo, "failed to connect", sizeof(pdata->errinfo));
        /*        return -1;*/
    }
    else
    {
        pdata->lastFd = connfd;
        ev_io_set(io_watcher, tdata->lastFd, EV_READ);
        ev_io_start(loop, io_watcher);
    }

    ev_run(loop, 0);
    return NULL;
}

int StartSvr(const char * ip, int port, CallbackMethod CallAppFunc)
{
    if ((NULL == ip) || (NULL == CallAppFunc))
    {
        memcpy(pdata->errinfo, "parameter err", sizeof(pdata->errinfo));
        return -1;
    }
    signal(SIGPIPE, SIG_IGN);
    // 
    //     memset(cToken, '\0', sizeof(cToken));
    //     if (strlen(token) >= sizeof(cToken))
    //     {
    //         return -1;
    //     }
    //    memcpy(cToken, token, strlen(token));

    char *strHost = (char *)malloc(strlen(ip) + 1);
    memset(strHost, '\0', strlen(ip));
    memcpy(strHost, ip, strlen(ip));
    int iPort = port;

    pdata = new conndata();
    pdata->connIp = strHost;
    pdata->connPort = iPort;
    pdata->func = CallAppFunc;
    memcpy(pdata->errinfo, "success", sizeof(pdata->errinfo));

    loop = EV_DEFAULT;
    pdata->ploop = loop;
    pdata->lastSendTime = ev_now(loop);

    io_watcher = new ev_io();
    io_watcher->data = (void*)pdata;
    ev_init(io_watcher, IoRedata);
    //     int connfd = connectSvr(strHost, iPort);
    //     if (connfd < 0)
    //     {
    //         memcpy(pdata->errinfo, "failed to connect", sizeof(pdata->errinfo));
    // /*        return -1;*/
    //     }
    //     pdata->lastFd = connfd;

    //     loop = EV_DEFAULT;
    //     pdata->ploop = loop;
    //     pdata->lastSendTime = ev_now(loop);

    ////printf("func=%s line=%d\n", __FUNCTION__, __LINE__);
    //     timeout_watcher = new ev_timer();
    //     ev_timer_init(timeout_watcher, timeout_cb, BIT_ITME, 0.0);
    //     timeout_watcher->data = (void*)pdata;
    //     ev_timer_start(loop, timeout_watcher);
    // 
    //     io_watcher = new ev_io();
    //     ev_io_init(io_watcher, IoRedata, pdata->lastFd, EV_READ);
    //     io_watcher->data = (void*)pdata;
    //     ev_io_start(loop, io_watcher);

    //    ev_run(loop, 0);

    pthread_t worker;
    if (pthread_create(&worker, NULL, ThreadFunc, (void *)pdata) != 0)
    {
        memcpy(pdata->errinfo, "failed to create thread", sizeof(pdata->errinfo));
        return -1;
    }
    pthread_detach(worker);

    return 0;
}

int updateToken(const char *token)
{
    memset(cToken, '\0', sizeof(cToken));
    if (strlen(token) >= sizeof(cToken))
    {
        return -1;
    }
    memcpy(cToken, token, strlen(token));
    return 0;
}

int SendMsg(const char *pBody, int bodyLen, int cmd)
{
    if (NULL == pdata)
    {
        return -1;
    }
    int iErrno = 0;
    CBuffer oWriteBuff;

    tagClientMsgHead oMsgHead;
    oMsgHead.version = 1;        // version暂时无用
    oMsgHead.encript = (unsigned char)(0);
    oMsgHead.cmd = htons((unsigned short)(gc_uiCmdBit & cmd));
    oMsgHead.body_len = htonl((unsigned int)bodyLen);
    unsigned int seq;

    auto_lock lock(&g_mutex_lock);
    if (0 == g_seq)
    {
        g_seq = 1;
    }
    seq = g_seq;
    oMsgHead.seq = htonl(g_seq++);
    //     oMsgHead.version = 1;        // version暂时无用
    //     oMsgHead.encript = (unsigned char)(RC5);
    //     oMsgHead.cmd = htons((unsigned short)(gc_uiCmdBit & cmd));
    //     oMsgHead.body_len = htonl((unsigned int)bodyLen);
    //     // 进入临界区
    //     //EnterCriticalSection(&g_cs);
    //     oMsgHead.seq = htonl(g_seq++);
    // 离开临界区
    //LeaveCriticalSection(&g_cs);
    oWriteBuff.Write(&oMsgHead, sizeof(oMsgHead));
    oWriteBuff.Write(pBody, bodyLen);

    int iWriteSize = oWriteBuff.WriteFD(pdata->lastFd, iErrno);
    if (iWriteSize < 0)
    {
        if (EAGAIN != iErrno && EINTR != iErrno)    // 对非阻塞socket而言，EAGAIN不是一种错误;EINTR即errno为4，错误描述Interrupted system call，操作也应该继续。
        {
            if (0 < pdata->lastFd)
            {
                ev_io_stop(loop, io_watcher);
                close(pdata->lastFd);
                pdata->lastFd = 0;
            }
            pdata->lastFd = connectSvr(pdata->connIp, pdata->connPort);
            if (pdata->lastFd < 0)
            {
                memcpy(pdata->errinfo, "fail to reconnect", sizeof(pdata->errinfo));
                return -1;
            }
            else
            {
                ev_io_set(io_watcher, pdata->lastFd, EV_READ);
                ev_io_start(loop, io_watcher);
                int iWriteSize = oWriteBuff.WriteFD(pdata->lastFd, iErrno);
                if (iWriteSize < 0)
                {
                    return -1;
                }
                if ((NULL != pdata) && (NULL != pdata->func))
                {
                    pdata->func(NULL, 0, 0, 0);
                }
                memcpy(pdata->errinfo, "reconnect successful", sizeof(pdata->errinfo));
            }
        }
        else
        {
            return -1;
        }
    }
    else if (iWriteSize = 0)
    {
        return -1;
    }

    pdata->lastSendTime = ev_now(loop);
    return seq;
}
