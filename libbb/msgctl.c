#include <unistd.h>
#include <sys/syscall.h>
#include <linux/msg.h>

#include "ipc_nr.h"

int msgctl(int msqid, int cmd, struct msqid_ds *buf) {
  return syscall(__NR_msgctl, msqid, cmd, buf);
}
