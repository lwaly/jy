#ifndef _MANUAL_LOCK_H_
#define _MANUAL_LOCK_H_

#include <pthread.h>

class linux_mutex_lock
{
    pthread_mutex_t m_mutex;
public:
    linux_mutex_lock() { pthread_mutex_init(&m_mutex, NULL); }
    virtual ~linux_mutex_lock() { pthread_mutex_destroy(&m_mutex); }

    virtual void lock() { pthread_mutex_lock(&m_mutex); }
    virtual void unlock() { pthread_mutex_unlock(&m_mutex); }
};

class auto_lock
{
    linux_mutex_lock *m_p_base_lock;
public:
    auto_lock(linux_mutex_lock *p_base_lock) : m_p_base_lock(p_base_lock)
    {
        if (m_p_base_lock)
            m_p_base_lock->lock();
    }

    ~auto_lock()
    {
        if (m_p_base_lock)
            m_p_base_lock->unlock();
    }
};

#endif