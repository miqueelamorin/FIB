#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void mifunc(int signum){
	char buf[80];

	sprintf (buf, "sobrevivo al signal %d\n", signum);
	write(1,buf,strlen(buf));
	exit(1);
}

int main(){
struct sigaction trat;
int *p = 0;
sigset_t mask;
int i;

sigemptyset(&mask);
sigaddset(&mask, SIGINT);
sigprocmask(SIG_SETMASK,&mask,NULL);

trat.sa_flags=0;
sigemptyset(&trat.sa_mask);
trat.sa_handler=mifunc;

sigaction (SIGINT, &trat, NULL);
sigaction (SIGSEGV, &trat, NULL);

//*p=3; // provoca un SIGSEGV
i=0;
while (1){
	if (i<400000){
	    fprintf(stdout, "Estoy aqui: %d\n",i);
    }
	if (i==400000){
	    fprintf(stdout, "Voy a desbloquear: %d\n",i);
		sigprocmask(SIG_UNBLOCK,&mask,NULL);
	}
	i++;
}
}
