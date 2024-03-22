#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void trat_sigpipe(int signum){
fprintf(stdout, "He recibido signal\n");
exit(1);
}

main(){
int fdpipe[2];
int ret;
struct sigaction trat;

sigemptyset(&trat.sa_mask);
trat.sa_flags = 0;
trat.sa_handler = trat_sigpipe;
sigaction(SIGPIPE, &trat, 0);
pipe(fdpipe);
//close(fdpipe[0]);
ret= write(fdpipe[1],"a",1);
if (ret<0) perror("Escribiendo pipe\n");

while(1);

}
