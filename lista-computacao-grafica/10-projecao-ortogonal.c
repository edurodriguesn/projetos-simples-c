#include <stdio.h>

float produto_escalar(float vetorA[3], float vetorB[3]) {
    return vetorA[0] * vetorB[0] + vetorA[1] * vetorB[1] + vetorA[2] * vetorB[2];
}

void projecao_ortogonal(float vetorA[3], float vetorB[3], float projecao[3]) {
    float produtoA_B = produto_escalar(vetorA, vetorB);
    float produtoB_B = produto_escalar(vetorB, vetorB);
    float escalar = produtoA_B / produtoB_B;
    projecao[0] = escalar * vetorB[0];
    projecao[1] = escalar * vetorB[1];
    projecao[2] = escalar * vetorB[2];
}

int questao10() {
    float vetorA[3], vetorB[3], projecao[3];

    printf("Informe os componentes do vetor A (A1 A2 A3): ");
    scanf("%f %f %f", &vetorA[0], &vetorA[1], &vetorA[2]);

    printf("Informe os componentes do vetor B (B1 B2 B3): ");
    scanf("%f %f %f", &vetorB[0], &vetorB[1], &vetorB[2]);

    projecao_ortogonal(vetorA, vetorB, projecao);

    printf("Vetor projecao de A sobre B: %.2f %.2f %.2f\n", projecao[0], projecao[1], projecao[2]);

    return 0;
}
