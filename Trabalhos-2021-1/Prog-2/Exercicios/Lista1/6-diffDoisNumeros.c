# include <stdio.h>
#include <math.h>
int main()
{
    int a,b;
    printf("Digite um número: ");
    scanf("%d",&a);
    printf("Digite um número: ");
    scanf("%d", &b);
    if(a>b){
        printf("%d é maior que %d, e a diferenca é %d", a,b,a-b);
    }else{
        printf("%d é maior que %d, e a diferenca é %d", b,a,b-a);
    }
    return 0;
}
