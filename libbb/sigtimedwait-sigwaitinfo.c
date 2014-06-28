/* originally from dietlibc, under the GPL 2 license. modified for bionic/android */

#include <signal.h>
#include <sys/syscall.h>
#include <linux/time.h>

int __rt_sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *ts, long nr) {
  return syscall(__NR_rt_sigtimedwait, set, info, ts, nr);
}

int sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *ts) {
  return __rt_sigtimedwait(set,info,ts,_NSIG/8);
}

int sigwaitinfo(const sigset_t *set, siginfo_t *info) {
  return sigtimedwait(set, info, NULL);
}
