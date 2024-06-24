#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int numero_atual=rand()%20, maior_ou_menor, numero_sorteado, comparador_de_numeros, pontos=0;
    printf("Número inicial: %d\n",numero_atual);
    do
    {
        printf("O próximo será (1 - maior | 2 - menor): ");
        scanf("%d",&maior_ou_menor);
        do
            numero_sorteado=rand()%20;
        while(numero_sorteado==numero_atual);
        printf("(Número sorteado: %d) - ",numero_sorteado);
        if(numero_sorteado > numero_atual) {
            printf("Maior\n");
            comparador_de_numeros=1;
        } else  {
            printf("Menor\n");
            comparador_de_numeros=2;
        }
        numero_atual = numero_sorteado;
        if(comparador_de_numeros == maior_ou_menor)
            pontos++;
            else
                printf("Perdeu\n");
        printf("Pontuação final: %d\n\n",pontos);
    }
    while(comparador_de_numeros==maior_ou_menor);
    return 0;
}

