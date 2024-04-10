double bissecao(double (*f)(double), double epsilon, double a, double b)
{
    //a convergência do método é assegurada, garantindo que o algoritmo permaneça dentro do intervalo inicial
    //a cada iteração, o tamanho do intervalo é reduzido pela metade
    //além disso, o método requer uma estimativa inicial precisa. o valor escolhido no primeiro passo influencia 
    //diretamente na quantidade de iterações 

    double erroAbsoluto, x0, x1;
    x0 = a;
    x1 = b;
    int i = 0;
    do 
    {
        erroAbsoluto = fabs(x1 - x0);
        x0 = x1;
        x1 = (a + b) / 2;
        if (f(x1) * f(a) < 0) 
        {
            b = x1;
        } 
        else 
        {
            a = x1;
        }
        printf("-----Iteração %d-----\nx atual é: %lf\n\n", i = i+1, x0);
    } while (erroAbsoluto > epsilon && f(x1) != 0);

    return x0;
}
