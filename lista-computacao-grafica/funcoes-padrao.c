#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i,j;
void dar_valores_aleatorios(int altura_matriz, int largura_matriz, float matriz[altura_matriz][largura_matriz]) {
    for(i=0; i<altura_matriz; i++) {
        for(j=0; j<largura_matriz; j++) {
            matriz[i][j]= ((float)rand() / RAND_MAX) * 20.0;
        }
    }
}
void definir_valores_manualmente(int altura_matriz, int largura_matriz, float matriz[altura_matriz][largura_matriz]) {
    float valor;
    for(i=0; i<altura_matriz; i++) {
        for(j=0; j<altura_matriz; j++) {
            printf("Linha %d, coluna %d: ", i,j);
            scanf("%f",&valor);
            matriz[i][j]=valor;
        }
    }
}