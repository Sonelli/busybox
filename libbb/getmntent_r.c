/* from dietlibc's getmntent, adapted for _r */

#include <stdio.h>
#include <stdlib.h>
#include <mntent.h>
#include <string.h>

struct mntent *getmntent_r(FILE *filep, struct mntent *mntbuf, char *buf, int buflen) {
  do {
    char *tmp=buf;
    int num;
    if (!fgets(buf,buflen,filep)) return 0;
/* "/dev/ide/host0/bus0/target0/lun0/part2 / reiserfs defaults 1 1" */
    for (num=0; num<6; ++num) {
      switch (num) {
      case 0: mntbuf->mnt_fsname=tmp; break;
      case 1: mntbuf->mnt_dir=tmp; break;
      case 2: mntbuf->mnt_type=tmp; break;
      case 3: mntbuf->mnt_opts=tmp; break;
      case 4: mntbuf->mnt_freq=strtol(tmp,&tmp,0); if (*tmp!=' ' && *tmp!='\t') continue; break;
      case 5: mntbuf->mnt_passno=strtol(tmp,&tmp,0); if (*tmp=='\n') return mntbuf; break;
      }
      while (*tmp && *tmp!=' ' && *tmp!='\n' && *tmp!='\t') ++tmp;
      if (*tmp) {
	if (num<4) *tmp++=0;
	while (*tmp==' ' || *tmp=='\t') ++tmp;
      } else
	continue;
    }
  } while (1);
}
