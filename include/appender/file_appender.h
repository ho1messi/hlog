#pragma once

#include "../appenderI.h"

#include <string>

class FileAppender : public AppenderI {
public:
    FileAppender(std::string fileName) {
    }

    void log(LogStream & logStream) {

    }
};
