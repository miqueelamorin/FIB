#include <unistd.h>
#include <stdio.h>

int main () {

int i;

for (i=0; i<3; i++){
	fork();
}
fprintf (stdout, "Mi pid es: %d\n", getpid());

}


