#include <stdio.h>
#include <math.h>
int main()
{
    int x, m;
    printf("Digite um número: ");
    scanf("%d",&x);
    for(m=1;m<=10;m++)
        if((x*m)%2==0)
            printf("%d x %d = %d \n",x,m,x*m);
    return 0;
}
