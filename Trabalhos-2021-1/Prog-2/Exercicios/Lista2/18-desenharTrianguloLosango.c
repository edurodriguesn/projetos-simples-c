#include <stdio.h>
int main(){
    int forma,qtd,lin,i,j,k,y=2,calc=1,aux=-1,val,l=0,caux,z=1;
    do{
    printf("Escolha a forma: triangulo(1) / losango(2)\n");
    scanf("%d",&forma);
    }
    while(forma<1 || forma>2);
    do{
        printf("Quantas linhas?: ");
        scanf("%d",&lin);
    }
    while(forma==2 && lin<3);
    int vcal[lin];
    vcal[0]=1;
    if(forma==1){
        for(i=1;i<lin;i++){
            calc=calc+2;
            vcal[i]=calc;
        }
        for(i=1;i<=lin;i++){
            aux=aux+2;
            for(j=1;j<=calc-aux;j++){
                printf(" ");
            }
            for(k=1;k<=vcal[i-1];k++){
                    printf("%%");
                }
            printf("\n");
        }
    }else{
        if(lin%2==0){
            qtd=lin/2;
            val=0;
        }else{
            qtd=(lin/2)+1;
            val=1;
        }
        int vaux[qtd];
        for(i=1;i<qtd;i++){
            calc=calc+4;
            vcal[i]=calc;
        }
        if(val==0){
            calc=(calc+4)/2;
        }else{
            calc=(calc/2)+1;
        }
        for(i=1;i<=lin;i++){
            if(i<=qtd){
                aux=aux+2;
                caux=calc-aux;
                if(val==1){
                    for(j=1;j<=caux;j++){
                        printf(" ");
                        vaux[i-1]=caux;
                        if(j+1-caux==0){
                            vaux[i]=(caux)-2;
                    }
                    }
                    for(k=1;k<=vcal[i-1];k++){
                        printf("%%");
                    }
                }else{
                    for(j=1;j<caux;j++){
                        printf(" ");
                        vaux[i-1]=(caux)+1;
                        if(j+1-caux==0){
                            vaux[i]=(caux)-1;
                        }
                    }
                    for(k=1;k<=vcal[i-1];k++){
                        printf("%%");
                    }
                }
            }else{
                if(val==1){
                    for(j=vaux[l];j<=calc;j++){
                        printf(" ");
                    }
                    l++;
                    for(k=1;k<=vcal[qtd-y];k++){
                        printf("%%");
                    }
                    y++;
                    }else{
                        for(j=vaux[l];j<calc;j++){
                            printf(" ");
                        }
                    l++;
                    for(k=1;k<=vcal[qtd-z];k++){
                        printf("%%");
                    }
                    z++;
                    }
                }
            printf("\n");
        }
    }
    return 0;
}