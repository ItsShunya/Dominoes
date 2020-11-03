#include <stdio.h>
#include "azar.h"
#include "ficha.h"
#define NUM_FICHAS_DOMINO 28
#define FALSE 0
#define TRUE 1

typedef struct
{
	int n_fichas;
	t_ficha f[NUM_FICHAS_DOMINO];
} t_pila;

void imprimir_pila(t_pila pi, int visible);
void inicializar_pila(t_pila *pi);
int esta_la_pila_vacia(t_pila pi);
t_ficha coger_ficha_de_la_pila(t_pila *pi);

void inicializar_pila(t_pila *pi)
{
	int i = 0, j, k;

	pi->n_fichas = NUM_FICHAS_DOMINO; // Al inicio todas las fichas estan en la pila
	for (j = 0; j < 7; j++)
		for (k = j; k < 7; k++)
		{
			inicializar_ficha(&pi->f[i], j, k); //Inicializa las 28 fichas
			i++;
		}
}

void imprimir_pila(t_pila pi, int visible)
{
	int i;

	if (visible == TRUE)
	{ // Omnisciencia activada
		printf("Pila:\t");
		for (i = 0; i < pi.n_fichas; i++)
			imprimir_ficha(pi.f[i], visible);
	}

	else
	{ // Omnisciencia apagada
		printf("Pila:\t");
		for (i = 0; i < pi.n_fichas; i++)
			printf("?:?|");
	}
	if (pi.n_fichas == 0)
		printf("La pila esta vacia");
}

int esta_la_pila_vacia(t_pila pi)
{
	if (pi.n_fichas == 0)
		return (TRUE);

	else
		return (FALSE);
}

t_ficha coger_ficha_de_la_pila(t_pila *pi)
{
	int i, pos;
	t_pila aux;
	pos = numero_al_azar(pi->n_fichas); // Escoge una ficha aleatoria
	aux.f[pos] = pi->f[pos];			// Guarda esta ficha aleatoria en un auxiliar
	for (i = pos; i < (pi->n_fichas - 1); i++)
	{ // Elimina la ficha robada del vector de la pila
		pi->f[i] = pi->f[i + 1];
	}
	pi->n_fichas--;
	return (aux.f[pos]); // El return devuelve la ficha robada
}
