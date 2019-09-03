#pragma once

#include "appenderI.h"

#include "appender/console_appender.h"
#include "appender/file_appender.h"
#include "formatter/line_formatter.h"

#include <string>
#include <list>
#include <cassert>

#include "logstream.h"

class Logger {
public:
    Logger(AppenderI * appender) {
        assert(!m_instance);

        if (appender)
            m_appenders.push_back(appender);

        m_instance = this;
    }

    void addAppender(AppenderI * appender) {
        if (appender)
            m_appenders.push_back(appender);
    }

    void operator += (LogStream & logStream) {
        std::list<AppenderI *>::iterator iter = m_appenders.begin();
        for (; iter != m_appenders.end(); iter++) {
            (*iter)->log(logStream);
        }
    }
    
    static Logger * getInstance() {
        return m_instance;
    }

protected:
    Logger(Logger & logger) {
    }

    Logger & operator = (Logger & logger) {
        return logger;
    }

private:
    static Logger * m_instance;
    std::list<AppenderI *> m_appenders;
};


Logger * Logger::m_instance = nullptr;

inline Logger * init() {
    LineFormatter * lineFormatter = new LineFormatter();
    Logger * logger = new Logger(new ConsoleAppender(lineFormatter));
    return logger;
}

inline Logger * init(std::string fileName) {
    LineFormatter * lineFormatter = new LineFormatter();
    Logger * logger = new Logger(new FileAppender(fileName, lineFormatter));
    return logger;
}

inline Logger * addConsole() {
    LineFormatter * lineFormatter = new LineFormatter();
    Logger::getInstance()->addAppender(new ConsoleAppender(lineFormatter));
    return Logger::getInstance();
}

inline Logger * addFile(std::string fileName) {
    LineFormatter * lineFormatter = new LineFormatter();
    Logger::getInstance()->addAppender(new FileAppender(fileName, lineFormatter));
    return Logger::getInstance();
}
