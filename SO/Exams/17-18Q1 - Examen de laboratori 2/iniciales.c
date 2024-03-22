#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Usage(){
    char buffer[128];
  	sprintf(buffer, "Usage: iniciales (nombre del archivo)\n");
  	write(1,buffer, strlen(buffer));
	exit(0);
}

void error(char *msg){
    perror(msg);
    exit(0);
}



int main(int argc, char* argv[]){
    if (argc < 2) Usage();
    else {
        execlp("mkfile")
    }
}
