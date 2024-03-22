#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void error_y_exit(char *msg, int exit_status) {
	perror(msg);
	exit(exit_status);
}

int main(int argc, char *argv[]) {
    char buf[80];
    int pid = fork();

    if (pid < 0) error_y_exit("Error en fork", 1);

    sprintf(buf, "Soy el proceso: %d\n", getpid());
	write(1, buf, strlen(buf));

    if (pid == 0){
		sprintf(buf, "Usuario: %s\n", argv[1]);
		write(1, buf, strlen(buf));
    }

    while(1);
}
