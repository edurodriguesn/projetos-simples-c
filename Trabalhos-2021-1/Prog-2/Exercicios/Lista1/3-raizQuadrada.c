#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    printf("Digite seu número\n");
    scanf("%d",&a);
    float b=sqrt(a);
    
    if(a>=0){
        printf("%.2f",b);
    }else{
        printf("%.d",a*a);
    }
    return 0;
}

