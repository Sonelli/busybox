#include <signal.h>
#include "sigisemptyset.h"

int sigisemptyset(sigset_t *set) {
    unsigned long *local_set = (unsigned long *)set;
    return *local_set == 0;
}
