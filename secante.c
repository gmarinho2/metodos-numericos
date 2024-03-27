double secante(double (*f)(double), double epsilon, double x0, double x1)
{
    //não requer a derivada da função 
    //a cada iteração, os pontos são atualizados com base na interseção da secante com o eixo x
    //esse método é menos estável, mas não exige a derivada da função.

    double erroAbsoluto = fabs(x1 - x0);
    double fx0 = f(x0);
    double fx1 = f(x1);
    int i = 0;
    do 
    {
        double x_proximo = (x0*fx1-x1*fx0) / (fx1-fx0);
        erroAbsoluto = fabs(x1 - x0);
        fx0 = fx1;
        fx1 = f(x_proximo);

        
        printf("Iteração %d: x atual é:%lf\n", i = i+1, x_proximo);
        x0 = x1;
        x1 = x_proximo;

    } while (erroAbsoluto > epsilon && f(x1) != 0);

    return x1;
}
