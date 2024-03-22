#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int pipe = open("mis_eventos", O_RDONLY, 0);
	char buff[265];
	while(read(pipe, buff, sizeof(char)) > 0){
		write(1, buff, sizeof(char));
	}
	close(pipe);
}
