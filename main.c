#include "partida.h"
//incloure totes les llibreries

#define TRUE 1
#define FALSE 0

int main(){
	int acabado;
	t_partida partida;
	inicializar_partida(&partida);
	realizar_jugada(&partida);
	acabado=FALSE;            // Inicialitzem "acabado" a 0 perque la partida comença i ha d'entrar al while
	while(acabado==FALSE)     // Entra sempre que es pugui seguint jugar
	{	
                imprimir_estado_partida(partida);
		realizar_jugada(&partida);
		acabado=se_ha_acabado_la_partida(partida);
	}
	
	imprimir_estado_final_partida(partida);   // Printf de la partida en la jugada final
}
