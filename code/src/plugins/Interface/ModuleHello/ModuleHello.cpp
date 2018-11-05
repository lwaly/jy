/*******************************************************************************
 * Project:  InterfaceServer
 * @file     ModuleHello.cpp
 * @brief 
 * @author   lbh
 * @date:    2016年7月6日
 * @note
 * Modify history:
 ******************************************************************************/
#include <fstream>
#include "ModuleHello.hpp"

namespace inter
{

ModuleHello::ModuleHello(const std::string& strModulePath)
    : neb::Module(strModulePath), pStepHello(nullptr)
{
}

ModuleHello::~ModuleHello()
{
    for (auto iter = m_mapModuleConf.begin();
             iter != m_mapModuleConf.end(); ++iter)
    {
        if (iter->second != NULL)
        {
            delete iter->second;
            iter->second = NULL;
        }
    }
    m_mapModuleConf.clear();
}

bool ModuleHello::Init()
{
    std::string strConfFile = GetWorkPath() + std::string("/release/conf/ModuleHello.json");
    LOG4_DEBUG("CONF FILE = %s.", strConfFile.c_str());

    std::ifstream fin(strConfFile.c_str());
    if (fin.good())
    {
        std::stringstream ssContent;
        neb::CJsonObject oHelloConf;
        ssContent << fin.rdbuf();
        fin.close();
        if (oHelloConf.Parse(ssContent.str()))
        {
            std::string strUrlPath;
            int iCmd = 0;
            neb::CJsonObject* pModuleJson = NULL;
            if (oHelloConf["module"].IsEmpty())
            {
                LOG4_WARNING("oHelloConf[\"module\"] is empty!");
            }
            for (int i = 0; i < oHelloConf["module"].GetArraySize(); ++i)
            {
                if (std::string("/im/hello_switch") == oHelloConf["module"][i]("url_path"))
                {
                    continue;
                }
                bool bAcceptModule = false;
                pModuleJson = new neb::CJsonObject(oHelloConf["module"][i]);
                if (pModuleJson->Get("url_path", strUrlPath) && pModuleJson->Get("cmd", iCmd))
                {
                    for (int j = 0; j < (*pModuleJson)["node_type"].GetArraySize(); ++j)
                    {
                        if ((*pModuleJson)["node_type"](j) == GetNodeType())
                        {
                            m_mapModuleConf.insert(std::make_pair(strUrlPath, pModuleJson));
                            bAcceptModule = true;
                            break;
                        }
                    }
                    if (!bAcceptModule)
                    {
                        DELETE(pModuleJson);
                    }
                }
                else
                {
                    LOG4_ERROR("miss \"url_paht\" or \"cmd\" in oHelloConf[\"module\"][%d]", i);
                    DELETE(pModuleJson);
                }
            }
        }
        else
        {
            LOG4_ERROR("oHelloConf pasre error");
            return(false);
        }
    }
    else
    {
        //配置信息流读取失败
        LOG4_ERROR("Open conf \"%s\" error!", strConfFile.c_str());
        return(false);
    }

    return(true);
}

bool ModuleHello::AnyMessage(
                std::shared_ptr<neb::SocketChannel> pUpstreamChannel,
                const HttpMsg& oInHttpMsg)
{
    if (HTTP_OPTIONS == oInHttpMsg.method())
    {
        LOG4_TRACE("receive an OPTIONS");
        ResponseOptions(pUpstreamChannel, oInHttpMsg);
        return(true);
    }
    auto module_conf_iter = m_mapModuleConf.find(oInHttpMsg.path());
    if (module_conf_iter == m_mapModuleConf.end())
    {
        HttpMsg oOutHttpMsg;
        LOG4_ERROR("no cmd config for %s in \"ModuleHello.json\"!", oInHttpMsg.path().c_str());
        oOutHttpMsg.set_type(HTTP_RESPONSE);
        oOutHttpMsg.set_status_code(404);
        oOutHttpMsg.set_http_major(oInHttpMsg.http_major());
        oOutHttpMsg.set_http_minor(oInHttpMsg.http_minor());
        return(false);
    }

    pStepHello = std::dynamic_pointer_cast<StepHello>(MakeSharedStep("inter::StepHello", pUpstreamChannel, oInHttpMsg, module_conf_iter->second));
    if ((pStepHello))
    {
        if (neb::CMD_STATUS_RUNNING == pStepHello->Emit(neb::ERR_OK))
        {
            LOG4_TRACE("pStepHello running");
            return(true);
        }
    }
    return(false);
}

void ModuleHello::Response(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const HttpMsg& oInHttpMsg, int iErrno, const std::string& strErrMsg)
{
    HttpMsg oHttpMsg;
    neb::CJsonObject oResponseData;
    oHttpMsg.set_type(HTTP_RESPONSE);
    oHttpMsg.set_status_code(200);
    oHttpMsg.set_http_major(oInHttpMsg.http_major());
    oHttpMsg.set_http_minor(oInHttpMsg.http_minor());
    oResponseData.Add("code", iErrno);
    oResponseData.Add("msg", strErrMsg);
    if (iErrno == 0)
    {
        oResponseData.Add("data", neb::CJsonObject("[]"));
    }
    oHttpMsg.set_body(oResponseData.ToFormattedString());
    SendTo(pUpstreamChannel, oHttpMsg);
}

void ModuleHello::ResponseOptions(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const HttpMsg& oInHttpMsg)
{
    LOG4_DEBUG("%s()", __FUNCTION__);
    HttpMsg oHttpMsg;
    oHttpMsg.set_type(HTTP_RESPONSE);
    oHttpMsg.set_status_code(200);
    oHttpMsg.set_http_major(oInHttpMsg.http_major());
    oHttpMsg.set_http_minor(oInHttpMsg.http_minor());
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Connection", "keep-alive"));
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Access-Control-Allow-Origin", "*"));
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Access-Control-Allow-Headers", "Origin, Content-Type, Cookie, Accept"));
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Access-Control-Allow-Methods", "GET, POST"));
    oHttpMsg.mutable_headers()->insert(google::protobuf::MapPair<std::string, std::string>("Access-Control-Allow-Credentials", "true"));
    SendTo(pUpstreamChannel, oHttpMsg);
}

} /* namespace inter */
