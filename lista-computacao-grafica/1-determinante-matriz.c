/*Escreva um programa que calcule o determinante de uma 
matriz quadrada de ordem_matriz n. O determinante é uma função que 
associa um único número a uma matriz quadrada, fundamental 
em várias áreas da álgebra linear.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,j;
void dar_valores_aleatorios(int ordem_matriz, int matriz[ordem_matriz][ordem_matriz]) {
    srand(time(NULL));
    for(i=0; i<ordem_matriz; i++) {
        for(j=0; j<ordem_matriz; j++) {
            matriz[i][j]=rand()%20;
        }
    }
}
void definir_valores_manualmente(int ordem_matriz, int matriz[ordem_matriz][ordem_matriz]) {
    int valor;
    for(i=0; i<ordem_matriz; i++) {
        for(j=0; j<ordem_matriz; j++) {
            printf("Linha %d, coluna %d: ", i,j);
            scanf("%d",&valor);
            matriz[i][j]=valor;
        }
    }
}
//função para atribuir os valores da matriz original à matriz temporária
void gerarSubmatriz(int ordem_matriz, int matriz[ordem_matriz][ordem_matriz], int submatriz[ordem_matriz-1][ordem_matriz-1], int linha_excluida, int coluna_excluida) {
    
    int i = 0, j = 0;
    for (int linha = 0; linha < ordem_matriz; linha++) {
        for (int coluna = 0; coluna < ordem_matriz; coluna++) {
            if (linha != linha_excluida && coluna != coluna_excluida) { //Quando a linha e a coluna estão dentro dos limites da nova matriz diminuída
                submatriz[i][j++] = matriz[linha][coluna]; //atribui o valor da matriz original e caminha uma coluna, para continuar atribuindo
                if (j == ordem_matriz - 1) { //quando chegar na ultima coluna
                    j = 0; //zera o valor da coluna
                    i++; //desce uma linha
                }
            }
        }
    }
}

//função para obter a determinante usando laplace
int determinante(int ordem_matriz, int matriz[ordem_matriz][ordem_matriz]) {
    if (ordem_matriz == 1) {
        return matriz[0][0]; //no caso de uma matriz 1x1, o determinante é o único valor
    }

    int submatriz[ordem_matriz-1][ordem_matriz-1];
    int determinante_valor = 0;

    for (int coluna_atual = 0; coluna_atual < ordem_matriz; coluna_atual++) {
        gerarSubmatriz(ordem_matriz, matriz, submatriz, 0, coluna_atual); //chama a função, informando que irá excluir remover a primeira linha e a coluna atual
        int sinal = (coluna_atual % 2 == 0) ? 1 : -1; //se a coluna atual for par, o sinal é positivo, se impar, negativo
        determinante_valor += sinal * matriz[0][coluna_atual] * determinante(ordem_matriz - 1, submatriz); //chama recursivamente a função
    }

    return determinante_valor;
}
int main(){
    int ordem_matriz;
    printf("Informe a ordem_matriz da matriz: ");
    scanf("%d",&ordem_matriz);
    int matriz[ordem_matriz][ordem_matriz];
    dar_valores_aleatorios(ordem_matriz, matriz);
    for(i=0; i<ordem_matriz; i++) {
        for(j=0; j<ordem_matriz; j++) {
            printf("%.2d ",matriz[i][j]);
        }
        printf("\n");

    }
    int valor_determinante = determinante(ordem_matriz, matriz);
    printf("Determinante da matriz: %d\n", valor_determinante);
    return 0;
}