#pragma once

#include "../appenderI.h"
#include "../formatter/line_formatter.h"

#include <iostream>

class ConsoleAppender : public AppenderI {
public:
    ConsoleAppender() {
        m_formatter = new LineFormatter();
    }

    virtual ~ConsoleAppender() {
    }

    void log(LogStream & logStream) {
        std::cout << m_formatter->format(logStream) << std::endl;
    }

private:
    FormatterI * m_formatter;
};
