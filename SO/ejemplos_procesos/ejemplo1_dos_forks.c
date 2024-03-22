#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main () {

fork();
fork();
fork();
fprintf (stdout, "Mi pid es: %d\n", getpid());

}


