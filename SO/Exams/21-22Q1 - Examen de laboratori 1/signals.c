#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int recibido = 0;
int pid[10];
int count;
int i;

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

void tratamiento(int s){
    if (s == SIGUSR1) recibido = 1;
    if (s == SIGINT) alarm(0);
    if (s == SIGALRM) {
        for (i = 1; i < count; ++i) kill(pid[i], SIGKILL);
    }
}

int main(int argc, char *argv[]){
    if (argc < 2) Usage();

    count = argc;
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset (&mask, SIGUSR1);
    sigaddset (&mask, SIGINT);
    sigaddset (&mask, SIGALRM);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    struct sigaction sa;
    sa.sa_handler = &tratamiento;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGALRM, &sa, NULL);

    for (i = 1; i < argc; ++i){
        switch(pid[i] = fork()){
            case 0: {
                sigprocmask(SIG_UNBLOCK, &mask, NULL);
                while(!recibido);
                char buffer[128];
                sprintf(buffer, "%d: He tratado: %s\n", getpid(), argv[i]);
                write(1,buffer, strlen(buffer));
                exit(i);
                }
            case -1: error("error en el fork");
        }
    }

    int result;
    char buffer[128];

    i = 1;
    alarm (2);
    sigfillset(&mask);
    sigdelset (&mask, SIGINT);
    sigdelset (&mask, SIGALRM);
    sigsuspend(&mask);

    while (i < argc){
        sigsuspend(&mask);
        sprintf(buffer, "Salimos de la espera del hijo %d\n", pid[i]);
        write(1, buffer, strlen(buffer));
        kill(pid[i], SIGUSR1);
        ++i;
    }

    int pidm;
    for(i = 1; i < argc; ++i){
        if ((pidm = waitpid(-1, &result, 0)) < 0) error("waitpid");
        if (WIFEXITED(result)) sprintf(buffer, "Termina proceso %d por exit con resultado %d\n", pidm, WEXITSTATUS(result));
        else if (WIFSIGNALED(result)) sprintf(buffer, "Termina proceso %d con signal %d\n", pidm, WTERMSIG(result));
        write(1, buffer, strlen(buffer));
    }
}
