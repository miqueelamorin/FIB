#include "mis_funciones.h"

unsigned int char2int(char c){
    return (c - '0');
}

int mi_atoi(char *s){
    int signe = 1;
    int valor = 0;
    while (*s == '\n' || *s == ' ') ++s;
    if (*s == '-') {
        signe = -1;
        ++s;
    }
    while (*s >= '0' && *s <= '9'){
        valor *= 10;
        valor += char2int(*s);
        ++s;
    }
    return (valor * signe);
}

int esNumero(char *str) {
	if (str) {
		int i = 0;
		if (str[i] == '-') ++str;
		for (; str[i] != '\0'; ++i) {
			if (str[i] < '0' || str[i] > '9')
				return 0;
		}
		return (i > 0) && (i <= MAX_SIZE);
	}
	return 0;
}
