double secante(double (*f)(double), double epsilon, double x0, double x1)
{
    //não requer a derivada da função 
    //a cada iteração, os pontos são atualizados com base na interseção da secante com o eixo x
    //esse método é menos estável, mas não exige a derivada da função.

    double erroAbsoluto = fabs(x1 - x0);

    int i = 0;
    do 
    {
        double x_proximo = ((x0*f(x1))-(x1*f(x0))) / (f(x1)-f(x0));
        erroAbsoluto = fabs(x1 - x0);

        printf("-----Iteração %d-----\n x atual é: %lf\n\n", i = i+1, x_proximo);
        x0 = x1;
        x1 = x_proximo;

    } while (erroAbsoluto > epsilon && f(x1) != 0);

    return x1;
}
