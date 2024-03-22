#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


main() {
int pid;

pid = fork ();
if (pid == 0) {
	close(1);
	open("f1", O_WRONLY|O_CREAT|O_APPEND, 0660);
	execlp("ls", "ls", (char *) 0);
} else {
	waitpid(-1, NULL, 0);
}

}
