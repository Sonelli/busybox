#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <linux/shm.h>
#include <linux/msg.h>
#include <linux/sem.h>

#include "ipc_nr.h"

int shmget(key_t key, size_t size, int shmflg) {
  return syscall(__NR_shmget, key, size, shmflg);
}

int msgget(key_t key, int msgflg) {
  return syscall(__NR_msgget, key, msgflg);
}

int semget(key_t key, int nsems, int semflg) {
  return syscall(__NR_semget, key, nsems, semflg);
}
