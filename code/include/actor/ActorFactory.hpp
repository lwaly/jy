/*******************************************************************************
 * Project:  Nebula
 * @file     ActorFactory.hpp
 * @brief 
 * @author   bwar
 * @date:    Mar 11, 2018
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_ACTOR_ACTORFACTORY_HPP_
#define SRC_ACTOR_ACTORFACTORY_HPP_

#include <string>
#include <unordered_map>

namespace neb
{

class Actor;

template<typename T, typename ...Targs>
class ActorFactory
{
public:
    static ActorFactory* Instance()
    {
        if (nullptr == m_pActorFactory)
        {
            m_pActorFactory = new ActorFactory();
        }
        return(m_pActorFactory);
    }

    virtual ~ActorFactory(){};

    bool Regist(const std::string& strTypeName, std::function<Actor*(Targs&&... args)> pFunc);
    Actor* Create(const std::string& strTypeName, Targs&&... args);
    void Print(std::string& strRes)
    {
        strRes = m_strRes;
    }
private:
    ActorFactory(){};
    static ActorFactory<typename T, Targs...>* m_pActorFactory;
    static string m_strRes;
    std::unordered_map<std::string, std::function<Actor*(Targs&&...)> > m_mapCreateFunction;
};


template<typename T, typename ...Targs>
ActorFactory<typename T, Targs...>* ActorFactory<typename T, Targs...>::m_pActorFactory = nullptr;

template<typename T, typename ...Targs>
bool ActorFactory<typename T, Targs...>::Regist(const std::string& strTypeName, std::function<Actor*(Targs&&... args)> pFunc)
{
    m_strRes += strTypeName + "  ";
    if (nullptr == pFunc)
    {
        return (false);
    }

    m_strRes += strTypeName + "  ";
    bool bReg = m_mapCreateFunction.insert(
                    std::make_pair(strTypeName, pFunc)).second;
    return (bReg);
}

template<typename T, typename ...Targs>
Actor* ActorFactory<typename T, Targs...>::Create(const std::string& strTypeName, Targs&&... args)
{
    T* pT = nullptr;
    try
    {
        pT = new T(std::forward<Targs>(args)...);
    }
    catch(std::bad_alloc& e)
    {
        //std::cerr << e.what() << std::endl;     // TODO write log
        return(nullptr);
    }
    return(pT);
    //auto iter = m_mapCreateFunction.find(strTypeName);
    //if (iter == m_mapCreateFunction.end())
    //{
    //    return (nullptr);
    //}
    //else
    //{
    //    return (iter->second(std::forward<Targs>(args)...));
    //}
}


} /* namespace neb */

#endif /* SRC_ACTOR_ACTORFACTORY_HPP_ */
