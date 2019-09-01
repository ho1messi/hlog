#pragma once

#include "../appenderI.h"

#include <iostream>

class ConsoleAppender : public AppenderI {
public:
    ConsoleAppender() {

    }

    virtual ~ConsoleAppender() {
    }

    void log(LogStream & logStream) {
        std::cout << logStream.getMessage().str() << std::endl;
    }
};
