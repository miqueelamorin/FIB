#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

main(){
	int pidh[2];
	int pipe1[2];
	char buffer[256];
	char c;
	int i,ret, valor;
	

	pipe(pipe1);
	pidh[0] = fork();
	switch (pidh[0]){
	case -1: perror("Error en el Fork\n");
		 exit(1);
	case 0: dup2(pipe1[1], 1);
		close(pipe1[1]);
		close(pipe1[0]);
		execlp("ls","ls", "-l", (char *)0);
		perror("mutando al ls");
		exit(0);
	}
	close(pipe1[1]);

	pidh[1] = fork();
	switch (pidh[1]){
	case -1: perror("Error en el Fork\n");
		 exit(1);
	case 0: dup2(pipe1[0],0); close(pipe1[0]);
		execlp("wc","wc", "-l", (char *)0);
		exit(0);
	}
close(pipe1[0]);
while ((ret= waitpid(-1,&valor,0))>0){
	sprintf(buffer, "Hijo %d acaba la ejecucion\n", ret);
	write(1,buffer,strlen(buffer));
}
}
