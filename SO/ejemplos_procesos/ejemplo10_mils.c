#include <stdlib.h>
#include <unistd.h>
 #include <stdio.h>
  #include <sys/types.h>
       #include <sys/wait.h>

int main() {
int ret,status;

ret = fork();

if (ret == 0) {
	execlp("ls", "ls","-l", (char *) 0);
	perror("Error ejecutando ls");
}
waitpid(ret, &status, 0);
}
