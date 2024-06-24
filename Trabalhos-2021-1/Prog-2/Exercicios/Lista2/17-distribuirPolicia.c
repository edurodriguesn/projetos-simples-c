#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int ocor,grav,i,pol,vali=0,cops[3],homer=0,dir=0;
float perc,timer=0;
void registrar(){
    do{
        printf("Nova ocorrência: Direção Perigosa(1), Barulho(2), Bebedeira(3), Homer(4), encerrar(0)\n");
        scanf("%d",&ocor);
        if(ocor==1){
            dir++;
        }
    }
    while(ocor<0 || ocor>4);
        if(ocor!=4 && ocor!=0){
        do{
            printf("Gravidade: Baixa(1), Média(2), Alta(3)\n");
            scanf("%d",&grav);
        }
        while(grav<1 || grav>3);
    }
}
void distribuir(){
    if(ocor==4){
        cops[0]++;
        homer++;
    }else{
        if(timer<2 || cops[0]==cops[1] || cops[0]==cops[2] || cops[1]==cops[2]){
            do{
                srand(time(NULL));
                pol=rand()%3;
                if(cops[0]!=cops[1] || cops[2]!=cops[1] || cops[0]!=cops[2]){
                    if(pol==0 && cops[0]<cops[1]||cops[0]<cops[2]){
                        cops[0]++;
                        vali=1;
                    }else if(pol==1 && cops[1]<cops[0]||cops[1]<cops[2]){
                        cops[1]++;
                        vali=1;
                    }else if(pol==2 && cops[2]<cops[0]||cops[2]<cops[1]){
                        cops[2]++;
                        vali=1;
                    }
                    }else{
                    cops[pol]++;
                    vali=1;
                }
            }
            while(vali=0);
        }else{
            if(cops[0]<cops[1]&&cops[0]<cops[2]){
                cops[0]++;
            }else if(cops[1]<cops[0]&&cops[1]<cops[2]){
                cops[1]++;
            }else{
                cops[2]++;
            }
        }
    }
}
int main(){
    for(i=0;i<=2;i++){
        cops[i]=0;
    }
    do{
        registrar();
        distribuir();
        timer++;
        perc=(dir*100)/timer;
        printf("Ocorrências por policial:\nChefe Clancy: %d\nEddie: %d\nLou: %d\nOcorrências do Tipo Homer: %d\nPercentual de ocorrências Direçao Perigosa: %.2f%%\n",cops[0],cops[1],cops[2],homer,perc);
        vali=0;
    }
    while(ocor!=0);
    return 0;
}

