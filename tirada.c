#define TIRADA_H

#include <stdio.h>
#include "ficha.h"
#include "jugador.h"
#include "mesa.h"

#define MAX_TIRADAS_JUGADOR NUM_FICHAS_DOMINO

typedef struct
{
	int n_ficha;  // numero de ficha en el vector de fichas del jugador
	char extremo; // IZQUIERDA o DERECHA (de n_ficha(1))
	int girada;	  // TRUE o FALSE
	int dobledobla;
} t_tirada;

typedef struct
{
	int n_tiradas;
	t_tirada t[MAX_TIRADAS_JUGADOR];
	int cont_dobles, dobleizquierda, doblederecha;

} t_tiradas;

void imprimir_tirada(t_tirada t, t_jugador j)
{ //Siempre es visible independiente de omnisciencia
	int aux;
	aux = t.n_ficha;
	if (j.tipo == T_ROBOT)
		printf("Tira:  %c|%d:%d|\n\n", t.extremo, j.f[aux].num1, j.f[aux].num2);
}

void imprimir_tiradas(t_tiradas ts, t_jugador j, int visible)
{
	int i;

	if ((visible == TRUE && j.tipo == T_ROBOT) || j.tipo == T_HUMANO)
	{ // Muestra si omnisciencia está activada o el jugador es humano
		printf("Tiradas posibles: ");
		if (ts.n_tiradas > 0)
		{ // Si puede tirar
			for (i = 0; i < ts.n_tiradas; i++)
			{
				printf("%d(%c%d:%d) ", i, ts.t[i].extremo, j.f[ts.t[i].n_ficha].num1, j.f[ts.t[i].n_ficha].num2);
			}

			if ((ts.cont_dobles > 1) && (j.f[ts.t[ts.dobleizquierda].n_ficha].num1 != j.f[ts.t[ts.doblederecha].n_ficha].num2))
			{
				i = ts.n_tiradas;
				printf("%d(%c%d:%d|%c%d:%d) ", i, ts.t[ts.dobleizquierda].extremo, j.f[ts.t[ts.dobleizquierda].n_ficha].num1, j.f[ts.t[ts.dobleizquierda].n_ficha].num2, ts.t[ts.doblederecha].extremo, j.f[ts.t[ts.doblederecha].n_ficha].num1, j.f[ts.t[ts.doblederecha].n_ficha].num2);
			}
			printf("\n");
		}
		else
			printf("No hay tiradas posibles!!\n"); // Si no puede tirar
	}
}

t_tiradas calcular_tiradas_posibles(t_jugador j, t_mesa m)
{
	t_tiradas ts;
	int izq, der, i, k = 0, doble;
	izq = extremo_izquierdo_mesa(m); // Calcula el extremo izquierdo de la mesa
	der = extremo_derecho_mesa(m);	 // Calcula el extremo derecho de la mesa
	ts.cont_dobles = 0;
	for (i = 0; i < j.n_fichas; i++)
	{
		doble = 0;
		if (j.f[i].num1 == j.f[i].num2)
			doble = TRUE; // Comprueba si es un doble

		if (j.f[i].num2 == izq)
		{ // Tirada por la izquierda sin girar
			if (doble == TRUE)
			{
				ts.cont_dobles++;
				ts.dobleizquierda = k;
			}
			ts.t[k].n_ficha = i;
			ts.t[k].extremo = 'i';
			ts.t[k].girada = 0;
			k++;
		}
		if (j.f[i].num1 == izq)
		{ // Tirada por la izquierda girando
			if (doble == FALSE)
			{
				ts.t[k].n_ficha = i;
				ts.t[k].extremo = 'i';
				ts.t[k].girada = 1;
				k++;
			}
		}
		if (j.f[i].num1 == der)
		{ // Tirada por la derecha sin girar
			if (doble == TRUE)
			{
				ts.cont_dobles++;
				ts.doblederecha = k;
			}
			ts.t[k].n_ficha = i;
			ts.t[k].extremo = 'd';
			ts.t[k].girada = 0;
			k++;
		}
		if (j.f[i].num2 == der)
		{ // Tirada por la derecha girando
			if (doble == FALSE)
			{
				ts.t[k].n_ficha = i;
				ts.t[k].extremo = 'd';
				ts.t[k].girada = 1;
				k++;
			}
		}

		ts.n_tiradas = k; // Numero de tiradas
	}

	return (ts);
}
