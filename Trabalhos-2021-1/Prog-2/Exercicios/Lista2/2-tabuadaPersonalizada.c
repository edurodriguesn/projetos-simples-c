#include <stdio.h>
#include <math.h>
int main()
{
    int x,a,z;
    printf("Digite o número: ");
    scanf("%d",&x);
    printf("Digite o começo da tabuada: ");
    scanf("%d", &a);
    printf("Digite o fim da tabuada: ");
    scanf("%d", &z);
    if(a<=z){
        while(a<=z){
            printf("%d x %d = %d \n", x, a, x*a);
            a=a+1;
        }
    }
    return 0;
}
