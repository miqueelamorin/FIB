#include <signal.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>

void mifunc(int signum){ 
    char buf[80];
    sprintf (buf, "sobrevivo al signal %d\n", signum);
    write(1,buf,strlen(buf));
    sprintf (buf, "muero elegantemente\n");
    write(1,buf,strlen(buf));
    exit(1);
}

int main(){
struct sigaction trat;
int i;

trat.sa_flags=0;
sigemptyset(&trat.sa_mask);
trat.sa_handler=mifunc;
//trat.sa_handler=SIG_IGN;

sigaction (SIGINT, &trat, NULL);

i=0;
while (1){
    fprintf(stdout, "Estoy aqui:%d\n",i);
	i++;
}
}
