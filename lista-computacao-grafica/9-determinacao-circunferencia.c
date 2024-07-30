#include <stdio.h>
#include <math.h>

// Função para calcular os coeficientes da equação da circunferência
void calcular_circunferencia(float pontos[3][2], float *h, float *k, float *r) {
    float x1 = pontos[0][0], y1 = pontos[0][1];
    float x2 = pontos[1][0], y2 = pontos[1][1];
    float x3 = pontos[2][0], y3 = pontos[2][1];

    float D = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    float x1_y1_2 = x1 * x1 + y1 * y1;
    float x2_y2_2 = x2 * x2 + y2 * y2;
    float x3_y3_2 = x3 * x3 + y3 * y3;

    *h = (x1_y1_2 * (y2 - y3) + x2_y2_2 * (y3 - y1) + x3_y3_2 * (y1 - y2)) / D;
    *k = (x1_y1_2 * (x3 - x2) + x2_y2_2 * (x1 - x3) + x3_y3_2 * (x2 - x1)) / D;
    *r = sqrt((x1 - *h) * (x1 - *h) + (y1 - *k) * (y1 - *k));
}

int main() {
    float pontos[3][2];
    float h, k, r;

    printf("Informe as coordenadas do ponto A (x1 y1): ");
    scanf("%f %f", &pontos[0][0], &pontos[0][1]);

    printf("Informe as coordenadas do ponto B (x2 y2): ");
    scanf("%f %f", &pontos[1][0], &pontos[1][1]);

    printf("Informe as coordenadas do ponto C (x3 y3): ");
    scanf("%f %f", &pontos[2][0], &pontos[2][1]);

    calcular_circunferencia(pontos, &h, &k, &r);

    printf("Coeficientes da equacao da circunferencia: h = %.2f, k = %.2f, r = %.2f\n", h, k, r);

    return 0;
}
