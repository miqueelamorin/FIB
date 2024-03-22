#include <stdio.h>

int es_espai(char c){
    return (c == '\n' || c == '.' || c == ' ' || c == ',');
}

int contar(char *str)
{
	int	paraula_actual = 0;
	int paraula = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (!es_espai(str[i]) && paraula_actual == 0)
		{
			++paraula;
			paraula_actual = 1;
		}
		else if (es_espai(str[i]))
		{
			paraula_actual = 0;
		}
		++i;
	}
	return (paraula);
}

int main(int argc, char *argv[])
{
	if (argc >= 2) {
		printf("%i palabras\n", contar(argv[1]));
	}
	return 0;
}
