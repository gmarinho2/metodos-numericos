#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double f1 (double x)
{
    return pow(x,5) - 2*pow(x,4) - 9*pow(x,3)+22*pow(x,2)+4*x-24;
}

double f2 (double x)
{
    return pow(cos(x), 2);
}

double f3 (double x)
{
    return (sqrt(x)-5)*exp(-x);
}

double bissecao(double (*funcao_ptr)(double), double a, double b, double epsilon)
{
    double x0 = a;
    double x1 = b;

    while(fabs(x0 - x1) > epsilon)
    {
        printf("O x atual é: %lf\n", x0);
        x1 = (a + b)/2;

        if(funcao_ptr(x1) * funcao_ptr(a)<0)
        {
            b = x1;
        }
        else
        {
            a = x1;
        }
        
        x0 = x1;
        printf("O x atual é: %lf\n", x0);
    } 

    return x0;
}

double secante(double (*funcao_ptr)(double), double x0, double x1, double epsilon)
{
    double erroAbsoluto;

    double x_proximo;

    
    do {
        x_proximo = (x0*funcao_ptr(x1)-x1*funcao_ptr(x0)) / funcao_ptr(x1)-funcao_ptr(x0);
        erroAbsoluto = fabs(x1 - x0);

        //atualiza variaveis:
        double aux = x1;
        x1 = x_proximo;
        x0 = aux;

        printf("O x atual é: %lf\n", x0);
    } while (erroAbsoluto > epsilon);
    

    return x0;

}

int main(int argc, char const *argv[])
{

    double resposta = secante(f1, 1, 3, 1E-10);

    printf("A resposta é: %.20lf", resposta);

    return 0;
}
