#include <stdio.h>
#include <math.h>
int main()
{
    int a,b;
    printf("Digite um número: ");
    do
        scanf("%d",&a);
    while(a<0);
    if(a<10)
        printf("%d",a);
    else{
        if(a>=10000 && a<100000){
            b=a/10000;
            a=a%10000;
            b=b+(a/1000);
            a=a%1000;
            b=b+(a/100);
            a=a%100;
            b=b+(a/10);
            a=a%10;
            b=b+a;
        }else if(a>=1000 && a<10000){
            b=a/1000;
            a=a%1000;
            b=b+(a/100);
            a=a%100;
            b=b+(a/10);
            a=a%10;
            b=b+a;
        }else if(a>=100 && a<1000){
            b=a/100;
            a=a%100;
            b=b+(a/10);
            a=a%10;
            b=b+a;
        }else if(a>=10 && a<100){
            b=a/10;
            a=a%10;
            b=b+a;
        }
        printf("Soma dos digitos: %d",b);
    }
        
    return 0;
}
