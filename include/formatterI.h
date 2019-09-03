#pragma once

#include "logstream.h"

#include <string>

namespace hlog {

class FormatterI {
public:
    virtual ~FormatterI() {

    }

    virtual const char * format(LogStream & logStream) = 0;

};

}
