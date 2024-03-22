#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Usage(){
    char buffer[128];
  	sprintf(buffer, "Usage: crear n hijos arg[n]\n");
  	write(1,buffer, strlen(buffer));
	exit(0);
}

void error(char *msg){
    perror(msg);
    exit(0);
}

void trat_alarm(int s)
{
}

void trat_sigusr1(int s)
{
    int n = alarm(0);
    exit(n);
}

int main(int argc, char *argv[]){
    if (argc < 2) Usage();

    struct sigaction sa;
    sa.sa_handler = &trat_alarm;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) < 0) error("sigaction");

    sa.sa_handler = &trat_sigusr1;
    if (sigaction(SIGUSR1, &sa, NULL) < 0) error("sigaction");

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGALRM);
    if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) error("sigprocmask");

    int nhijos = atoi(argv[1]);
    int pid[nhijos];
    char buffer[128];

    for (int i = 0; i < nhijos; ++i){
        switch(pid[i] = fork()){
            case 0:{
                alarm(3);
                sigfillset(&mask);
                sigdelset(&mask, SIGUSR1);
                sigdelset(&mask, SIGALRM);
                sigsuspend(&mask);
                sprintf(buffer, "%d: Timeout\n", getpid());
                write(1, buffer, strlen(buffer));
                exit(0);
            }
            case -1: error("error en el fork");
        }
    }

    for(int i = 0; i < nhijos; ++i){
        if (pid[i] % 2 == 0) {
            if (kill(pid[i], SIGUSR1) < 0) error("error en el kill");
        }
    }

    int status;
    int pidm;

    for(int i = 0; i < nhijos; ++i){
        if ((pidm = waitpid(-1, &status, 0)) < 0) error("waitpid");
        if (WIFEXITED(status) && (pidm % 2 == 0)){
            sprintf(buffer, "Hijo %d. Segundos restantes %d\n", pidm, WEXITSTATUS(status));
            write(1, buffer, strlen(buffer));
        }
    }
}
