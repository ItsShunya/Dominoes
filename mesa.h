#ifndef MESA_H
#define MESA_H

#include "ficha.h"

typedef struct {
	int n_fichas;
	t_ficha	f[NUM_FICHAS_DOMINO];
} t_mesa;

void inicializar_mesa(t_mesa *p_m);
void imprimir_mesa(t_mesa m, int dim);

void pon_en_mesa_por_la_derecha(t_mesa *p_m, t_ficha f);
void pon_en_mesa_por_la_izquierda(t_mesa *p_m, t_ficha f);

int extremo_izquierdo_mesa(t_mesa m);
int extremo_derecho_mesa(t_mesa m);

#endif // MESA_H
