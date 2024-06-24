#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int cartas_dealer[2],cartas_jogador[2],i,soma_cartas_dealer=0,soma_cartas_jogador=0,jogada,nova_carta_jogador,vencedor=0;
bool carta_as[2];
void distribuir_cartas_dealer(){
    for(i=0;i<2;i++)
    {
        cartas_dealer[i]=(rand()%13)+1;
        if(cartas_dealer[i]==1) //se a carta for um as
            carta_as[0]=true;
        else if(cartas_dealer[i]>10) //qualquer valor acima de 10 vale 10
        {
            cartas_dealer[i]=10;
        }
        soma_cartas_dealer+=cartas_dealer[i];   
    }
    if(soma_cartas_dealer==11&&carta_as[0]) {//quando vem um as e um 10 é blackjack
        soma_cartas_dealer=21;
        vencedor=1;
    }
}

void distribuir_cartas_jogador(){
    for(i=0;i<2;i++) {
        cartas_jogador[i]=(rand()%13)+1;
        if(cartas_jogador[i]==1) //se a carta for um as
            carta_as[1]=true;
        else if(cartas_jogador[i]>10) //qualquer valor acima de 10 vale 10
        {
            cartas_jogador[i]=10;
        }
        soma_cartas_jogador+=cartas_jogador[i];
    }
    if(soma_cartas_jogador==11&&carta_as[1]) {//quando vem um as e um 10 é blackjack
        soma_cartas_jogador=21;
        vencedor=2;
    }
}

void pedir_ou_manter(){
    printf("Pedir(1)/Manter(2): ");
     do
        scanf("%d",&jogada);
    while(jogada<1||jogada>2);
    if(jogada==1)
    {   
        nova_carta_jogador=(rand()%10)+1;
        soma_cartas_jogador+=nova_carta_jogador;
        printf("Nova carta: %d - Total: %d\n",nova_carta_jogador,soma_cartas_jogador);
    } else {
        printf("Dealer: %2d |%2d = %2d\n",cartas_dealer[0],cartas_dealer[1],soma_cartas_dealer);
        if(soma_cartas_dealer>soma_cartas_jogador)
            vencedor=1;
        else if(soma_cartas_dealer<soma_cartas_jogador)
            vencedor=2;
        else
            vencedor = -1;
    }
    if(soma_cartas_jogador>21||soma_cartas_dealer==1)
        vencedor=1;
    else if(soma_cartas_dealer>21||soma_cartas_jogador==21)
        vencedor=2;
}
int main()
{
    srand(time(NULL));
    distribuir_cartas_dealer();
    distribuir_cartas_jogador();
    //adicionar a função de ás poder ser 11 ou 1
    printf("Dealer: %2d | ?\nVoce:   %2d | %2d = %2d\n",cartas_dealer[0],cartas_jogador[0],cartas_jogador[1],soma_cartas_jogador);
    while(vencedor==0) {
        pedir_ou_manter();
    }
    if(vencedor==1)
        printf("Vitoria do dealer");
    else if(vencedor==2)
        printf("Vitoria do jogador");
    else
        printf("Empate");
    return 0;
}
