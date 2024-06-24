#include <stdio.h>
#include <math.h>
int main()
{
    float a;
    printf("Digite um número: ");
    scanf("%f", &a);
    if(a>0){
        printf("%.2f\n",a*a);
        a=sqrt(a);
        printf("%.2f",a);
    }
    return 0;
}
