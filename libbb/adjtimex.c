#include <time.h>
#include <linux/timex.h>
#include <sys/syscall.h>

int adjtimex(struct timex *buf) {
  return syscall(__NR_adjtimex, buf);
}

