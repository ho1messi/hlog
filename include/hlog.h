#pragma once

#include "logger.h"
#include "logstream.h"

namespace hlog {

#define HLOGI (*hlog::Logger::getInstance()) += hlog::LogStream(hlog::Info, __func__, __LINE__)
#define HLOGD (*hlog::Logger::getInstance()) += hlog::LogStream(hlog::Debug, __func__, __LINE__)
#define HLOGE (*hlog::Logger::getInstance()) += hlog::LogStream(hlog::Error, __func__, __LINE__)

}
