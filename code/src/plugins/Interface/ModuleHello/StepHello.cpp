/*******************************************************************************
 * Project:  InterfaceServer
 * @file     StepHello.cpp
 * @brief 
 * @author   lbh
 * @date:    2016年7月6日
 * @note
 * Modify history:
 ******************************************************************************/

#include <util/http/http_parser.h>
#include "StepHello.hpp"

namespace inter
{

StepHello::StepHello(std::shared_ptr<neb::SocketChannel> pUpstreamChannel,
                const HttpMsg& oInHttpMsg, const neb::CJsonObject* pModuleConf)
    : m_pRequestUpstreamChannel(pUpstreamChannel), m_oInHttpMsg(oInHttpMsg), m_oModuleConf(pModuleConf)
{
}

StepHello::~StepHello()
{
}

neb::E_CMD_STATUS StepHello::Emit(int iErrno, const std::string& strErrMsg, void* data)
{
    LOG4_DEBUG("%s()", __FUNCTION__);
    if (neb::ERR_OK != iErrno)
    {
        LOG4_ERROR("error %d: %s!", iErrno, strErrMsg.c_str());
        Response(iErrno, strErrMsg, strErrMsg);
        return(neb::CMD_STATUS_FAULT);
    }

    return(EmitHello());
}

neb::E_CMD_STATUS StepHello::Callback(
        std::shared_ptr<neb::SocketChannel> pUpstreamChannel,
        const MsgHead& oInMsgHead,
        const MsgBody& oInMsgBody,
        void* data)
{
    LOG4_TRACE("%s()", __FUNCTION__);
    return(CallbackHello(pUpstreamChannel, oInMsgHead, oInMsgBody));
}

neb::E_CMD_STATUS StepHello::Timeout()
{
    LOG4_DEBUG("%s()", __FUNCTION__);
    return(neb::CMD_STATUS_FAULT);
}

neb::E_CMD_STATUS StepHello::EmitHello()
{
    LOG4_DEBUG("%s", __FUNCTION__);
    uint32 uiCmd = 0;
    m_oModuleConf.Get("cmd", uiCmd);
    m_oHelloMsgBody.set_data(m_oInHttpMsg.body());

    if (m_oHelloMsgBody.has_req_target())
    {
        if (m_oHelloMsgBody.req_target().route_id() > 0)
        {
            SendOriented("LOGIC", m_oHelloMsgBody.req_target().route_id(), uiCmd, GetSequence(), m_oHelloMsgBody);
        }
        else if (m_oHelloMsgBody.req_target().route().size() > 0)
        {
            SendOriented("LOGIC", m_oHelloMsgBody.req_target().route().size(), uiCmd, GetSequence(), m_oHelloMsgBody);
        }
        else
        {
            SendPolling("LOGIC", uiCmd, GetSequence(), m_oHelloMsgBody);
        }
    }
    else
    {
        SendPolling("LOGIC", uiCmd, GetSequence(), m_oHelloMsgBody);
    }
    return (neb::CMD_STATUS_RUNNING);
}

neb::E_CMD_STATUS StepHello::CallbackHello(
                std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oInMsgHead, const MsgBody& oInMsgBody)
{
    LOG4_DEBUG("%s()", __FUNCTION__);
    HttpMsg oHttpMsg;
    oHttpMsg.set_type(HTTP_RESPONSE);
    oHttpMsg.set_status_code(200);
    oHttpMsg.set_http_major(m_oInHttpMsg.http_major());
    oHttpMsg.set_http_minor(m_oInHttpMsg.http_minor());
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Access-Control-Allow-Origin", "*"));
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Access-Control-Allow-Headers", "Origin, Content-Type, Cookie, Accept"));
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Access-Control-Allow-Methods", "GET, POST"));
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Access-Control-Allow-Credentials", "true"));
    oHttpMsg.set_body(oInMsgBody.data());
    SendTo(m_pRequestUpstreamChannel, oHttpMsg);
    return (neb::CMD_STATUS_COMPLETED);
}

void StepHello::Response(int iErrno, const std::string& strErrMsg, const std::string& strErrClientShow)
{
    LOG4_TRACE("%s()", __FUNCTION__);
    HttpMsg oHttpMsg;
    neb::CJsonObject oResponseData;
    oHttpMsg.set_type(HTTP_RESPONSE);
    oHttpMsg.set_status_code(200);
    oHttpMsg.set_http_major(m_oInHttpMsg.http_major());
    oHttpMsg.set_http_minor(m_oInHttpMsg.http_minor());
    oResponseData.Add("code", iErrno);
    oResponseData.Add("msg", strErrClientShow);
    if (iErrno == 0)
    {
        oResponseData.Add("data", neb::CJsonObject("[]"));
    }
    oHttpMsg.set_body(oResponseData.ToFormattedString());
    SendTo(m_pRequestUpstreamChannel, oHttpMsg);
}

} /* namespace im */
