#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
/* ESTE PROCESO PROGRAMA UN TEMPORIZADOR PARA  DENTRO DE 5 SEGUNDOS Y SE BLOQUEA A ESPERAR QUE LLEGUE */
/* LA ACCION POR DEFECTO DEL SIGALRM ES ACABAR EL PROCESO */
int main (int argc, char *argv[])
{
  sigset_t mask; //crear mascara

  sigemptyset (&mask); //inicialtzar-la buida
  sigaddset (&mask, SIGALRM); //afegir SIGALRM a la mask
  sigprocmask (SIG_BLOCK, &mask, NULL); //afegir signals de mask a la mascara de bloquejats del proces

  alarm (5); //10s
  sigfillset (&mask); //init amb tots els signals
  sigdelset (&mask, SIGALRM); //eliminem SIGALRM
  sigdelset (&mask, SIGINT); //eliminem SIGINT
  sigsuspend (&mask); //suspendre temporalment amb la config de mask
  exit (1);
}
