#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mis_funciones.h"

void Usage(){
    printf("Usage:listaParametros arg1 [arg2..argn]\n");
    printf("Este programa escribe por su salida la lista de argumentos que recibe\n");
}

int main (int argc, char *argv[])
{
    if (argc <= 2) Usage();
    char buf[80];
    int suma = 0;
    for (int i = 1; i < argc; i++) {
        if (esNumero (argv[i]) == 1) {
            suma += mi_atoi(argv[i]);
        }
        else {
            sprintf (buf, "Error: el parametro %s no es un numero\n", argv[i]);
            write (1, buf, strlen (buf));
            return 0;
        }
    }
    sprintf (buf, "La suma es %d\n", suma);
    write (1, buf, strlen (buf));
    return 0;
}
