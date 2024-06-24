#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int i;
    float yy=0;
    int g[10];
    float s=0;
    for(i=0;i<=9;i++){
        printf("%dº: ",i+1);
        scanf("%d",&g[i]);
        s=s+g[i];
    }
    float m=s/10;
    for(i=0;i<=9;i++){
    if(g[i]<m){
        yy=((m-g[i])*(m-g[i]))+yy;
    }else{
        yy=((g[i]-m)*(g[i]-m))+yy;
    }
    }
    printf("Média: %f\n",m);
    printf("Desvio padrão: %f",sqrt(yy/10.0));
    return 0;
}

