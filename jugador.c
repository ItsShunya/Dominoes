#include "ficha.h"
#include <stdio.h>

#define MIN_JUGADORES 2
#define MAX_JUGADORES 4

#define T_HUMANO 1
#define T_ROBOT 2

#define TRUE 1
#define FALSE 0

typedef struct
{
	int n_fichas;
	t_ficha f[NUM_FICHAS_DOMINO]; // Fichas que tiene
	int tipo;
	int peso;
} t_jugador;

typedef struct
{
	int n_jugadores;
	int un_humano; // TRUE or FALSE
	int turno;
	t_jugador j[MAX_JUGADORES]; // Fichas que tiene y otras cosas
} t_jugadores;

void imprimir_jugador(t_jugador j, int visible);
void imprimir_jugadores(t_jugadores js, int visible);
void que_jugador_tiene_doble_mas_alto(t_jugadores js, int *p_nj, int *p_nf);
void pasar_turno(t_jugadores *p_js);
void imprimir_turno(t_jugadores _js);

void imprimir_jugador(t_jugador j, int visible)
{
	int i;
	t_ficha f;

	if (j.tipo == T_ROBOT)
	{ // Robot
		if (visible == FALSE)
		{ // Omnisciencia apagada
			for (i = 0; i < j.n_fichas; i++)
			{
				printf("?:?|");
			}
		}
		else
		{ // Omnisciencia encendida
			for (i = 0; i < j.n_fichas; i++)
			{
				printf("%d:%d|", j.f[i].num1, j.f[i].num2);
			}
		}
	}
	else
	{ // Humano
		for (i = 0; i < j.n_fichas; i++)
		{
			printf("%d:%d|", j.f[i].num1, j.f[i].num2);
		}
	}
}
void imprimir_jugadores(t_jugadores js, int visible)
{
	int i;
	for (i = 0; i < js.n_jugadores; i++)
	{ //Ejecuta el codigo para cada jugador
		printf("J%d 	", i);
		imprimir_jugador(js.j[i], visible);
		if (js.j[i].tipo == T_ROBOT)
		{ //Robot
			printf("Robot\n");
		}
		else
		{ //Humano
			printf("Humano\n");
		}
	}
}
void que_jugador_tiene_doble_mas_alto(t_jugadores js, int *p_nj, int *p_nf)
{
	int i, j, max = 0, encontrado = 0;

	for (i = 0; i < js.n_jugadores; i++)
	{ //Comprueba que jugador tiene el doble mas alto
		for (j = 0; j < js.j[i].n_fichas; j++)
		{
			if (js.j[i].f[j].num1 == js.j[i].f[j].num2 && js.j[i].f[j].num1 > max)
			{
				max = js.j[i].f[j].num1;
				*p_nj = i;
				*p_nf = j;
				encontrado = 1;
			}
		}
	}
	if (encontrado == 0)
	{
		*p_nj = 0;
		*p_nf = 0;
	}
}
void pasar_turno(t_jugadores *p_js)
{
	p_js->turno = ((p_js->turno) + 1) % (p_js->n_jugadores); // Suma 1 al turno a menos que sea máximo, entonces vuelve al inicial (0)
}
void imprimir_turno(t_jugadores js)
{
	printf("Turno: %d\n", js.turno);
}
