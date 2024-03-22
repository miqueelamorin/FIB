#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

void error_y_exit(char *msg,int exit_status)
{
    perror(msg);
    exit(exit_status);
}

int seg=0;
void trat_signals(int s)
{
    char buff[256];
    if (s == SIGALRM) seg=seg+1;
    else if (s == SIGUSR1) {
        seg = 0;
        sprintf(buff, "Valor actual: %d segundos\n",seg);
        write(1, buff, strlen(buff));
    }
    else if (s == SIGUSR2) {
        sprintf(buff, "Valor actual: %d segundos\n",seg);
        write(1, buff, strlen(buff));
    }
}

int main (int argc,char * argv[])
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    sigprocmask(SIG_BLOCK,&mask, NULL);

    /* REPROGRAMAMOS EL SIGNAL SIGALRM */
    sa.sa_handler = &trat_signals;
    sa.sa_flags = SA_RESETHAND;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) < 0 || sigaction(SIGUSR1, &sa, NULL) < 0 || sigaction(SIGUSR2, &sa, NULL) < 0) error_y_exit("sigaction", 1);

    char buff[256];
    sprintf(buff, "pid=%d\n", getpid());
    write(1, buff, strlen(buff));

    while (1)
    {
    	alarm(1);
    	sigfillset(&mask);
        sigdelset(&mask, SIGALRM);
    	sigdelset(&mask, SIGINT);
        sigdelset(&mask, SIGUSR1);
        sigdelset(&mask, SIGUSR2);
        sigsuspend(&mask);
    }
    exit(1);
}
