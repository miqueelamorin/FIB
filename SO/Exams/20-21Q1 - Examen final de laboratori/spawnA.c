void usage(){
    char buffer[128];
    sprintf(buffer, "Usage");
    write(1,buffer,strlen(buffer));
    exit(1);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    if (argc != 2) usage(); 
    for (int i = 0; i < atoi(argv[1]); ++i){
        int pid = fork();
        if (pid == 0){
            execlp("./hijo1", "hijo1", NULL);
            error_y_exit("Error en el execlp");
        }
        else if (pid < 0) error_y_exit("Error en el fork");
    }
    while(waitpid(-1, NULL, 0) > 0){
        int pid = fork();
        if (pid == 0){
            execlp("./hijo1", "hijo1", NULL);
            error_y_exit("Error en el execlp");
        }
    }
}