/*******************************************************************************
 * Project:  Beacon
 * @file     CmdToClient.hpp
 * @brief 
 * @author   bwar
 * @date:    Feb 14, 2017
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_CMD_TO_CLIENT_HPP_
#define SRC_CMD_TO_CLIENT_HPP_

#include <string>
#include <unordered_map>
#include <Error.hpp>
#include <util/json/CJsonObject.hpp>
#include <actor/cmd/Cmd.hpp>
#include "StepToClient.hpp"

namespace plugins
{

class CmdToClient: public neb::Cmd, public neb::DynamicCreator<CmdToClient, int32>
{
public:
    CmdToClient(int32 iCmd);
    virtual ~CmdToClient();

    virtual bool Init();
    virtual bool AnyMessage(std::shared_ptr<neb::SocketChannel> pUpstreamChannel, const MsgHead& oMsgHead, const MsgBody& oMsgBody);

    virtual std::string ObjectName() const
    {
        return("plugins::CmdToClient");
    }

public:
    std::shared_ptr<StepToClient> m_pStep;
};

} /* namespace plugins */

#endif /* SRC_CMDNODEDISCONNECT_CMDNODEDISCONNECT_HPP_ */
