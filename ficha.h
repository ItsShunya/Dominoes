#ifndef FICHA_H
#define FICHA_H

#define FALSE	0
#define TRUE	1

#define NUM_FICHAS_DOMINO		28

typedef struct{
    int num1, num2;
}t_ficha;

void inicializar_ficha(t_ficha *p_f, int a, int b);
void girar_ficha(t_ficha *p_f);
void imprimir_ficha(t_ficha f, int visible);

#endif // FICHA_H

