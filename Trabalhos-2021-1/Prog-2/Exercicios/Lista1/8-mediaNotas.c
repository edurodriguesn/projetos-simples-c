#include <stdio.h>
#include <math.h>
int main()
{
    float a,b;
    printf("Digite a nota 1: ");
    do
        scanf("%f",&a);
    while(a<0 || a>10);
    printf("Digite a nota 2: ");
    do
        scanf("%f",&b);
    while(b<0 || b>10);
    printf("Média: %.2f",(a+b)/2);
    return 0;
}
