#include <fcntl.h>
#include <sys/syscall.h>
#include <stdio.h>

ssize_t readahead(int fd, off64_t offset, size_t count) {
  return syscall(__NR_readahead, fd, offset, count);
}
