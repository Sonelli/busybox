#include <unistd.h>
#include <sys/syscall.h>
#include <linux/sem.h>

int semop(int semid, struct sembuf *sops, unsigned nsops) {
  return syscall(__NR_semop, semid, sops, nsops);
}

