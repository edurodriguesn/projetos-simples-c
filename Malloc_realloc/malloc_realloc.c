#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ponteiro, valor = 1;
    ponteiro=(int *)malloc(sizeof(int)*1); //aloca o valor 1 para o ponteiro, assim passa a ter 1 valor
    for(int i=0; i<5; i++) {
        ponteiro=(int *)realloc(ponteiro,sizeof(int)*i+1); //realoca  o tamanho do ponteiro para poder receber outro valor
        ponteiro[i]=valor;
        valor++;
    }
    for(int i=0;i<5;i++){
        printf("%d\n",ponteiro[i]);
    }    
    free(ponteiro); //libera o espaço que foi alocado na memória
    return 0;
}