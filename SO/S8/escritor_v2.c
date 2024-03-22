#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	char buff[80];
	int fifo;

	while((fifo = open("bridge", O_WRONLY | O_NONBLOCK)) == -1 && errno == ENXIO){
        sprintf(buff, "Esperando un lector...\n");
		write(1, buff, strlen(buff));
		sleep(3);
    }

	sprintf(buff, "Lector encontrado!\n");
	write(1, buff, strlen(buff));

	char c;
	while(read(0, &c, sizeof(char)) > 0)
	{
		write(fifo, &c, sizeof(char));
	}
}

