#pragma once

#include "logger.h"
#include "logstream.h"


#define HLOGI (*Logger::getInstance()) += LogStream(Info)
#define HLOGD (*Logger::getInstance()) += LogStream(Debug)
#define HLOGE (*Logger::getInstance()) += LogStream(Error)
