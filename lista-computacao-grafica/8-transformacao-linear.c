#include <stdio.h>

void aplicar_transformacao(float T[2][2], float ponto[2], float ponto_transformado[2]) {
    ponto_transformado[0] = T[0][0] * ponto[0] + T[0][1] * ponto[1];
    ponto_transformado[1] = T[1][0] * ponto[0] + T[1][1] * ponto[1];
}

int questao8() {
    float T[2][2];
    int n;
    
    printf("Informe os valores da matriz de transformacao T (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%f", &T[i][j]);
        }
    }

    printf("Informe o numero de pontos: ");
    scanf("%d", &n);

    printf("Informe as coordenadas dos pontos:\n");
    float pontos[n][2], pontos_transformados[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &pontos[i][0], &pontos[i][1]);
        aplicar_transformacao(T, pontos[i], pontos_transformados[i]);
    }

    printf("Coordenadas dos pontos transformados:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f %.2f\n", pontos_transformados[i][0], pontos_transformados[i][1]);
    }

    return 0;
}
