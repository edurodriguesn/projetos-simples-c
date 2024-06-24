#include <stdio.h>
#include <math.h>
int main()
{
    int a,n,r,i;
    printf("Digite o primeiro termo: ");
    scanf("%d", &a);
    printf("Digite o número de elementos: ");
    scanf("%d", &n);
    printf("Digite a razão da PA: ");
    scanf("%d",&r);
    for(i=1;i<=n;i++){
        printf("%d\n",a);
        a=a+r;
    }
    return 0;
}
