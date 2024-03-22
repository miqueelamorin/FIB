#include <unistd.h>
#include <stdio.h>

int main () {
int pidh;
pidh=fork();

if (pidh == 0) {
	fprintf (stdout, "Soy el hijo y Mi pid es: %d\n", getpid());
} else {
	fprintf (stdout, "Soy el padre y Mi pid es: %d\n", getpid());

}

}


