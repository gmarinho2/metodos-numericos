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