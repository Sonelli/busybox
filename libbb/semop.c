#include <unistd.h>
#include <sys/syscall.h>
#include <linux/sem.h>
#include "ipc_nr.h"

int semop(int semid, struct sembuf *sops, unsigned nsops) {
  return syscall(__NR_semop, semid, sops, nsops);
}

