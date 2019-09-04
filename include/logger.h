#pragma once

#include "appenderI.h"

#include "appender/console_appender.h"
#include "appender/file_appender.h"
#include "formatter/line_formatter.h"
#include "formatter/table_formatter.h"

#include <string>
#include <list>
#include <cassert>

#include "logstream.h"

namespace hlog {

class Logger {
public:
    Logger * addAppender(AppenderI * appender) {
        if (appender)
            m_appenders.push_back(appender);

        return this;
    }

    void operator += (LogStream & logStream) {
        std::list<AppenderI *>::iterator iter = m_appenders.begin();
        for (; iter != m_appenders.end(); iter++) {
            (*iter)->log(logStream);
        }
    }
    
    static Logger * getInstance() {
        if (!m_instance)
            m_instance = new Logger();

        return m_instance;
    }

protected:
    Logger() {
    }

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

inline bool isCsv(const std::string & fileName) {
    static std::string csvStr("csv");
    std::string::size_type dotPos = fileName.rfind('.');
    if (dotPos != std::string::npos)
        return !csvStr.compare(0, 3, fileName, dotPos + 1, 3);
    return false;
}

inline Logger * addConsole() {
    LineFormatter * lineFormatter = new LineFormatter();
    return Logger::getInstance()->addAppender(new ConsoleAppender(lineFormatter));
}

inline Logger * addFile(const std::string & fileName) {
    FormatterI * formatter = nullptr;
    if (isCsv(fileName))
        formatter = new TableFormatter();
    else
        formatter = new LineFormatter();
    return Logger::getInstance()->addAppender(new FileAppender(fileName, formatter));
}

inline Logger * init() {
    return addConsole();
}

inline Logger * init(const std::string & fileName) {
    return addFile(fileName);
}

}
