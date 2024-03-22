#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void trat(){
}

int main(int argc, char* argv[]){
	sigset_t m;
	sigemptyset(&m);
	sigaddset(&m, SIGALRM);
	sigprocmask(SIG_BLOCK, &m, NULL);	//bloquejem 3 signals
	
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &trat;
	sigaction(SIGALRM, &sa, NULL);	//sigaction dels 3 signals
	
	sigfillset(&m);
	sigdelset(&m, SIGALRM);
	
	int fd = open("texto.txt", O_RDONLY, 0);
	int pipe = open("mis_eventos", O_WRONLY, 0);
	char buff[265];
	while(read(fd, buff, sizeof(char)) > 0){
		write(pipe, buff, sizeof(char));
		alarm(1);
		sigsuspend(&m);
	}
	close(fd);
	close(pipe);
}
