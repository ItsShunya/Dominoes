#ifndef PILA_H
#define PILA_H

#include "ficha.h"

typedef struct
{
	int n_fichas;
	t_ficha f[NUM_FICHAS_DOMINO];
} t_pila;

void inicializar_pila(t_pila *pi);
void imprimir_pila(t_pila pi, int visible);
t_ficha coger_ficha_de_la_pila(t_pila *pi);
int esta_la_pila_vacia(t_pila pi);

#endif // PILA_H
