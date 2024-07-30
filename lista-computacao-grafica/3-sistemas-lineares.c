#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dar_valores_aleatorios(int altura_matriz, int largura_matriz, float matriz[altura_matriz][largura_matriz]) {
    for (int i = 0; i < altura_matriz; i++) {
        for (int j = 0; j < largura_matriz; j++) {
            matriz[i][j] = (float)(rand() % 20);
        }
    }
}

void definir_valores_manualmente(int altura_matriz, int largura_matriz, float matriz[altura_matriz][largura_matriz]) {
    float valor;
    for (int i = 0; i < altura_matriz; i++) {
        for (int j = 0; j < largura_matriz; j++) {
            printf("Linha %d, coluna %d: ", i, j);
            scanf("%f", &valor);
            matriz[i][j] = valor;
        }
    }
}

void eliminacao_de_gauss(int qnt_equacoes, float matriz[qnt_equacoes][qnt_equacoes + 1]) {
    for (int i = 0; i < qnt_equacoes; i++) {
        float max_valor = abs(matriz[i][i]);
        int max_linha = i;
        for (int k = i + 1; k < qnt_equacoes; k++) {
            if (abs(matriz[k][i]) > max_valor) {
                max_valor = abs(matriz[k][i]);
                max_linha = k;
            }
        }
        for (int k = i; k < qnt_equacoes + 1; k++) {
            float temp = matriz[max_linha][k];
            matriz[max_linha][k] = matriz[i][k];
            matriz[i][k] = temp;
        }
        for (int k = i + 1; k < qnt_equacoes; k++) {
            float fator = matriz[k][i] / matriz[i][i];
            for (int j = i; j < qnt_equacoes + 1; j++) {
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
    for (int i = qnt_equacoes - 1; i >= 0; i--) {
        solucao[i] = matriz[i][qnt_equacoes] / matriz[i][i];
        for (int k = i - 1; k >= 0; k--) {
            matriz[k][qnt_equacoes] -= matriz[k][i] * solucao[i];
        }
    }
}

int main() {
    int qnt_equacoes;
    printf("Informe o numero de equacoes: ");
    scanf("%d", &qnt_equacoes);

    srand(time(NULL));

    float matriz[qnt_equacoes][qnt_equacoes + 1];
    
    definir_valores_manualmente(qnt_equacoes, qnt_equacoes + 1, matriz);
    for (int i = 0; i < qnt_equacoes; i++) {
        for (int j = 0; j < qnt_equacoes + 1; j++) {
            printf("%d ", (int)matriz[i][j]);
        }
        printf("\n");
    }

    eliminacao_de_gauss(qnt_equacoes, matriz);

    float solucao[qnt_equacoes];
    substituicao_regressiva(qnt_equacoes, matriz, solucao);

    printf("Solucoes do sistema:\n");
    for (int i = 0; i < qnt_equacoes; i++) {
        printf("%.2f ", solucao[i]);
    }
    printf("\n");

    return 0;
}
