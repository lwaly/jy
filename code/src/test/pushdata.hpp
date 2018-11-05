/*******************************************************************************
* Project:  行情数据推送服务
* @file     pushdata.hpp
* @brief
* @author
* @date:    2018年6月27日
* @note
* Modify history:
******************************************************************************/
#ifndef SDK_DATA_PUSH_HPP_
#define SDK_DATA_PUSH_HPP_

typedef void(*CallbackMethod)(const char *pBody, int bodyLen, int cmd, unsigned int seq); //回调app接口

//启动服务
int StartSvr(const char * ip, int port, CallbackMethod CallAppFunc);

//获取报错信息
char *gerError();

//消息发送
int SendMsg(const char *pBody, int bodyLen, int cmd);

//token更新
int updateToken(const char *token);
//停止服务
void StopSvr();

#endif /* SDK_DATA_PUSH_HPP_ */

