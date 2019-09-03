#pragma once

#include "../appenderI.h"
#include "../formatterI.h"

#include <string>
#include <iostream>
#include <fstream>

namespace hlog {

class FileAppender : public AppenderI {
public:
    FileAppender(const std::string & fileName, FormatterI * formatter) :
    m_formatter(formatter) {
        m_fileStream.open(fileName, std::ios::app | std::ios::out);
    }

    virtual ~FileAppender() {
        m_fileStream.close();
    }

    void log(LogStream & logStream) {
        m_fileStream << m_formatter->format(logStream) << std::endl;
    }

private:
    FormatterI * m_formatter;
    std::fstream m_fileStream;
};

}
