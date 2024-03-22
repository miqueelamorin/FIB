#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>


#define N 10 

void print_vector (int *pid_h, int num_eltos) {
int i;
char buf[200];
buf[0]='\0';
char tmp[20];

for (i=0;i<num_eltos;i++) {
    sprintf(tmp, "%d ", pid_h[i]);
    strcat(buf,tmp);
}
strcat(buf, "\n");

write (1, buf, strlen(buf));
}

void f_sigusr1(int s) {

}

int main () {

int pid_h[N];	
int i = 0;
sigset_t mask;
struct sigaction trat;

sigemptyset(&mask);
sigaddset(&mask, SIGUSR1);
sigprocmask(SIG_BLOCK,&mask,NULL);

sigemptyset(&trat.sa_mask);
trat.sa_flags=0;
trat.sa_handler = f_sigusr1;

sigfillset(&mask);


sigdelset(&mask, SIGUSR1);

sigaction(SIGUSR1, &trat, NULL);

pid_h[0] = fork();

while ((i<N-1) && (pid_h[i] > 0)){
	i++;
	pid_h[i] = fork();
}

if (pid_h[i] > 0) {
	print_vector(pid_h,i+1);
	kill (pid_h[i], SIGUSR1);
	while (waitpid(-1, NULL, 0)>0);
} else {
	sigsuspend(&mask);
	print_vector(pid_h,i+1);
	if (i>0) {
		kill(pid_h[i-1],SIGUSR1)<0;
	}
}
}


