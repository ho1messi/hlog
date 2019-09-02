#pragma once

#include "logger.h"
#include "serverity.h"
#include "utils.h"

#include <sstream>

class LogStream {
public:
    LogStream(Serverity serverity, const char * func, size_t line) :
        m_serverity(serverity), m_func(func), m_line(line), m_tid(pthread_self()) {

    }
    
    ~LogStream() {
    }

    const char * getMessage() {
        m_messageStr = m_message.str();
        return m_messageStr.c_str();
    }

    const char * getFunc() {
        return m_func;
    }

    size_t getLine() {
        return m_line;
    }

    unsigned int getTid() {
        return m_tid;
    }

    Serverity getServerity() {
        return m_serverity;
    }

    template <class T>
    LogStream & operator<< (T & data) {
        m_message << data;
        return *this;
    }

private:
    std::stringstream m_message;
    std::string m_messageStr;

    const char * m_func;
    size_t m_line;
    unsigned int m_tid;
    Serverity m_serverity;
};
