#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    printf("Digite seu número: ");
    scanf("%d", &a);
    if(a%2!=0){
        printf("Impar");
    }else{
        printf("Par");
    }
    return 0;
}
