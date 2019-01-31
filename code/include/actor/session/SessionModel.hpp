/*******************************************************************************
 * Project:  Nebula
 * @file     SessionModel.hpp
 * @brief 
 * @author   bwar
 * @date:    Apr 4, 2018
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_ACTOR_SESSION_SESSIONMODEL_HPP_
#define SRC_ACTOR_SESSION_SESSIONMODEL_HPP_

#include "actor/Actor.hpp"

namespace neb
{

class SessionModel: public Actor
{
public:
    SessionModel(uint32 ulSessionId, ev_tstamp dSessionTimeout = 60.0);
    SessionModel(const std::string& strSessionId, ev_tstamp dSessionTimeout = 60.0);
    SessionModel(const SessionModel&) = delete;
    SessionModel& operator=(const SessionModel&) = delete;
    virtual ~SessionModel();

    /**
     * @brief 会话超时回调
     */
    virtual E_CMD_STATUS Timeout() = 0;

    const std::string& GetSessionId() const
    {
        return(m_strSessionId);
    }

private:
    std::string m_strSessionId;
    friend class WorkerImpl;
};

} /* namespace neb */

#endif /* SRC_ACTOR_SESSION_SESSIONMODEL_HPP_ */
