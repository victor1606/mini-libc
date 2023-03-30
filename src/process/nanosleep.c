#include <time.h>
#include <errno.h>
#include <internal/syscall.h>


int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = -1;
    
    while(1) {
        ret = syscall(__NR_nanosleep, req, rem);
        if (ret == -1 && errno == EINTR) {
            continue;
        } else {
            break;
        }
    }
    
    return ret;
}