// Este fichero se le da al alumno
#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int fuera_de_rango(int n, int min, int max);
void convertir_a_minusculas(char *c);
int preguntar_n_en_rango(char *s, int min, int max);
int preguntar_si_o_no(char *s);

#endif // PREGUNTAS_H
