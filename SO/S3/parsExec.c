#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void error_y_exit(char *msg, int exit_status) {
	perror(msg);
	exit(exit_status);
}

int main(int argc, char* argv[]) {
    for (int i = 0; i < 4; ++i) {
        int pid = fork();
        char buff[80];
        if (pid < 0) error_y_exit("Error en fork", 1);
        else if (pid == 0){
            if (i == 0) execlp("./listaParametros", "listaParametros", "a", "b", (char*)0);
            if (i == 1) execlp("./listaParametros", "listaParametros", (char*)0);
            if (i == 2) execlp("./listaParametros", "listaParametros", "25", "4", (char*)0);
            if (i == 3) execlp("./listaParametros", "listaParametros", "1024", "hola", "adios", (char*)0);
            exit(0);
        }
    }
    while (waitpid(-1, NULL, 0) > 0);
}
