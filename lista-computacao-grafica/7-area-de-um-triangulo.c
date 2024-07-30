#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcular_area(float vertice1[2], float vertice2[2], float vertice3[2]) {
    return 0.5 * fabs(vertice1[0] * (vertice2[1] - vertice3[1]) + vertice2[0] * (vertice3[1] - vertice1[1]) + vertice3[0] * (vertice1[1] - vertice2[1]));
}

int main() {
    float vertice1[2];
    float vertice2[2];
    float vertice3[2];

    printf("Informe as coordenadas do vertice 1 (x1 y1): ");
    scanf("%f %f", &vertice1[0], &vertice1[1]);

    printf("Informe as coordenadas do vertice 2 (x2 y2): ");
    scanf("%f %f", &vertice2[0], &vertice2[1]);

    printf("Informe as coordenadas do vertice 3 (x3 y3): ");
    scanf("%f %f", &vertice3[0], &vertice3[1]);

    float area = calcular_area(vertice1, vertice2, vertice3);

    printf("Area do triangulo: %.2f\n", area);

    return 0;
}
