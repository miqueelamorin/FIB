#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void usage(){
    char buffer[128];
    sprintf(buffer, "Usage\n");
    write(1,buffer,strlen(buffer));
    exit(1);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(1);
}

void tratamiento(){
	perror("Limite tiempo");
	exit(1);
}

int main(int argc, char *argv[]){
    if (argc != 5) usage(); 
    sigset_t m;
    struct sigaction sa;
    
    sigemptyset(&m);
    sigaddset(&m, SIGALRM);
    sigprocmask(SIG_BLOCK,&m,NULL);
    
    sa.sa_handler = tratamiento;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
    sigprocmask(SIG_UNBLOCK,&m,NULL);
    
    alarm(atoi(argv[3]));
    
    int semilla = atoi(argv[2]);
    for (int i = 0; i < atoi(argv[1]); ++i){
        int pid = fork();
        if (pid == 0) {
            char sem[2];
            sprintf(sem, "%d", semilla);
            execlp("./dummy", "dummy", sem, (char*)NULL);
            error_y_exit("Error en el execlp");
        }
        else if (pid < 0) error_y_exit("Error en el fork");
        else {
            int stat;
            waitpid(pid, &stat, 0);
            if (WIFEXITED(stat)) semilla += WEXITSTATUS(stat);
        }
    }
    int fd = open(argv[4], O_WRONLY|O_CREAT|O_TRUNC, 600);
    char buff[128];
    sprintf(buff, "El total es %d\n", semilla);
    write(fd, buff, strlen(buff));
    exit(0);
}
