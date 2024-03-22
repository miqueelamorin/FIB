#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main ()
{

     fprintf(stdout, "EJEMPLO 7 PID: %d\n", getpid());
     //execlp ("ls", "ls","-l", (char *) 0);
     execlp ("./ejemplo6_par_wait",  "ejemplo6_par_wait",(char *) 0);
     //execlp ("./ls", "ls","-l", (char *) 0); /* descomentar para forzar un exec con error */
     fprintf(stdout, "Despues del exec\n");
     perror ("Error executing execlp");

    

}
