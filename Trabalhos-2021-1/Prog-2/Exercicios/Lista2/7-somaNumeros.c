#include <stdio.h>
#include <math.h>
int main(){
    int n,i;
    float x;
    float s=0;
    printf("Quantos números você quer digitar?: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("%dº número: ",i);
        scanf("%f",&x);
        s=s+x;
    }
    printf("Soma: %f",s);
    return 0;
}

