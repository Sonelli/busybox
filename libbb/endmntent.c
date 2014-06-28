/* originally from dietlibc, under the GPL version 2 */

#include <stdio.h>
#include <mntent.h>

int endmntent(FILE *filep) {
  fclose(filep);
  return 1;
}

