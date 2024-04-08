#include<stdlib.h>
#include <math.h>
#include<stdio.h>
#include <string.h>
#include "bissecao.c"
#include "secante.c"

double f1 (double x)
{
    return pow(x,5) - 2*pow(x,4) - 9*pow(x,3)+22*pow(x,2)+4*x-24;
}

double f2 (double x)
{
    return cos(x) - sqrt(x);
}

double f3 (double x)
{
    return (sqrt(x)-5)*exp(-x);
}

int main(int argc, char const *argv[])
{
    double x0, x1, episilon;
    
    episilon = strtof(argv[1], NULL);
    x0 = strtof(argv[3], NULL);
    x1 = strtof(argv[4], NULL);


    if(strcmp(argv[1], "sc") == 0) 
    //é necessario escolher a funcao alterando o codigo, como está no exemplo da lista
    {
        printf("Método: Secante\n");
        printf("Erro máximo: %s\n\n", argv[2]);
        printf("Resp: %.20lf\n\n", secante(f2, episilon, x0, x1));
    }
    if(strcmp(argv[1], "bs") == 0)
    {
        printf("Método: Bisseção\n");
        printf("Erro máximo: %s\n", argv[2]);
        printf("Resp: %.20lf\n", bissecao(f2, episilon, x0, x1);
    }
    return 0;
}
