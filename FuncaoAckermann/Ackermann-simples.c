#include <stdio.h>
int A(int m, int n)
{
    int resultado;
    if(m==0)
        resultado=n+1;
        else if(n==0)
            resultado=A(m-1,n=1);
            else
                resultado=A(m-1,A(m,n-1));
    return resultado;
}
int main()
{
    int m,n,resultado;
    printf("Informe m e n: ");
    scanf("%d%d",&m,&n);
    resultado=A(m,n);
    printf("Resultado: %d\n",resultado);
    return 0;
}
