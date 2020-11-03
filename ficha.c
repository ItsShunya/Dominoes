#include <stdio.h>  
typedef struct{
    int num1, num2;
}t_ficha;

void inicializar_ficha (t_ficha *ficha, int i, int j);
void imprimir_ficha (t_ficha f, int visible);
void girar_ficha (t_ficha *ficha);
int doble();

void imprimir_ficha(t_ficha ficha, int visible){
	
	printf("%d:%d|", ficha.num1, ficha.num2);
}

void girar_ficha(t_ficha *ficha){    // num1 es canvia per num2 i al contrari
	int aux, i;
   
    aux=ficha->num1;
    ficha->num1=ficha->num2;
    ficha->num2=aux;

}

int doble()
{	t_ficha ficha[28];
	int i;
	
	if(ficha[i].num1==ficha[i].num2) //Si es un doble num1=num2
		return(1);
	else return(0);
}

void inicializar_ficha (t_ficha *ficha, int i, int j) {      
            ficha->num2=j; 
            ficha->num1=i;
        }
