#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void error_y_exit(char* msg,int exitStatus) {
	perror(msg);
	exit(exitStatus);
}

void muta_cat() {

}

int main() {
	char buf[256];
	int pf[2];
	if(pipe(pf) == -1) error_y_exit("ha fallado la creacion\n",1);

	if(fork() == 0) {
		dup2(pf[0],0);
		close(pf[0]);
        close(pf[1]);
		execlp("cat","cat",NULL);
        error_y_exit("fallo en el execlp\n",1);
	}

	else {
		close(pf[0]);
		sprintf(buf,"Inicio\n");
		write(pf[1],buf,strlen(buf));
		close(pf[1]);
		waitpid(-1,NULL,0);
		sprintf(buf,"Fin\n");
		write(1,buf,strlen(buf));
	}
}