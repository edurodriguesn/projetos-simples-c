#include <stdio.h>
int main()
{
    int a,b;
    printf("Digite um número\n");
    scanf("%d",&a);
    printf("Digite outro número\n");
    scanf("%d",&b);
    if(a>b){
        printf("%d é maior",a);
    }else{
        printf("%d é maior",b);
    }
    return 0;
}
