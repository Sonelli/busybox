#include <sys/sysinfo.h>
#include <sys/syscall.h>

int sysinfo(struct sysinfo *info) {
  return syscall(__NR_sysinfo, info);
}

