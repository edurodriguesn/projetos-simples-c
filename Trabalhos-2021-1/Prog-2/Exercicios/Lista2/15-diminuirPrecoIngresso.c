#include <stdio.h>
#include <math.h>
int main(){
    int a[8],i,p=120;
    float v[9],l[8],m,mm,ll=400;
    v[0]=4.5;
    printf("Informe o aumento de público a cada diminuição de preço\n");
    for(i=0;i<=7;i++){
        v[i+1]=v[i]-0.5;
        printf("(R$ %.2f) aumento: ",v[i]);
        scanf("%d",&a[i]);
        p=p+a[i];
        l[i]=(p*v[i])-200;
    }
    printf("Lucro em R$ 5.00: R$ %.2f\n",ll);
    v[0]=4.5;
    mm=5;
    m=ll;
    for(i=0;i<=7;i++){
        v[i+1]=v[i]-0.5;
        printf("Lucro em R$ %.2f: R$ %.2f\n",v[i],l[i]);
        if(l[i]>m){
            m=l[i];
            mm=v[i];
        }
    }
    printf("Maior lucro: R$ %.2f\nValor do ingresso: R$ %.2f",m,mm);
    return 0;
}
//diminuir qnd ter menos pessoas
