#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	int *mem = malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i){
		int pid = fork();
		if (pid == 0) execlp("./espera_sig", "espera_sig", NULL);
		else {
			mem[i] = pid;
			char buff[256];
			sprintf(buff, "PID Hijo = %d\n", pid);
			write(1, &buff, strlen(buff));
		}
	}
	
	int fd = open("exit_status.txt", O_WRONLY|O_CREAT|O_TRUNC, 640);
	int stat, ret;
	char buff[256];
	
	while((ret=waitpid(-1, &stat, 0)) > 0){
		if (WIFEXITED(stat)) {
			int i;
			for (i = 0; i < n; ++i) if (mem[i] == ret) break;
			lseek(fd, 8*i, SEEK_SET);
			sprintf(buff, "%d %d ", ret, WEXITSTATUS(stat));
			write(fd, buff, strlen(buff));
		}
	}
	sprintf(buff, "\n");
	write(fd, buff, strlen(buff));
}
