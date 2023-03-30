#include <unistd.h>
#include <string.h>
#include <errno.h>

int puts(const char *s) {
    if (s == NULL) {
        return -1;
    }

    int ct = 0;
    while (*s != '\0') {
        int ret = write(1, s, 1);
        s++;

        if (ret != 1) {
            ct = -1;
            return ct;
        }
        ct++;
    }

    int ret = write(1, "\n", 1);
    if (ret != 1) {
        ct = -1;
        return ct;
    }

    return ct++;
}