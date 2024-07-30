#include "funcoes-padrao.c"
#include "1-determinante-matriz.c"
#include "2-multiplicar-matrizes.c"
#include "3-sistemas-lineares.c"
#include "4-produto-vetorial.c"
#include "5-intersecao-de-retas.c"
#include "6-distancia-dois-pontos.c"
#include "7-area-de-um-triangulo.c"
#include "8-transformacao-linear.c"
#include "9-determinacao-circunferencia.c"
#include "10-projecao-ortogonal.c"
#include <stdio.h>

int main() {
    srand(time(NULL));
    int questao, ponto_de_parada=1;
    printf("1a Lista de Computacao Grafica\n");
    while(ponto_de_parada == 1){
        printf("Informe o numero da questao (1-10): ");
        do {
            scanf("%d",&questao);
        } while (questao<1 || questao > 10);
        switch(questao) {
            case 1:
                questao1();
                break;
            case 2:
                questao2();
                break;
            case 3:
                questao3();
                break;
            case 4:
                questao4();
                break;
            case 5:
                questao5();
                break;
            case 6:
                questao6();
                break;
            case 7:
                questao7();
                break;
            case 8:
                questao8();
                break;
            case 9:
                questao9();
                break;
            case 10:
                questao10();
                break;
        }
        printf("Outra Questao(1) / Terminar (0): ");
        scanf("%d",&ponto_de_parada);
    }
    
    return 0;
}