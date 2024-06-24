#include <stdio.h>
#include <math.h>
int main()
{
    int a,b;
    printf("Digite um número: ");
    scanf("%d",&a);
    printf("Digite um número: ");
    scanf("%d",&b);
    if(a>b){
        printf("%d é maior", a);
    }else{
        if(b>a){
            printf("%d é maior",b);
        }else{
            printf("Números iguais");
        }
    }
    return 0;
}
