#include <unistd.h>
#include <sys/syscall.h>
#include <linux/shm.h>

// NOTE: IPC_INFO takes a struct shminfo64
int shmctl(int shmid, int cmd, struct shmid_ds *buf) {
  return syscall(__NR_shmctl, shmid, cmd, buf);
}
