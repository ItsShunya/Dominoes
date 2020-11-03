#include <stdio.h>
#include "ficha.h"
#define NUM_FICHAS_DOMINO 28

typedef struct
{
	int n_fichas;
	t_ficha f[NUM_FICHAS_DOMINO];
} t_mesa;

void inicializar_mesa(t_mesa *p_m)
{
	p_m->n_fichas = 0; // Inicialmente no hay fichas en la mesa
}

void imprimir_mesa(t_mesa m, int dim)
{
	int i, pos2;

	printf("\nMesa:   ");
	if (dim == FALSE)
	{ //sense 2d
		for (i = 0; i < m.n_fichas; i++)
			printf("%d:%d|", m.f[i].num1, m.f[i].num2);
	}
	else
	{ //con 2d
		printf("\n");

		for (i = 0; i < m.n_fichas; i++)
		{
			if (m.f[i].num1 == m.f[i].num2)
			{ //es doble, poner vertical
				printf("%d|", m.f[i].num1);
			}
			else
			{
				printf("___ ");
			}
		}
		printf("\n");
		for (i = 0; i < m.n_fichas; i++)
		{
			if (m.f[i].num1 == m.f[i].num2)
			{ //es doble, poner vertical
				printf("-|");
			}
			else
			{
				printf("%d:%d|", m.f[i].num1, m.f[i].num2); //es normal, se imprime normal
			}
		}
		printf("\n");
		for (i = 0; i < m.n_fichas; i++)
		{
			if (m.f[i].num1 == m.f[i].num2)
			{ //es doble, poner vertical
				printf("%d|", m.f[i].num1);
			}
			else
			{
				printf("    ");
			}
		}
		printf("\n");
	}
}

void pon_en_mesa_por_la_derecha(t_mesa *p_m, t_ficha f)
{
	int i;

	p_m->f[p_m->n_fichas] = f; // Posición de la derecha: n_fichas porque es la primera posición vacia en el vector
	p_m->n_fichas++;
}
void pon_en_mesa_por_la_izquierda(t_mesa *p_m, t_ficha f)
{
	int i;
	p_m->n_fichas++;
	for (i = p_m->n_fichas; i > 0; i--)
	{ // Desplaza toda la mesa un lugar a la derecha
		p_m->f[i] = p_m->f[i - 1];
	}
	p_m->f[0] = f; // Introduce en la posición 0 la nueva ficha
}

int extremo_izquierdo_mesa(t_mesa m)
{
	int izquierdo;
	izquierdo = m.f[0].num1;
	return (izquierdo);
}
int extremo_derecho_mesa(t_mesa m)
{
	int derecho;
	derecho = m.f[m.n_fichas - 1].num2;
	return (derecho);
}
