#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int QntElementos,i,j;
char **Elementos,**Resultado;
void DefinirValores(){
    Elementos = (char **)malloc(QntElementos * sizeof(char *));
}
void RealizarSorteio(int TipoDeSorteio, char *Elementos[]){
    int ResultaRepetido;
    if(TipoDeSorteio==1||TipoDeSorteio==2){
        int QntSorteada;
        printf("Quantos elementos devem ser sorteados?: ");
        do
            scanf("%d",&QntSorteada);
            while(QntSorteada<1);
        Resultado = (char **)malloc(QntSorteada * sizeof(char *));
        for(i=0;i<QntSorteada;i++){
            if(TipoDeSorteio==1){
                char NumeroConvertido[sizeof(char)];
                int NumeroSorteado;
                do{
                    NumeroSorteado = rand()%(atoi(Elementos[1]))-atoi(Elementos[0]);
                    sprintf(NumeroConvertido, "%d", NumeroSorteado);
                    for(j=0;j<i;j++){
                        if(strcmp(NumeroConvertido,Resultado[i])!=0)
                            ResultaRepetido=0;
                            else{
                                ResultaRepetido=1;
                                break;
                            }
                    }    
                }
                while(ResultaRepetido==1);
                Resultado[i]=NumeroConvertido;
                printf("%s",Resultado[i]);
            }
                
        }
    }
}
void PrepararSorteio(){
    int TipoDeSorteio, QntElementos;
    printf("Qual o tipo  de sorteio?: Sortear em um intervalo de números(1) | Sortear nomes(2) | Relacionar elementos(3))\n:");
    do
        scanf("%d",&TipoDeSorteio);
        while(TipoDeSorteio<1&&TipoDeSorteio>3);//Definir o tipo de sorteio
    if(TipoDeSorteio==1){//se o sorteio for de intervalo de números
        int ComeçoDoIntervalo, FinalDoIntervalo;
        QntElementos=2;
        char Começo[sizeof(int)], Final[sizeof(int)];
        printf("Sorteio vai de: ");
        scanf("%d",&ComeçoDoIntervalo);
        sprintf(Começo, "%d", ComeçoDoIntervalo);
        printf("Até: ");
        scanf("%d",&FinalDoIntervalo);
        sprintf(Final, "%d", FinalDoIntervalo);
        Elementos[0]=Começo;
        Elementos[1]=Final;
        RealizarSorteio(TipoDeSorteio, Elementos);
    }else if(TipoDeSorteio==2){
        
    }
}
int main()
{
    PrepararSorteio();
    srand(time(NULL));
    free(Elementos);
    return 0;
}

