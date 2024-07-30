#include <stdio.h>
#include <math.h>

float calcular_distancia(float ponto1[3], float ponto2[3]) {
    return sqrt(pow(ponto2[0] - ponto1[0], 2) + pow(ponto2[1] - ponto1[1], 2) + pow(ponto2[2] - ponto1[2], 2));
}

int questao6() {
    float ponto1[3];
    float ponto2[3];

    printf("Informe as coordenadas do ponto 1 (x1 y1 z1): ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &ponto1[i]);
    }

    printf("Informe as coordenadas do ponto 2 (x2 y2 z2): ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &ponto2[i]);
    }

    float distancia = calcular_distancia(ponto1, ponto2);

    printf("Distancia entre os pontos: %.2f\n", distancia);

    return 0;
}
