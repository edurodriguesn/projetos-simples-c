#include <stdio.h>
#include <math.h>
int main(){
    int q,i;
    int a=1;
    int b=1;
    printf("Quantos elementos da sequência de Fibonacci você quer exibir?: ");
    scanf("%d",&q);
    printf("1º: %d\n",a);
    if(q==2){
        printf("2º: %d\n",b);
    }
    if(q>2){
    for(i=2;i<q;i+=2){
        b=a+b;
        printf("%dº: %d\n%dº: %d\n",i,a,(i+1),b);
        a=a+b;
    }if(q%2==0){
        printf("%dº: %d\n",i,a);
    }}
    return 0;
}
