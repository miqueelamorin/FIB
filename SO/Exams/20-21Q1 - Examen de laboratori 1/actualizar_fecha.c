#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Usage(){
    char buffer[128];
  	sprintf(buffer, "Usage: actualizar_fecha fichero_1 .. fichero_n\n");
  	write(1,buffer, strlen(buffer));
	exit(0);
}

void error(char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){
    if (argc < 2) Usage();

    int pids[6];
    char buffer[128];
    for (int i = 1; i < argc; ++i){
        switch (pids[i] = fork()){
            case 0: {
                execlp("touch", "touch", argv[i], NULL);
                error ("error en execlp");
            }
            case -1: error("error en el fork");
        }
    }

    int pid = 0;
    while ((pid = waitpid(-1,NULL,0)) > 0){
        int j = 1;
        while (pid != pids[j]) j++;

        sprintf(buffer, "Fecha %s actualizada por %d\n", argv[j], pid);
        write(1,buffer, strlen(buffer));
    }
}
