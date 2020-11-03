#include <stdio.h>
#include "tile.h"
#define NUM_TILES_DOMINO 28

typedef struct
{
	int n_tiles;
	t_tile f[NUM_TILES_DOMINO];
} t_table;

void initialize_table(t_table *p_m)
{
	p_m->n_tiles = 0; // Inicialmente no hay tiles en la mesa
}

void print_table(t_table m, int dim)
{
	int i, pos2;

	printf("\nTable:   ");
	if (dim == FALSE)
	{ //sense 2d
		for (i = 0; i < m.n_tiles; i++)
			printf("%d:%d|", m.f[i].num1, m.f[i].num2);
	}
	else
	{ //con 2d
		printf("\n");

		for (i = 0; i < m.n_tiles; i++)
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
		for (i = 0; i < m.n_tiles; i++)
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
		for (i = 0; i < m.n_tiles; i++)
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

void play_from_right(t_table *p_m, t_tile f)
{
	int i;

	p_m->f[p_m->n_tiles] = f; // Posición de la derecha: n_tiles porque es la primera posición vacia en el vector
	p_m->n_tiles++;
}
void play_from_left(t_table *p_m, t_tile f)
{
	int i;
	p_m->n_tiles++;
	for (i = p_m->n_tiles; i > 0; i--)
	{ // Desplaza toda la mesa un lugar a la derecha
		p_m->f[i] = p_m->f[i - 1];
	}
	p_m->f[0] = f; // Introduce en la posición 0 la nueva tile
}

int table_leftmost(t_table m)
{
	int left;
	left = m.f[0].num1;
	return (left);
}
int table_rightmost(t_table m)
{
	int right;
	right = m.f[m.n_tiles - 1].num2;
	return (right);
}
