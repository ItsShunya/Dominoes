#ifndef JUGADOR_H
#define JUGADOR_H

#include "ficha.h"

#define MIN_JUGADORES	2
#define MAX_JUGADORES	4

#define T_HUMANO	1
#define T_ROBOT		2

typedef struct {
	int	n_fichas;
	t_ficha	f[NUM_FICHAS_DOMINO];	// Fichas que tiene
	int	tipo;
    int peso;
} t_jugador;

typedef struct {
	int n_jugadores;
	int un_humano;	// TRUE or FALSE
	int turno;
	t_jugador	j[MAX_JUGADORES]; // Fichas que tiene y otras cosas
} t_jugadores;

void imprimir_jugador(t_jugador j, int visible);
void imprimir_jugadores(t_jugadores js, int visible);
void que_jugador_tiene_doble_mas_alto(t_jugadores js, int *p_nj, int *p_nf);
void pasar_turno(t_jugadores *p_js);
void imprimir_turno(t_jugadores _js);

#endif // JUGADOR_H

