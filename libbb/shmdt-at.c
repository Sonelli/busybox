#include <unistd.h>
#include <sys/syscall.h>
#include <linux/shm.h>
#include "ipc_nr.h"

int shmdt(const void *shmaddr) {
  return syscall(__NR_shmdt, shmaddr);
}

void *shmat(int shmid, const void *shmaddr, int shmflg) {
  return (void *)syscall(__NR_shmat, shmid, shmaddr, shmflg);
}
