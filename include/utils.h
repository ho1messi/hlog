#pragma once

#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>


inline unsigned int getTid()
{
#ifdef _WIN32
    return GetCurrentThreadId();
#elif defined(__linux__)
    return static_cast<unsigned int>(::syscall(__NR_gettid));
#elif defined(__FreeBSD__)
    long tid;
    syscall(SYS_thr_self, &tid);
    return static_cast<unsigned int>(tid);
#elif defined(__rtems__)
    return rtems_task_self();
#elif defined(__APPLE__)
    uint64_t tid64;
    pthread_threadid_np(NULL, &tid64);
    return static_cast<unsigned int>(tid64);
#endif
}


