#include "game.h"

#define TRUE 1
#define FALSE 0

int main()
{
	int end;
	t_game game;
	initialize_game(&game);
	make_play(&game);
	end = FALSE;		 // Inicialitzem "end" a 0 perque la game comença i ha d'entrar al while
	while (end == FALSE) // Entra sempre que es pugui seguint jugar
	{
		print_game_state(game);
		make_play(&game);
		end = has_the_game_ended(game);
	}

	print_final_game_state(game); // Printf de la game en la jugada final
}
