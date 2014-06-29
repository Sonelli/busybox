#ifndef IPC_NR_H
#define IPC_NR_H

#ifdef __ANDROID__ && i386
// these aren't defined on arch-x86
// this comes from linux kernel include/uapi/asm-generic/unistd.h

 #ifndef __NR_shmget
 #define __NR_shmget 194
 #endif

 #ifndef __NR_msgget
 #define __NR_msgget 186
 #endif

 #ifndef __NR_semget
 #define __NR_semget 190
 #endif

 #ifndef __NR_msgctl
 #define __NR_msgctl 187
 #endif

 #ifndef __NR_semctl
 #define __NR_semctl 191
 #endif

 #ifndef __NR_semop
 #define __NR_semop 193
 #endif

 #ifndef __NR_shmctl
 #define __NR_shmctl 195
 #endif

 #ifndef __NR_shmdt
 #define __NR_shmdt 197
 #endif

 #ifndef __NR_shmat
 #define __NR_shmat 196
 #endif
#endif // __ANDROID__ and i386

#endif
