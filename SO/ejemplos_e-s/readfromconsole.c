#include <unistd.h>
#include <fcntl.h>

main() {
char buffer[10];
int ret,fd;

ret = read(0, buffer, sizeof(buffer));

write(1,buffer,ret);

write(1,"\n**********\n",12);

ret = read(0, buffer, sizeof(buffer));

write(1,buffer,ret);
write(1,"\n**********\n",12);



}
