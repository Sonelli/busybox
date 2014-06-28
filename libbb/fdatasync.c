#include <sys/syscall.h>

int fdatasync(int fd) {
  return syscall(__NR_fdatasync, fd);
}
