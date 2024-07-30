#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dar_valores_aleatorios(int tamanho_vetor, int vetor[tamanho_vetor]) {
    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i] = rand() % 20;
    }
}

void definir_valores_manualmente(int tamanho_vetor, int vetor[tamanho_vetor]) {
    int valor;
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("Componente %d: ", i + 1);
        scanf("%d", &valor);
        vetor[i] = valor;
    }
}

void produto_vetorial(int vetor_A[3], int vetor_B[3], int vetor_C[3]) {
    vetor_C[0] = vetor_A[1] * vetor_B[2] - vetor_A[2] * vetor_B[1];
    vetor_C[1] = vetor_A[2] * vetor_B[0] - vetor_A[0] * vetor_B[2];
    vetor_C[2] = vetor_A[0] * vetor_B[1] - vetor_A[1] * vetor_B[0];
}

int main() {
    srand(time(NULL));

    int vetor_A[3];
    int vetor_B[3];
    int vetor_C[3];

    dar_valores_aleatorios(3, vetor_A);
    dar_valores_aleatorios(3, vetor_B);

    printf("Vetor A:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", vetor_A[i]);
    }
    printf("\n");

    printf("Vetor B:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", vetor_B[i]);
    }
    printf("\n");

    produto_vetorial(vetor_A, vetor_B, vetor_C);

    printf("Vetor resultante do produto vetorial:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", vetor_C[i]);
    }
    printf("\n");

    return 0;
}
