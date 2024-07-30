#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;

void produto_matrizes(int altura_matriz_A, int largura_matriz_A, float matriz_A[altura_matriz_A][largura_matriz_A], 
                     int altura_matriz_B, int largura_matriz_B, float matriz_B[altura_matriz_B][largura_matriz_B], 
                     float matriz_resultado[altura_matriz_A][largura_matriz_B]) {
    
    for (i = 0; i < altura_matriz_A; i++) {
        for (j = 0; j < largura_matriz_B; j++) {
            matriz_resultado[i][j] = 0;
        }
    }

    for (i = 0; i < altura_matriz_A; i++) {
        for (j = 0; j < largura_matriz_B; j++) {
            for (int k = 0; k < largura_matriz_A; k++) {
                matriz_resultado[i][j] += matriz_A[i][k] * matriz_B[k][j];
            }
        }
    }
}

void exibir_matriz(int altura_matriz, int largura_matriz, float matriz[altura_matriz][largura_matriz]) {
    for (i = 0; i < altura_matriz; i++) {
        for (j = 0; j < largura_matriz; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int questao2() {
    int altura_matriz_A, largura_matriz_A, altura_matriz_B, largura_matriz_B;

    printf("Informe a altura da matriz A: ");
    scanf("%d", &altura_matriz_A);
    printf("Informe a largura da matriz A: ");
    scanf("%d", &largura_matriz_A);
    printf("Informe a altura da matriz B: ");
    scanf("%d", &altura_matriz_B);
    printf("Informe a largura da matriz B: ");
    scanf("%d", &largura_matriz_B);

    if (largura_matriz_A != altura_matriz_B) {
        printf("As matrizes não podem ser multiplicadas devido ao princípio da multiplicabilidade\n");
    } else {
        float matriz_A[altura_matriz_A][largura_matriz_A];
        dar_valores_aleatorios(altura_matriz_A, largura_matriz_A, matriz_A);

        float matriz_B[altura_matriz_B][largura_matriz_B];
        dar_valores_aleatorios(altura_matriz_B, largura_matriz_B, matriz_B);

        float matriz_resultado[altura_matriz_A][largura_matriz_B];

        produto_matrizes(altura_matriz_A, largura_matriz_A, matriz_A, altura_matriz_B, largura_matriz_B, matriz_B, matriz_resultado);

        printf("Matriz A:\n");
        exibir_matriz(altura_matriz_A, largura_matriz_A, matriz_A);

        printf("Matriz B:\n");
        exibir_matriz(altura_matriz_B, largura_matriz_B, matriz_B);

        printf("Produto das matrizes:\n");
        exibir_matriz(altura_matriz_A, largura_matriz_B, matriz_resultado);
    }

    return 0;
}
