#include <sys/syscall.h>

int pivot_root(const char *new_root, const char *put_old) {
  return syscall(__NR_pivot_root, new_root, put_old);
}
