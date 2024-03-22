#ifndef MIS_FUNCIONES_H
#define MIS_FUNCIONES_H

#include <stdio.h>
#define MAX_SIZE 8

int esNumero(char *str);
/* Retorna 1 si 'str' es un numero de como mucho 8 cifras, 0 altramente.*/

unsigned int char2int(char c);
/* Retorna el caracter 'c' convertido a integer. 'c' es un numero de una cifra.*/

int mi_atoi(char *s);
/* Retorna 's' convertido a integer. 's' es un numero de varias cifras.*/

#endif
