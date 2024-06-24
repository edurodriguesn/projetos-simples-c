#include <stdio.h>
int main(){
    int y,q,i;
    int s=0;
    int l=0;
    printf("De quantas pessoas você quer informar a idade?: ");
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        printf("Digite e %dª idade: ",i);
        scanf("%d",&y);
        if(y>=18){
        s=s+y;
        l=l+1;
        }
    }
    float m=s/l;
    printf("Soma dos maiores de idade: %d\n",s);
    printf("Média dessas idades: %f",m);
    return 0;
}
