#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

main(int argc, char *argv[]){
char buffer[128];
int ret;
int nfiles;
int i = 1;

if (argc > 1){
	close(0);
	ret=open (argv[i], O_RDONLY);
	if (ret < 0) {
		perror("Error abriendo fichero");
		exit(1);
	}
	nfiles = argc-1;
} else {
	nfiles = 1;
}

while (i<=nfiles) {

	while ((ret = read(0,buffer, sizeof(buffer))) > 0){
		ret = write (1,buffer, ret);
		if (ret < 0) {
			perror("Error escribiendo en entrada estandar");
			exit(1);
		}
	}
	if (ret < 0) {
		perror("Error leyendo de entrada estandar");
		exit(1);
	}
	i++;
	if (i <= nfiles) {
		close(0);
		ret=open (argv[i], O_RDONLY);
		if (ret < 0) {
			perror("Error abriendo fichero");
			exit(1);
		}
	}	
}

}
