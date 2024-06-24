#include <stdio.h>
#include <math.h>
int main()
{
    int x;
    int m=0;
    printf("Digite um número: ");
    scanf("%d",&x);
    do{
        m=m+1;
        if((x*m)%2!=0){
            printf("%d x %d = %d\n", x,m,x*m);
        }
    }
    while(m<=10);
    return 0;
}
