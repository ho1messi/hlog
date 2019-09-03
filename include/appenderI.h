#pragma once

#include "logstream.h"

namespace hlog {

class AppenderI {
public:
    virtual ~AppenderI() {
    }

    virtual void log(LogStream & logStream) = 0;
};

}
