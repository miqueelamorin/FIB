#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define N 3

void print_vector (int *pid_h, int num_eltos) {

char buf[80];
buf[0]='\0';

for (int i=0;i<num_eltos;i++) {
    sprintf(buf, "%s %d\n", buf, pid_h[i]);
}

sprintf(buf, "%s\n", buf);

write (1, buf, strlen(buf));
}

int main () {

int pid_h[N];	
int i = 0;

pid_h[0] = fork();

while ((i<N-1) && (pid_h[i] > 0)){
	i++;
	pid_h[i] = fork();
}
		
print_vector(pid_h,i+1);

}


