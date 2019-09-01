#pragma once

#include "logger.h"
#include "serverity.h"

#include <sstream>

class LogStream {
public:
    LogStream(Serverity serverity) :
        m_serverity(serverity) {

    }
    
    ~LogStream() {
    }

    std::stringstream & getMessage() {
        return m_message;
    }

    template <class T>
    LogStream & operator<< (T & data) {
        switch (m_serverity) {
        case Info:
            m_message << "Info: "; break;
        case Debug:
            m_message << "Debug: "; break;
        case Error:
            m_message << "Error: "; break;
        }

        m_message << data;
        return *this;
    }

private:
    std::stringstream m_message;
    Serverity m_serverity;
};
