#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "table.h"
#include "stack.h"
#include "move.h"

typedef struct
{
	t_players js;
	t_table m;	  // tiles jugadas
	t_stack pi;	  // tiles no jugadas y que no tiene nadie
	int visible;  // Pila y tiles de robots visibles
	int table_2d; // Ver mesa en 2D (versus 1D)
				  // visible y table_2d pueden valer TRUE o FALSE
	int pasadas;  // Veces consecutivas que un player pasa
				  // si pasadas == n_player se acaba el juego.
} t_game;

void initialize_game(t_game *p_pa);
void print_game_state(t_game pa);
void print_final_game_state(t_game pa);
void make_play(t_game *p_pa);
int has_the_game_ended(t_game pa);

#endif // GAME_H
