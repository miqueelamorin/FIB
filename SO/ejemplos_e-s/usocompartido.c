#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


main() {
int pid,fd1,fd2,ret;
char buf[80];

fd1=open("f1", O_WRONLY|O_CREAT|O_TRUNC, 0660);
pid = fork ();
fd2=open("f2", O_RDONLY); 

while ((ret = read(fd2,buf,sizeof(buf)))>0){
	write(fd1,buf,ret);
}

}
