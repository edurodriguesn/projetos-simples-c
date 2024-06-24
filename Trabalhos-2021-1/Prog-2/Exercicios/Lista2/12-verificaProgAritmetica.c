#include <stdio.h>
int main(){
    int a,b,r,rr,y;
    int h=0;
    int i=1;
    do{
        printf("%dº: ",i);
        scanf("%d",&a);
        i++;
        if(i>2){
            rr=a-b;
            if(rr!=r){
                h++;
        }}
        if(i<9){
        printf("%dº: ",i);
        scanf("%d",&b);
        }
        i++;
        r=b-a;
    }while(i<10);
    if(h==0){
        printf("É progressão aritmética de razão %d",r);
    }else{
        printf("Não é progressão aritmética");
    }
    return 0;
}
