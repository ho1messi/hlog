#pragma once

#include "../formatterI.h"
#include "../serverity.h"

#include <sstream>
#include <iomanip>
#include <cstddef>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>

namespace hlog {

class LineFormatter : public FormatterI {
public:
    LineFormatter() {

    }

    ~LineFormatter() {

    }

    const char * format(LogStream & logStream) {
        std::stringstream ss;

        std::time_t rawTime;
        std::time(&rawTime);
        std::tm * time = std::localtime(&rawTime);
        timeval tv;
        gettimeofday(&tv, NULL);

        ss << time->tm_year + 1900 << '-';
        ss << std::setw(2) << std::setfill('0') << time->tm_mon + 1 << '-';
        ss << std::setw(2) << std::setfill('0') << time->tm_mday << ' ';
        ss << std::setw(2) << std::setfill('0') << time->tm_hour << ':';
        ss << std::setw(2) << std::setfill('0') << time->tm_min << ':';
        ss << std::setw(2) << std::setfill('0') << time->tm_sec << '.';
        ss << std::setw(3) << std::setfill('0') << tv.tv_usec / 1000 << ' ';

        ss << std::setw(5) << std::setfill(' ') << ServerityStr[logStream.getServerity()] << ' ';
        ss << '[' << logStream.getTid() << ']' << ' ';
        ss << '[' << logStream.getFunc() << '@' << logStream.getLine() << ']' << ' ';
        ss << logStream.getMessage();

        m_formatStr = ss.str();
        return m_formatStr.c_str();
    }

private:
    std::string m_formatStr;

};

}
