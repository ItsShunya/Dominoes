#ifndef PARTIDA_H
#define PARTIDA_H

#include "jugador.h"
#include "mesa.h"
#include "pila.h"
#include "tirada.h"

typedef struct
{
	t_jugadores js;
	t_mesa m;	 // Fichas jugadas
	t_pila pi;	 // Fichas no jugadas y que no tiene nadie
	int visible; // Pila y fichas de robots visibles
	int mesa_2d; // Ver mesa en 2D (versus 1D)
				 // visible y mesa_2d pueden valer TRUE o FALSE
	int pasadas; // Veces consecutivas que un jugador pasa
				 // si pasadas == n_jugadores se acaba el juego.
} t_partida;

void inicializar_partida(t_partida *p_pa);
void imprimir_estado_partida(t_partida pa);
void imprimir_estado_final_partida(t_partida pa);
void realizar_jugada(t_partida *p_pa);
int se_ha_acabado_la_partida(t_partida pa);

#endif // PARTIDA_H
