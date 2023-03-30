#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int sleep(int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    nanosleep(&req, &rem);
    return rem.tv_sec;
}
