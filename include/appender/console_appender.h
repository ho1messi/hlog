#pragma once

#include "../appenderI.h"
#include "../formatterI.h"
#include "../formatter/line_formatter.h"

#include <iostream>

namespace hlog {

class ConsoleAppender : public AppenderI {
public:
    ConsoleAppender(FormatterI * formatter) :
    m_formatter(formatter) {
    }

    virtual ~ConsoleAppender() {
    }

    void log(LogStream & logStream) {
        std::cout << m_formatter->format(logStream) << std::endl;
    }

private:
    FormatterI * m_formatter;
};

}
