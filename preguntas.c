// Este fichero se le da al alumno
#include <stdio.h>

int fuera_de_rango(int n, int min, int max)
{
	return ((n < min) || (n > max));
}

void convertir_a_minusculas(char *c)
{
	if ((*c >= 'A') && (*c <= 'Z'))
	{
		*c = *c - 'A' + 'a';
	}
}

int preguntar_n_en_rango(char *s, int min, int max)
{
	int n;

	do
	{
		printf("%s [%d-%d]: ", s, min, max);
		scanf("%d%*c", &n);
	} while (fuera_de_rango(n, min, max));

	return n;
}

int preguntar_si_o_no(char *s)
{
	char c;

	do
	{
		printf("%s [s/n]: ", s);
		scanf("%c%*c", &c);
		convertir_a_minusculas(&c);
	} while (c != 's' && c != 'n');

	return (c == 's');
}
