#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /* overwrite process name (shown in ps) by whatever we want */
    memcpy(argv[0], "/bin/fullkekk", strlen("/bin/fullkekk" + 1));

    /* fork and stop master to reattach to init */
    int p = fork();
    if (p) {
         exit(0);
    }

    while (1) {
        sleep(1);
    }

    return 0;
}
