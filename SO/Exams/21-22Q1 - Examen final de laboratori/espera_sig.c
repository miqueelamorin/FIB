#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void trat(int signal){
	char buff[256];
	sprintf(buff, "Signal recibido = %d\n", signal);
	write(1, &buff, strlen(buff));
	if (signal == SIGINT) exit(1);
	if (signal == SIGUSR1) exit(2);
	if (signal == SIGUSR2) exit(3);	
}

int main(int argc, char* argv[]){
	sigset_t m;
	sigemptyset(&m);
	sigaddset(&m, SIGINT);
	sigaddset(&m, SIGUSR1);
	sigaddset(&m, SIGUSR2);
	sigprocmask(SIG_BLOCK, &m, NULL);	//bloquejem 3 signals
	
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &trat;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);	//sigaction dels 3 signals
	
	sigfillset(&m);
	sigdelset(&m, SIGINT);
	sigdelset(&m, SIGUSR1);
	sigdelset(&m, SIGUSR2);
	sigsuspend(&m);
}
