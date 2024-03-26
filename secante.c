double secante(double (*funcao_ptr)(double), double x0, double x1, double epsilon)
{
    double erroAbsoluto;
    double x_proximo;

    do 
    {
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