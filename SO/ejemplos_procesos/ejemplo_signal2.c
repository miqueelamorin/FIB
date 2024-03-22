#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int recibido = 0;

void mifunc(int signum){
char buf[80];

sprintf (buf, "sobrevivo al signal %d\n", signum);
write(1,buf,strlen(buf));

if (signum == SIGALRM) 
	recibido = 1;

}

int main(){
char buf[80];
struct sigaction trat;
sigset_t mask;
int i;

sigemptyset(&mask);
sigaddset(&mask,SIGINT);
sigprocmask(SIG_BLOCK,&mask,NULL);

trat.sa_flags = 0;
sigemptyset(&trat.sa_mask);
trat.sa_handler = mifunc;

sigaction (SIGINT, &trat,NULL);
sigaction (SIGALRM, &trat,NULL);

alarm(5);
while(!recibido);
sprintf(buf,"salgo del bucle\n");
write(1,buf,strlen(buf));

//sigfillset(&mask);
sigdelset(&mask,SIGINT);
sigsuspend(&mask);

sprintf(buf,"salgo elegantemente\n");
write(1,buf,strlen(buf));

}
