#pragma once

namespace hlog {

enum Serverity {
    Info,
    Debug,
    Error,
};

const char * ServerityStr[] = {
    "INFO",
    "DEBUG",
    "ERROR",
};

}
