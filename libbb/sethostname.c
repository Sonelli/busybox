#include <unistd.h>
#include <sys/syscall.h>

int sethostname(const char *name, size_t len) {
  return syscall(__NR_sethostname, name, len);
}

