#include <stdio.h>

// Definição da estrutura Pessoa
typedef struct {
    int idade;
    float peso;
} Pessoa;

int main() {
    Pessoa alunos[3];

    // Loop para ler a idade e o peso das pessoas
    for (int i = 0; i < 3; i++) {
        printf("Digite a idade do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].idade);
        
        printf("Digite o peso do aluno %d (em kg): ", i + 1);
        scanf("%f", &alunos[i].peso);
    }

    // Exibir os dados das pessoas
    printf("\nDados dos alunos inseridos:\n");
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d: Idade = %d anos, Peso = %.2f kg\n", i + 1, alunos[i].idade, alunos[i].peso);
    }

    return 0;
}
