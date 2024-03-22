#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Usage(){
    char buffer[128];
  	sprintf(buffer, "Usage: jerarquia file1, file2,...\n");
  	write(1,buffer, strlen(buffer));
	exit(0);
}

void error(char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){
    if (argc <= 1) Usage();
    else {
        int pid[argc];
        int i;
        for (i = 1; i < argc; ++i){
            switch(pid[i] = fork()){
                case 0: {
                    char buffer[128];
                    sprintf(buffer, "%d: He tratado: %s\n", getpid(), argv[i]);
                    write(1,buffer, strlen(buffer));
                        for (int j = 0; j < 3; ++j){
                            if (fork() == 0){
                                char name[80];
                                strcpy(name, argv[i]); /* copy name into the new var */
                                strcat(name, "_sin_repes"); /* add the extension */

                                if (j == 0) execlp ("wc", "wc", "-l", argv[i], NULL);
                                else if (j == 1) execlp ("sort", "sort", "-u", argv[i], "-o", name, NULL);
                                else execlp ("wc", "wc", "-l", name, NULL);
                                exit(0);
                            }
                            waitpid(-1 , 0, 0);
                        }
                    exit(i);
                }
                case -1: error("error en el fork");
            }
        }
        int result;
        i = 1;
        char buffer[128];
        while (waitpid(pid[i] , &result, 0) > 0){
            if (WIFEXITED(result)){
                    sprintf(buffer, "Termina proceso %d con resultado %d\n", pid[i], WEXITSTATUS(result));
                    write(1, buffer, strlen(buffer));
                    ++i;
            }
        }
    }
}
