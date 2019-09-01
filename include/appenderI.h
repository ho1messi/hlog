#pragma once

#include "logstream.h"

class AppenderI {
public:
    virtual ~AppenderI() {
    }

    virtual void log(LogStream & logStream) = 0;
};
