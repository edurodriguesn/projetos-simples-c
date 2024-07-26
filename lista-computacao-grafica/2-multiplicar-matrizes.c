#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,j;
void dar_valores_aleatorios(int altura_matriz, int largura_matriz, int matriz[altura_matriz][largura_matriz]) {
    srand(time(NULL));
    for(i=0; i<altura_matriz; i++) {
        for(j=0; j<largura_matriz; j++) {
            matriz[i][j]=rand()%20;
        }
    }
}
void definir_valores_manualmente(int altura_matriz, int largura_matriz, int matriz[altura_matriz][largura_matriz]) {
    int valor;
    for(i=0; i<altura_matriz; i++) {
        for(j=0; j<largura_matriz; j++) {
            printf("Linha %d, coluna %d: ", i,j);
            scanf("%d",&valor);
            matriz[i][j]=valor;
        }
    }
}
int produtoMatrizes(int largura_matriz_A, int altura_matriz_B, int ) {

}
int main(){
    int altura_matriz_A, largura_matriz_A, altura_matriz_B, largura_matriz_B;
    printf("Informe a altura da matriz A: ");
    scanf("%d",&altura_matriz_A);
    printf("Informe a largura da matriz A: ");
    scanf("%d",&largura_matriz_A);
    printf("Informe a altura da matriz B: ");
    scanf("%d",&altura_matriz_B);
    printf("Informe a largura da matriz B: ");
    scanf("%d",&largura_matriz_B);
    if(largura_matriz_A != altura_matriz_B) {
        printf("As matrizes não podem ser multiplicadas devido ao princípio da multiplicabilidade");
    } else {
        int matriz_A[altura_matriz_A][largura_matriz_A];
        dar_valores_aleatorios(altura_matriz_A, largura_matriz_A, matriz_A);
        int matriz_B[altura_matriz_B][largura_matriz_B];
        dar_valores_aleatorios(altura_matriz_B, largura_matriz_B, matriz_B);
    }
    
    return 0;
}