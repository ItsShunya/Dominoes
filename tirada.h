#ifndef TIRADA_H
#define TIRADA_H

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
	int cont_dobles, doblederecha, dobleizquierda;
} t_tiradas;

void imprimir_tirada(t_tirada ts, t_jugador j);
void imprimir_tiradas(t_tiradas ts, t_jugador j);
t_tiradas calcular_tiradas_posibles(t_jugador j, t_mesa m);

#endif // TIRADA_H
