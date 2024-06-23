#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

int QtdPalavras = 0, i, IDPalavra, QtdErros = 0, ContadorTentativas = 0,PosicaoPalavra=0;
bool acertou, LetraRepetida;
char PalavraEscolhida[50], *PalavraForca, boneco[8] = {' ', ' ', ' ', ' ', ' ', ' ', '\0'}, letra[2], LogLetras[27] = {0};

void GerarPalavras(char *ListaPalavras[], char Palavra[50]) {
    for (int j = 0; j < strlen(Palavra); j++) {
        Palavra[j] = tolower(Palavra[j]); // Converte para minúsculas
    }
    strcpy(ListaPalavras[PosicaoPalavra], Palavra); // Armazena a palavra digitada na lista com letras minúsculas
    PosicaoPalavra++;
}

void DigitarPalavras(char ***ListaPalavras) {
    char Palavra[50];
    printf("Quantas palavras você quer cadastrar?: ");
    scanf("%d", &QtdPalavras);

    *ListaPalavras = (char **) realloc(*ListaPalavras, QtdPalavras * sizeof(char *)); // Redimensiona a lista de palavras

    for (i = 0; i < QtdPalavras; i++) {
        printf("Digite a palavra: ");
        scanf("%49s", Palavra);
        (*ListaPalavras)[i] = (char *) malloc((strlen(Palavra) + 1) * sizeof(char)); // Aloca memória para a nova palavra
        GerarPalavras(*ListaPalavras, Palavra); 
    }
}


void LerArquivo(char ***ListaPalavras) {
    char Palavra[50];
    FILE *arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo\n");
        return;
    }
    
    while (fgets(Palavra, sizeof(Palavra), arquivo) != NULL) {
        Palavra[strcspn(Palavra, "\n")] = '\0'; // Remove o caractere de nova linha, se presente
        QtdPalavras++;
        *ListaPalavras = (char **) realloc(*ListaPalavras, QtdPalavras * sizeof(char *)); // Redimensiona a lista de palavras
        (*ListaPalavras)[QtdPalavras - 1] = (char *) malloc((strlen(Palavra) + 1) * sizeof(char)); // Aloca memória para a nova palavra
        GerarPalavras(*ListaPalavras, Palavra);
    }
    fclose(arquivo);
}

void SortearPalavra(char *ListaPalavras[]) {
    IDPalavra = rand() % QtdPalavras; // Sorteia uma palavra na matriz de palavras
    
    strcpy(PalavraEscolhida, ListaPalavras[IDPalavra]); // Atribui a palavra escolhida da lista de palavras
    
    PalavraForca = (char *) malloc((strlen(PalavraEscolhida) + 1) * sizeof(char)); // Aloca o tamanho da palavra escolhida na string da forca
    
    for (i = 0; i < strlen(PalavraEscolhida); i++) {
        PalavraForca[i] = '-';
    }
    PalavraForca[strlen(PalavraEscolhida)] = '\0'; // Adiciona o terminador de string
}

void game() {
    LetraRepetida = false;
    acertou = false;

    for (i = 0; i < ContadorTentativas; i++) { // Verifica se a letra já foi digitada antes
        if (LogLetras[i] == letra[0]) {
            LetraRepetida = true;
            break;
        }
    }
    if (!LetraRepetida) {
        for (i = 0; i < strlen(PalavraForca); i++) { // Percorre toda a forca
            if (PalavraForca[i] == '-') { // Verificação quando a letra ainda não foi revelada
                if (PalavraEscolhida[i] == letra[0]) { // Se acertar uma letra
                    PalavraForca[i] = letra[0]; // Revela a letra na forca
                    acertou = true;
                }
            }
        }
        if (!acertou) {
            QtdErros++; // Aumentar o contador de erros
            switch (QtdErros) {
                case 1:
                    boneco[0] = 'O';
                    break;
                case 2:
                    boneco[1] = '/';
                    break;
                case 3:
                    boneco[2] = '|';
                    break;
                case 4:
                    boneco[3] = '\\';
                    break;
                case 5:
                    boneco[4] = '|';
                    break;
                case 6:
                    boneco[5] = '/';
                    break;
                case 7:
                    boneco[6] = '\\';
                    break;
                default:
                    break;
            }
        }
        LogLetras[ContadorTentativas] = letra[0]; // Armazena a letra no log para não haver repetições
        ContadorTentativas++;
    }
}

int main() {
    srand(time(NULL)); // Seta a semente de aleatoriedade
    char **ListaPalavras = NULL; // Inicializa a lista de palavras
    printf("1 - Digitar Palavras\n2 - Ler arquivo\n: ");
    int Opcao;
    do {
        scanf("%d", &Opcao);
    } while (Opcao != 1 && Opcao != 2);
    
    if (Opcao == 1) {
        DigitarPalavras(&ListaPalavras);
    } else {
        LerArquivo(&ListaPalavras);
    }
    
    SortearPalavra(ListaPalavras);
    
    printf(",--,\n|  %c\n| %c%c%c\n|  %c\n| %c %c\n|%s\n\n", boneco[0], boneco[1], boneco[2], boneco[3], boneco[4], boneco[5], boneco[6], PalavraForca);
    
    do {
        printf("Digite a letra: ");
        scanf("%1s", letra); // Limita a leitura a um caractere
        letra[0] = tolower(letra[0]);
        acertou = false;
        game();
        if (!LetraRepetida) {
            printf(",--,\n|  %c\n| %c%c%c\n|  %c\n| %c %c\n|%s\n\n", boneco[0], boneco[1], boneco[2], boneco[3], boneco[4], boneco[5], boneco[6], PalavraForca);
        } else {
            printf("Letra já escolhida\n");
            LetraRepetida = false;
        }
    } while (strcmp(PalavraForca, PalavraEscolhida) != 0 && QtdErros < 7);
    
    if (strcmp(PalavraForca, PalavraEscolhida) == 0) { 
        printf("Vitória\n");
    } else {
        printf("Derrota\n");
    }
    
    // Libera a memória alocada
    for (i = 0; i < QtdPalavras; i++) {
        free(ListaPalavras[i]);
    }
    free(ListaPalavras);
    free(PalavraForca);
    
    return 0;
}
