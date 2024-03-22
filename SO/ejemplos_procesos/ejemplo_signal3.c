#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int recibido = 0;

void mifunc(int signum){
char buf[80];

sprintf (buf, "sobrevivo al signal %d\n", signum);
write(1,buf,strlen(buf));

recibido = 1;

}

int main(){
char buf[80];
int ret;
struct sigaction trat;
trat.sa_flags=0;
sigemptyset(&trat.sa_mask);
trat.sa_handler = mifunc;

sigaction (SIGINT, &trat, NULL);

ret=fork();
switch (ret) {
case 0: sprintf(buf,"Pid del hijo: %d\n",getpid());
	write (1,buf, strlen(buf));
	break;
case -1: perror("Error creando proceso hijo");
	exit(1); 
default:
	sprintf(buf,"Pid del padre: %d\n",getpid());
	write (1,buf, strlen(buf));

	trat.sa_handler=SIG_DFL;
	//sigaction (SIGINT, &trat, NULL);


}

while (!recibido);

sprintf(buf,"Soy %d y salgo elegantemente\n",getpid());
write(1,buf,strlen(buf));

}
