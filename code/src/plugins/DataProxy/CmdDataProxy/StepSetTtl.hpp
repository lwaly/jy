/*******************************************************************************
* Project:  DataProxyServer
* @file     StepSetTtl.hpp
* @brief    设置过期时间
* @author   xxx
* @date:    2016年3月26日
* @note
* Modify history:
******************************************************************************/
#ifndef SRC_CMDDATAPROXY_STEPSETTTL_HPP_
#define SRC_CMDDATAPROXY_STEPSETTTL_HPP_

#include "RedisStorageStep.hpp"

namespace neb {

    class StepSetTtl: public RedisStorageStep {
    public:
        StepSetTtl(const std::string& strMasterNodeIdentify, const std::string& strKey, int32 iExpireSeconds);
        virtual ~StepSetTtl();

        virtual E_CMD_STATUS Emit(int iErrno, const std::string& strErrMsg = "", const std::string& strErrShow = "");

        virtual E_CMD_STATUS Callback(const redisAsyncContext* c, int status, redisReply* pReply);

    private:
        std::string m_strMasterNodeIdentify;
        std::string m_strKey;
        int32 m_iExpireSeconds;
    };

} /* namespace neb */

#endif /* SRC_CMDDATAPROXY_STEPSETTTL_HPP_ */
