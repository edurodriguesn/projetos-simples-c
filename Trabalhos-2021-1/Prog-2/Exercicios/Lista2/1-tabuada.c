#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    int b=0;
    printf("Digite um número: ");
    scanf("%d", &a);
    while(b<10){
        b=b+1;
        printf("%d x %d = %d \n", a,b, a*b);
    }
    return 0;
}
