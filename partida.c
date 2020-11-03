#include <stdio.h>
#include <string.h>
#include "jugador.h"
#include "mesa.h"
#include "pila.h"
#include "tirada.h"
#include "preguntas.h"
#include "duerme.h"
#include "azar.h"

#define TRUE 1
#define FALSE 0
typedef struct
{
    t_jugadores js;
    t_mesa m;    // Fichas jugadas
    t_pila pi;   // Fichas no jugadas y que no tiene nadie
    int visible; // Pila y fichas de robots visibles
    int dim;     // Ver mesa en 2D (versus 1D)
    // visible y mesa_2d pueden valer TRUE o FALSE
    int pasadas; // Veces consecutivas que un jugador pasa
    // si pasadas == n_jugadores se acaba el juego.
} t_partida;

void inicializar_partida(t_partida *p_pa);
void imprimir_estado_partida(t_partida pa);
void realizar_jugada(t_partida *p_pa);
int se_ha_acabado_la_partida(t_partida pa);

void inicializar_partida(t_partida *p_pa)
{
    int i, j, p, k, nj, nf;
    char s1[50] = "¿Numero de jugadores?", s2[50] = "¿Un jugador humano?", s3[50] = "¿Quieres omnisciencia?", s4[50] = "¿Quieres ver la mesa en 2D?";

    p_pa->pasadas = 0;

    p_pa->js.n_jugadores = preguntar_n_en_rango(&s1[0], 2, 4); //Realizamos las preguntas
    p_pa->js.un_humano = preguntar_si_o_no(&s2[0]);
    p_pa->visible = preguntar_si_o_no(&s3[0]);
    p_pa->dim = preguntar_si_o_no(&s4[0]);
    printf("\n");

    inicializar_pila(&(p_pa->pi));

    for (i = 0; i < p_pa->js.n_jugadores; i++) //Repartir fichas aleatoriamente
        for (j = 0; j < 7; j++)
            p_pa->js.j[i].f[j] = coger_ficha_de_la_pila(&(p_pa->pi));

    if (p_pa->js.un_humano == TRUE)
    { // Inicializamos los jugadores
        p_pa->js.j[0].tipo = T_HUMANO;
        p_pa->js.j[0].n_fichas = 7;
        for (i = 1; i < p_pa->js.n_jugadores; i++)
        {
            p_pa->js.j[i].tipo = T_ROBOT;
            p_pa->js.j[i].n_fichas = 7;
        }
    }
    else
    {
        for (i = 0; i < p_pa->js.n_jugadores; i++)
        {
            p_pa->js.j[i].tipo = T_ROBOT;
            p_pa->js.j[i].n_fichas = 7;
        }
    }
    que_jugador_tiene_doble_mas_alto(p_pa->js, &nj, &nf); // Que jugador empieza la partida

    inicializar_mesa(&(p_pa->m));
    imprimir_pila(p_pa->pi, p_pa->visible);

    pon_en_mesa_por_la_izquierda(&(p_pa->m), p_pa->js.j[nj].f[nf]);
    imprimir_mesa(p_pa->m, p_pa->dim);
    printf("\n");

    for (i = nf; i < p_pa->js.j[nj].n_fichas; i++)
        p_pa->js.j[nj].f[i] = p_pa->js.j[nj].f[i + 1];
    p_pa->js.j[nj].n_fichas--;

    p_pa->js.turno = nj;
    imprimir_jugadores(p_pa->js, p_pa->visible);
    pasar_turno(&(p_pa->js));
    imprimir_turno(p_pa->js);
}

void imprimir_estado_partida(t_partida pa)
{
    int i;
    imprimir_pila(pa.pi, pa.visible);
    //POSAR MESA EN NEGRETA
    imprimir_mesa(pa.m, pa.dim);
    printf("\n");
    imprimir_jugadores(pa.js, pa.visible);
    imprimir_turno(pa.js);
}
void imprimir_estado_final_partida(t_partida pa)
{ // Printf de la partida en el momento del final de la partida
    int i;
    duerme_un_rato(10);
    printf("\tESTADO FINAL DE PARTIDA:\n\n");
    pa.visible = TRUE;

    imprimir_pila(pa.pi, pa.visible);
    //POSAR MESA EN NEGRETA
    imprimir_mesa(pa.m, pa.dim);
    printf("\n");
    imprimir_jugadores(pa.js, pa.visible);
    printf("\n");
}

void realizar_jugada(t_partida *p_pa)
{
    int tirada = -1, i, v;
    t_tiradas ts;

    ts = calcular_tiradas_posibles(p_pa->js.j[p_pa->js.turno], p_pa->m); //Calculamos si hay tiradas posibles

    while (ts.n_tiradas == 0 && p_pa->pi.n_fichas != 0)
    { // Si no puede tirar tiene que robar ficha
        p_pa->js.j[p_pa->js.turno].f[p_pa->js.j[p_pa->js.turno].n_fichas] = coger_ficha_de_la_pila(&(p_pa->pi));

        if (p_pa->visible == TRUE)
        {                                                    // Omnisciencia activada
            if (p_pa->js.j[p_pa->js.turno].tipo == T_HUMANO) // Si es humano muestra la ficha
                printf("Vas a la pila! Pillas un %d:%d ;P\n", p_pa->js.j[p_pa->js.turno].f[p_pa->js.j[p_pa->js.turno].n_fichas].num1, p_pa->js.j[p_pa->js.turno].f[p_pa->js.j[p_pa->js.turno].n_fichas].num2);
            else
                printf("Va a la pila! Pilla un %d:%d ;)\n", p_pa->js.j[p_pa->js.turno].f[p_pa->js.j[p_pa->js.turno].n_fichas].num1, p_pa->js.j[p_pa->js.turno].f[p_pa->js.j[p_pa->js.turno].n_fichas].num2); // Si es robot muestra la ficha
            p_pa->js.j[p_pa->js.turno].n_fichas++;
            ts = calcular_tiradas_posibles(p_pa->js.j[p_pa->js.turno], p_pa->m);
        }
        if (p_pa->visible == FALSE)
        {
            if (p_pa->js.j[p_pa->js.turno].tipo == T_HUMANO) //Si es humano muestra la ficha
                printf("Vas a la pila! Pillas un %d:%d ;P\n", p_pa->js.j[p_pa->js.turno].f[p_pa->js.j[p_pa->js.turno].n_fichas].num1, p_pa->js.j[p_pa->js.turno].f[p_pa->js.j[p_pa->js.turno].n_fichas].num2);
            else
                printf("Va a la pila! ;)\n"); //Si es robot no muestra la ficha
            p_pa->js.j[p_pa->js.turno].n_fichas++;
            ts = calcular_tiradas_posibles(p_pa->js.j[p_pa->js.turno], p_pa->m);
        }
    }

    imprimir_tiradas(ts, p_pa->js.j[p_pa->js.turno]);

    if (p_pa->js.j[p_pa->js.turno].tipo == T_HUMANO)
    { //tira humano
        if (ts.n_tiradas == 0 && p_pa->pi.n_fichas == 0)
        { //HUMANO no puede tirar y pasa turno
            printf("Pasas! :(\n\n");
            p_pa->pasadas++;
        }

        if (ts.n_tiradas > 0)
        {
            p_pa->pasadas = 0;
            if (ts.cont_dobles > 1)
                v = ts.n_tiradas; //Si se dobledobla cuenta esa tirada como extra
            else
                v = ts.n_tiradas - 1;
            printf("¿Que tirada juegas[0-%d]?: ", v);
            scanf("%d", &tirada);
            while (tirada < 0 || tirada > v)
            {
                printf("¡%d no es una opcion!\n", tirada);
                printf("¿Que tirada juegas[0-%d]?: ", v);
                scanf("%d", &tirada);
            }
            printf("\n");
            if ((ts.cont_dobles > 1) && (tirada == ts.n_tiradas))
            {                                                                                                          //Se dobledobla cuando el contador tiene 2 tiradas con dobles y el jugador la escoje
                pon_en_mesa_por_la_derecha(&(p_pa->m), p_pa->js.j[p_pa->js.turno].f[ts.t[ts.dobleizquierda].n_ficha]); //Doble por la derecha
                pon_en_mesa_por_la_izquierda(&(p_pa->m), p_pa->js.j[p_pa->js.turno].f[ts.t[ts.doblederecha].n_ficha]); //Doble por la izquierda
                for (i = ts.t[ts.doblederecha].n_ficha; i < p_pa->js.j[p_pa->js.turno].n_fichas - 1; i++)              // Eliminar un doble del vector de fichas del jugador
                    p_pa->js.j[p_pa->js.turno].f[i] = p_pa->js.j[p_pa->js.turno].f[i + 1];
                p_pa->js.j[p_pa->js.turno].n_fichas--;
                if (ts.t[ts.dobleizquierda].n_ficha > ts.t[ts.doblederecha].n_ficha)
                { // Eliminar el otro doble del vector de fichas dependiendo de donde se encuentre respecto al primer doble
                    for (i = ts.t[ts.dobleizquierda - 1].n_ficha; i < p_pa->js.j[p_pa->js.turno].n_fichas - 1; i++)
                        p_pa->js.j[p_pa->js.turno].f[i] = p_pa->js.j[p_pa->js.turno].f[i + 1];
                    p_pa->js.j[p_pa->js.turno].n_fichas--;
                }
                else
                {
                    for (i = ts.t[ts.dobleizquierda - 1].n_ficha; i < p_pa->js.j[p_pa->js.turno].n_fichas - 1; i++)
                        p_pa->js.j[p_pa->js.turno].f[i] = p_pa->js.j[p_pa->js.turno].f[i + 1];
                    p_pa->js.j[p_pa->js.turno].n_fichas--;
                }
            }
            if (tirada != ts.n_tiradas)
            {                                    //Si no se dobledobla
                if (ts.t[tirada].girada == TRUE) //Gira la ficha si debe hacerlo
                    girar_ficha(&(p_pa->js.j[p_pa->js.turno].f[ts.t[tirada].n_ficha]));
                if (ts.t[tirada].extremo == 'd')
                {
                    pon_en_mesa_por_la_derecha(&(p_pa->m), p_pa->js.j[p_pa->js.turno].f[ts.t[tirada].n_ficha]); //Coloca por la derecha
                }
                else
                {
                    pon_en_mesa_por_la_izquierda(&(p_pa->m), p_pa->js.j[p_pa->js.turno].f[ts.t[tirada].n_ficha]); //Coloca por la izquierda
                }
                for (i = ts.t[tirada].n_ficha; i < p_pa->js.j[p_pa->js.turno].n_fichas - 1; i++)
                    p_pa->js.j[p_pa->js.turno].f[i] = p_pa->js.j[p_pa->js.turno].f[i + 1];
                p_pa->js.j[p_pa->js.turno].n_fichas--;
            }
        }
    }
    else
    { /*TIRA UN ROBOT*/
        if (ts.n_tiradas == 0 && p_pa->pi.n_fichas == 0)
        {
            printf("Pasa! :)\n\n"); //Si no puede tirar pasa turno
            p_pa->pasadas++;
        }
        //Robot no puede tirar y pasa turno

        if (ts.n_tiradas > 0)
        {
            p_pa->pasadas = 0;
            if (ts.cont_dobles > 1)
                ts.n_tiradas++;                    // Dobledoblarse cuenta como una tirada más
            tirada = numero_al_azar(ts.n_tiradas); // Escoge una tirada al azar
            if ((ts.cont_dobles > 1) && (tirada == ts.n_tiradas))
            {                                                                                                          //Se dobledobla cuando el contador tiene 2 tiradas con dobles y el jugador la escoje
                pon_en_mesa_por_la_derecha(&(p_pa->m), p_pa->js.j[p_pa->js.turno].f[ts.t[ts.dobleizquierda].n_ficha]); // Doble por la derecha
                pon_en_mesa_por_la_izquierda(&(p_pa->m), p_pa->js.j[p_pa->js.turno].f[ts.t[ts.doblederecha].n_ficha]); // Doble por la izquierda
                for (i = ts.t[ts.doblederecha].n_ficha; i < p_pa->js.j[p_pa->js.turno].n_fichas - 1; i++)              // Eliminar un doble del vector de fichas del robot
                    p_pa->js.j[p_pa->js.turno].f[i] = p_pa->js.j[p_pa->js.turno].f[i + 1];
                p_pa->js.j[p_pa->js.turno].n_fichas--;
                if (ts.t[ts.dobleizquierda].n_ficha > ts.t[ts.doblederecha].n_ficha)
                { //Eliminar el otro doble dependiendo de su posición respecto al primero
                    for (i = ts.t[ts.dobleizquierda - 1].n_ficha; i < p_pa->js.j[p_pa->js.turno].n_fichas - 1; i++)
                        p_pa->js.j[p_pa->js.turno].f[i] = p_pa->js.j[p_pa->js.turno].f[i + 1];
                    p_pa->js.j[p_pa->js.turno].n_fichas--;
                }
                else
                {
                    for (i = ts.t[ts.dobleizquierda - 1].n_ficha; i < p_pa->js.j[p_pa->js.turno].n_fichas - 1; i++)
                        p_pa->js.j[p_pa->js.turno].f[i] = p_pa->js.j[p_pa->js.turno].f[i + 1];
                    p_pa->js.j[p_pa->js.turno].n_fichas--;
                }
            }
            else
            {
                if (ts.t[tirada].girada == TRUE) //Gira la ficha si debe hacerlo
                    girar_ficha(&(p_pa->js.j[p_pa->js.turno].f[ts.t[tirada].n_ficha]));
                imprimir_tirada(ts.t[tirada], p_pa->js.j[p_pa->js.turno]);
                if (ts.t[tirada].extremo == 'd')
                {
                    pon_en_mesa_por_la_derecha(&(p_pa->m), p_pa->js.j[p_pa->js.turno].f[ts.t[tirada].n_ficha]); //Coloca por la derecha
                }
                else
                {
                    pon_en_mesa_por_la_izquierda(&(p_pa->m), p_pa->js.j[p_pa->js.turno].f[ts.t[tirada].n_ficha]); //Coloca por la izquierda
                }
                for (i = ts.t[tirada].n_ficha; i < p_pa->js.j[p_pa->js.turno].n_fichas - 1; i++) //Elimina la ficha del vector
                    p_pa->js.j[p_pa->js.turno].f[i] = p_pa->js.j[p_pa->js.turno].f[i + 1];
                p_pa->js.j[p_pa->js.turno].n_fichas--;
            }
            duerme_un_rato(4);
        }
    }

    pasar_turno(&(p_pa->js));
}

int se_ha_acabado_la_partida(t_partida pa)
{
    int aux = FALSE, minpeso = 200, i, j, jugminpeso, empate = FALSE;

    if (pa.js.turno > 0) // Como se_ha_acabado_la_partida se coloca despues de pasar_turno, pa.js.turno debe ser un numero menos
        pa.js.turno = pa.js.turno - 1;

    else // NO puede ser -1, asi que vuelve a n_jugadores-1 (maximo)
        pa.js.turno = pa.js.n_jugadores - 1;

    if (pa.js.j[pa.js.turno].n_fichas == 0)
    { // Condición de ganador
        if (pa.js.j[pa.js.turno].tipo == T_HUMANO)
        { // Gana el humano
            printf("===>>> HAS GANADO! :) <<<===\n\n");
        }
        else
        { //Gana el robot
            printf("===>>> HA GANADO EL J%d! :/ <<<===\n\n", pa.js.turno);
        }
        aux = TRUE;
        return (aux);
    }
    else if (pa.pasadas >= pa.js.n_jugadores)
    { //Ganador en bloqueo
        printf("===>>> JUEGO BLOQUEADO <<<===\n\n");
        aux = TRUE;
        for (i = 0; i < pa.js.n_jugadores; i++)
        { // Calcula el peso de las fichas
            pa.js.j[i].peso = 0;
            for (j = 0; j < pa.js.j[i].n_fichas; j++)
            {
                pa.js.j[i].peso = pa.js.j[i].peso + pa.js.j[i].f[j].num1 + pa.js.j[i].f[j].num2;
            }
            printf("Peso J%d=%d\n", i, pa.js.j[i].peso);
        }
        for (i = 0; i < pa.js.n_jugadores; i++)
        { //Peso minimo con su jugador
            if (minpeso > pa.js.j[i].peso)
            {
                minpeso = pa.js.j[i].peso;
                jugminpeso = i;
            }
        }
        for (i = 0; i < pa.js.n_jugadores; i++)
        { // Caso de empate (tablas)
            if (minpeso == pa.js.j[i].peso && i != jugminpeso)
            {
                empate = TRUE;
            }
        }
        if (empate == TRUE)
        { // Tablas
            printf("\n===>>> TABLAS ENTRE J%d Y J%d CON MINIMO PESO(%d de peso) <<<===\n\n\n", jugminpeso, i, minpeso);
        }
        else
        { // Ganador
            printf("\n===>>> HA GANADO EL J%d POR MINIMO PESO(%d de peso) <<<===\n\n\n", jugminpeso, minpeso);
        }
    }
    else
        return (aux);
}
