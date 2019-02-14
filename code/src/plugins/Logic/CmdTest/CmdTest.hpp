/*******************************************************************************
 * Project:  Logic
 * @file     CmdTest.hpp
 * @brief 
 * @author   bwar
 * @date:    Feb 21, 2017
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_CMD_TEST_HPP_
#define SRC_CMD_TEST_HPP_

#include <actor/cmd/Cmd.hpp>
#include "StepTest.hpp"

namespace logic
{

class CmdTest: public neb::Cmd, public neb::DynamicCreator<CmdTest, int32>
{
public:
    CmdTest(int32 iCmd);
    virtual ~CmdTest();

    virtual bool Init();
    virtual bool AnyMessage(
                    std::shared_ptr<neb::SocketChannel> pChannel, 
                    const MsgHead& oMsgHead,
                    const MsgBody& oMsgBody);

public:
    std::shared_ptr<StepTest> m_pStep;
};

} /* namespace logic */

#endif /* SRC_CMD_TEST_HPP_ */
