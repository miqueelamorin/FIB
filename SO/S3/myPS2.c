#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void error_y_exit(char *msg, int exit_status) {
	perror(msg);
	exit(exit_status);
}

int main(int argc, char *argv[]) {
    char buf[80];

    sprintf(buf, "Soy el proceso: %d\n", getpid());
	write(1, buf, strlen(buf));

    for (int i = 1; i < argc; i++){
        int pid = fork();
        if (pid < 0) error_y_exit("Error en fork", 1);
        else if (pid == 0){
            sprintf(buf, "Soy el proceso: %d\n", getpid());
            write(1, buf, strlen(buf));
            sprintf(buf, "Usuario: %s\n", argv[i]);
            write(1, buf, strlen(buf));
            exit(0);
        }
        waitpid(-1, NULL, 0);
    }
}
