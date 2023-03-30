// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	if (fd < 0) {
        errno = EBADF;
        return (off_t)-1;
    }

    if ((whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END) ||
        (offset < 0 && whence == SEEK_SET)) {
        errno = EINVAL;
        return (off_t)-1;
    }

	off_t ret = syscall(__NR_lseek, fd, offset, whence);

    if (ret < 0) {
		return (off_t)-1;
	}

    return ret;
}
