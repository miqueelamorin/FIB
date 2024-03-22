#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
int fd[2];
int pidh,n;
char c;

pipe(fd);

pidh=fork();

switch(pidh){
	case -1: 
		perror("Error creando fork");
		exit(1);
		
	case 0: 
		close(fd[1]);
		while ((n=read(fd[0],&c,sizeof(c)))>0){
			write(1,&c,n);
		}
		write(1,"Fin hijo\n", 10);
		exit(0);
		
	default : 
		close(fd[0]);
		 while ((n=read(0,&c,sizeof(c)))>0){
			write(fd[1],&c,n);
		}
		close(fd[1]);
		waitpid(-1,NULL,0);
		write(1,"Fin padre\n", 9);
		exit(0);
	}

}
