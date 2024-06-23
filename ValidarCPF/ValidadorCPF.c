#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char CPF[15];
char Alfabeto[] = "0123456789.-";
char StatusPadraoCPF[17];      // Aumentado para caber "Dentro do padrao"
char StatusValidadeCPF[9];     // Aumentado para caber "Invalido"

void VerificaPadrao(char CPF[15]) {
    int Pertencente; // Se o caractere lido está incluso no alfabeto
    for (int IndiceCPF = 0; IndiceCPF < 14; IndiceCPF++) { // Percorre todos os caracteres da string CPF
        Pertencente = 0; // Inicializa como não pertencente
        if (IndiceCPF != 3 && IndiceCPF != 7 && IndiceCPF != 11) { // Verifica se o índice não é '.' ou '-'
            for (int IndiceAlfabeto = 0; IndiceAlfabeto < 10; IndiceAlfabeto++) { // Percorre somente os números do alfabeto
                if (CPF[IndiceCPF] == Alfabeto[IndiceAlfabeto]) { // Compara se o caractere é reconhecido no alfabeto
                    Pertencente = 1; // Marca como pertencente
                    break; // Encerra a verificação
                }
            }
        } else if (IndiceCPF == 3 || IndiceCPF == 7) { // Verifica se o índice é '.'
            if (CPF[IndiceCPF] == Alfabeto[10]) {
                Pertencente = 1;
            }
        } else if (IndiceCPF == 11) { // Verifica se o índice é '-'
            if (CPF[IndiceCPF] == Alfabeto[11]) {
                Pertencente = 1;
            }
        }

        // Verifica a variável 'Pertencente'
        if (Pertencente == 0 || strlen(CPF) != 14) { // Se não pertence ao alfabeto ou se o tamanho do CPF não é 14
            strncpy(StatusPadraoCPF, "Fora do padrao", sizeof(StatusPadraoCPF)); // CPF fora do padrão
            StatusPadraoCPF[sizeof(StatusPadraoCPF) - 1] = '\0'; // Garante null-terminator
            return; // Encerra a função
        }
    }
    strncpy(StatusPadraoCPF, "Dentro do padrao", sizeof(StatusPadraoCPF)); // Se passou por todas as verificações
    StatusPadraoCPF[sizeof(StatusPadraoCPF) - 1] = '\0'; // Garante null-terminator
}

void ValidaCPF(char CPF[15]) {
    int Multiplicador = 10, Somatorio = 0; // Variáveis para a operação de validação do CPF
    int CPFValido = 1; // Assume CPF válido inicialmente
    char CaractereCPF[2]; // String para transformar caractere em int

    // Validação do primeiro dígito verificador
    for (int IndiceCPF = 0; IndiceCPF < 11; IndiceCPF++) {
        if (IndiceCPF != 3 && IndiceCPF != 7) { // Ignora '.' e '-'
            CaractereCPF[0] = CPF[IndiceCPF];
            CaractereCPF[1] = '\0';
            Somatorio += atoi(CaractereCPF) * Multiplicador;
            Multiplicador--;
        }
    }
    CaractereCPF[0] = CPF[12];
    CaractereCPF[1] = '\0';
    if ((Somatorio * 10) % 11 != atoi(CaractereCPF)) {
        CPFValido = 0;
    }

    // Validação do segundo dígito verificador
    Multiplicador = 11;
    Somatorio = 0;
    for (int IndiceCPF = 0; IndiceCPF < 13; IndiceCPF++) {
        if (IndiceCPF != 3 && IndiceCPF != 7 && IndiceCPF != 11) { // Ignora '.' e '-'
            CaractereCPF[0] = CPF[IndiceCPF];
            CaractereCPF[1] = '\0';
            Somatorio += atoi(CaractereCPF) * Multiplicador;
            Multiplicador--;
        }
    }
    CaractereCPF[0] = CPF[13];
    CaractereCPF[1] = '\0';
    if ((Somatorio * 10) % 11 != atoi(CaractereCPF)) {
        CPFValido = 0;
    }

    // Atualiza o status de validade do CPF
    if (CPFValido == 1) {
        strncpy(StatusValidadeCPF, "Valido", sizeof(StatusValidadeCPF));
    } else {
        strncpy(StatusValidadeCPF, "Invalido", sizeof(StatusValidadeCPF));
    }
    StatusValidadeCPF[sizeof(StatusValidadeCPF) - 1] = '\0'; // Garante null-terminator
}

int main() {
    printf("Informe seu CPF: ");
    scanf("%14s", CPF); // Lê até 14 caracteres do CPF
    VerificaPadrao(CPF); // Chama a função que verifica o padrão do CPF
    printf("Status do padrão do CPF: %s\n", StatusPadraoCPF); // Exibe o status do padrão

    if (strcmp(StatusPadraoCPF, "Dentro do padrao") == 0) { // Verifica se o CPF está dentro do padrão
        ValidaCPF(CPF); // Chama a função que verifica a validade do CPF
        printf("Status de Validade do CPF: %s\n", StatusValidadeCPF); // Exibe o status da validade
    }

    return 0;
}
