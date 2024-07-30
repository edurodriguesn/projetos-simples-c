#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,j,k;

void eliminacao_de_gauss(int qnt_equacoes, float matriz[qnt_equacoes][qnt_equacoes + 1]) {
    for (i = 0; i < qnt_equacoes; i++) {
        float max_valor = abs(matriz[i][i]);
        int max_linha = i;
        for (k = i + 1; k < qnt_equacoes; k++) {
            if (abs(matriz[k][i]) > max_valor) {
                max_valor = abs(matriz[k][i]);
                max_linha = k;
            }
        }
        for (k = i; k < qnt_equacoes + 1; k++) {
            float temp = matriz[max_linha][k];
            matriz[max_linha][k] = matriz[i][k];
            matriz[i][k] = temp;
        }
        for (k = i + 1; k < qnt_equacoes; k++) {
            float fator = matriz[k][i] / matriz[i][i];
            for (j = i; j < qnt_equacoes + 1; j++) {
                if (i == j) {
                    matriz[k][j] = 0;
                } else {
                    matriz[k][j] -= fator * matriz[i][j];
                }
            }
        }
    }
}

void substituicao_regressiva(int qnt_equacoes, float matriz[qnt_equacoes][qnt_equacoes + 1], float solucao[qnt_equacoes]) {
    for (i = qnt_equacoes - 1; i >= 0; i--) {
        solucao[i] = matriz[i][qnt_equacoes] / matriz[i][i];
        for (k = i - 1; k >= 0; k--) {
            matriz[k][qnt_equacoes] -= matriz[k][i] * solucao[i];
        }
    }
}

int questao3() {
    int qnt_equacoes;
    printf("Informe o numero de equacoes: ");
    scanf("%d", &qnt_equacoes);

    float matriz[qnt_equacoes][qnt_equacoes + 1];
    
    definir_valores_manualmente(qnt_equacoes, qnt_equacoes + 1, matriz);
    for (i = 0; i < qnt_equacoes; i++) {
        for (j = 0; j < qnt_equacoes + 1; j++) {
            printf("%d ", (int)matriz[i][j]);
        }
        printf("\n");
    }

    eliminacao_de_gauss(qnt_equacoes, matriz);

    float solucao[qnt_equacoes];
    substituicao_regressiva(qnt_equacoes, matriz, solucao);

    printf("Solucoes do sistema:\n");
    for (i = 0; i < qnt_equacoes; i++) {
        printf("%.2f ", solucao[i]);
    }
    printf("\n");

    return 0;
}
