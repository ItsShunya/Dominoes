// Este fichero se le da al alumno
#include <time.h>
#include "duerme.h"

#define UN_RATO_SEGUNDOS	1		// 1 segundo
#define UN_RATO_NANOSEGUNDOS	500000000	// 0.5 segundos

/*
 * Hace que la ejecucion del programa se detenga durante
 * el numero de segundos que se le pasa por parametro
 */
void duerme_n_segundos(long segundos) {
	struct timespec tim, tim2;
	tim.tv_sec = segundos;
	tim.tv_nsec = 0;

	nanosleep(&tim , &tim2);
}

/*
 * Hace que la ejecucion del programa se detenga durante
 * el numero de nanosegundos que se le pasa por parametro
 */
void duerme_n_nanosegundos(long nanosegundos) {
	struct timespec tim, tim2;
	tim.tv_sec = 0;
	tim.tv_nsec = nanosegundos;

	nanosleep(&tim , &tim2);
}

/*
 * Hace que la ejecucion del programa se detenga durante
 * un numero de segundos predeterminado
 */
void duerme_un_rato() {
	duerme_n_segundos(UN_RATO_SEGUNDOS);
}

/*
 * Hace que la ejecucion del programa se detenga durante
 * un numero de nanosegundos predeterminado
 */
void duerme_un_nano_rato() {
	duerme_n_nanosegundos(UN_RATO_NANOSEGUNDOS);
}

