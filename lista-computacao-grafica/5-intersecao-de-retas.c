#include <stdio.h>
#include <stdlib.h>

void ponto_de_intersecao(float coecifientes_1[3], float coecifientes_2[3], float *x, float *y) {
    float denominador = coecifientes_1[0] * coecifientes_2[1] - coecifientes_2[0] * coecifientes_1[1];
    
    if (denominador == 0) {
        printf("As retas são paralelas ou coincidentes e não têm um ponto de interseção único.\n");
        exit(1);
    }
    
    *x = (coecifientes_2[1] * coecifientes_1[2] - coecifientes_1[1] * coecifientes_2[2]) / denominador;
    *y = (coecifientes_1[0] * coecifientes_2[2] - coecifientes_2[0] * coecifientes_1[2]) / denominador;
}

int main() {
    float coecifientes_1[3];
    float coecifientes_2[3];
    float x, y;
    
    printf("Informe os coecifientes da primeira reta (a1 b1 c1): ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &coecifientes_1[i]);
    }
    
    printf("Informe os coecifientes da segunda reta (a2 b2 c2): ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &coecifientes_2[i]);
    }

    ponto_de_intersecao(coecifientes_1, coecifientes_2, &x, &y);

    printf("Ponto de intersecao: %.2f %.2f\n", x, y);

    return 0;
}
