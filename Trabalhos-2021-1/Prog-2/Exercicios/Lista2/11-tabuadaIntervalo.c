#include <stdio.h>
int main(){
    int x,q,qq,m,i;
    printf("Digite o número: ");
    scanf("%d",&x);
    printf("Começa em: ");
    scanf("%d",&q);
    printf("Termina em: ");
    scanf("%d",&qq);
    if(q>qq){
        for(i=q;i>=qq;i--){
            printf("%d x %d = %d\n",x,i,x*i);
        }
    }else{
    for(i=q;i<=qq;i++){
        printf("%d x %d = %d\n",x,i,x*i);
    }}
    return 0;
}
