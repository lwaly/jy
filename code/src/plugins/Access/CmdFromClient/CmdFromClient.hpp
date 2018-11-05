/*******************************************************************************
 * Project:  Beacon
 * @file     CmdFromClient.hpp
 * @brief 
 * @author   bwar
 * @date:    Feb 14, 2017
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_CMD_FROM_CLIENT_HPP_
#define SRC_CMD_FROM_CLIENT_HPP_

#include <string>
#include <unordered_map>
#include <Error.hpp>
#include <util/json/CJsonObject.hpp>
#include <actor/cmd/Cmd.hpp>
#include "StepFromClient.hpp"

namespace plugins
{

class CmdFromClient: public neb::Cmd, public neb::DynamicCreator<CmdFromClient, int32>
{
public:
    CmdFromClient(int32 iCmd);
    virtual ~CmdFromClient();

    virtual bool Init();
    virtual bool AnyMessage(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody);

    virtual std::string ObjectName() const
    {
        return("plugins::CmdFromClient");
    }

public:
    std::shared_ptr<StepFromClient> m_pStep;
};

} /* namespace beacon */

#endif /* SRC_CMDNODEDISCONNECT_CMDNODEDISCONNECT_HPP_ */
