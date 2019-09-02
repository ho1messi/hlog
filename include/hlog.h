#pragma once

#include "logger.h"
#include "logstream.h"


#define HLOGI (*Logger::getInstance()) += LogStream(Info, __func__, __LINE__)
#define HLOGD (*Logger::getInstance()) += LogStream(Debug, __func__, __LINE__)
#define HLOGE (*Logger::getInstance()) += LogStream(Error, __func__, __LINE__)
