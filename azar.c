// Este fichero se le da al alumno
#include <time.h>	// time()
#include <stdlib.h>	// rand(), srand()
#include <stdio.h>	// printf()
#include "azar.h"

/*
 * inicializar_azar() se tiene que ejecutar una vez al principio del main
 * para inicializar la generación de números aleatorios
 */
//void inicializar_azar() {
	/*
	 * Para que la sequencia de numeros aleatorios sea igual en cada
	 * ejecucion usad el srand (0) en lugar del srand(time).
	 */
	//srand(0);
//	srand( (unsigned)time( NULL ) );
//}

/*
 * numero_al_azar(max) devuelve un número entero al azar entre 0 y max-1
 */
int numero_al_azar(int max) {
	srand(time(NULL));
	return ( rand() % max); 
}

