#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

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

int main () {

int pid_h[N];	
int i = 0;

pid_h[0] = fork();

while ((i<N-1) && (pid_h[i] > 0)){
	waitpid(-1, NULL,0);
	i++;
	pid_h[i] = fork();
}

if (pid_h[i] > 0) waitpid(-1, NULL,0);
		
print_vector(pid_h,i+1);

}


