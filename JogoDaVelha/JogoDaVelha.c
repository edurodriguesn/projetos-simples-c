#include <stdio.h>
int posicao_escolhida,valor_matriz[9],jogada_alternativa[5],indicador_de_vitoria=0,somatorio_de_jogadas=0,i,rodadas=0;
char desenho_matriz[9];
//valor_matriz representa as 9 posições do jogo e marca com 1 caso a posição tenha sido marcada pelo player1 e 10 caso tenha sido marcada pelo player2
void jogada(int id_jogador){
    do{
        printf("Jogador %d | Posição: ",id_jogador)+1;
        scanf("%d",&posicao_escolhida);
    }
    while(posicao_escolhida<1 || posicao_escolhida>9 || valor_matriz[posicao_escolhida-1]>-1); //verifica se o jogador digitou uma posição fora do intervalo ou já marcada
    valor_matriz[posicao_escolhida-1]=id_jogador;
}

void calculo_do_jogo(){
    for(i=0;i<9;i++){
        somatorio_de_jogadas+=valor_matriz[i]; //soma o valor contido na posição da matriz
        if(i==2){ //verifica a primeira linha horizontal
            if(somatorio_de_jogadas==3){ //caso tivessem só X
                indicador_de_vitoria=1;
                break;
            }else if(somatorio_de_jogadas==30){ //caso tivessem só O (bolinha)
                    indicador_de_vitoria=2;
                    break;
            }else{
                somatorio_de_jogadas=0; //zera o contador
            }
        }else if(i==5){ //verifica fileira do meio horizontal
            if(somatorio_de_jogadas==3){ //caso tivessem só X
                indicador_de_vitoria=1;
                break;
            }else if(somatorio_de_jogadas==30){ //caso tivessem só O (bolinha)
                indicador_de_vitoria=2;
                break;
            }else{
                somatorio_de_jogadas=0; //zera o contador
            }
        }else if(i==8){ //terceira fileira horizontal
            if(somatorio_de_jogadas==3){
                indicador_de_vitoria=1;
            }else if(somatorio_de_jogadas==30){
               indicador_de_vitoria=2;
            }else{ //se as fileiras horizontais não tiveram resultado, calcula as fileiras alternativas
                jogada_alternativa[0]=valor_matriz[8]+valor_matriz[5]+valor_matriz[4]; //soma as posições da terceira fileira vertical
                jogada_alternativa[1]=valor_matriz[7]+valor_matriz[4]+valor_matriz[1]; //soma as posições da fileira do meio vertical
                jogada_alternativa[2]=valor_matriz[6]+valor_matriz[3]+valor_matriz[0]; //soma as posições da primeira fileira vertical
                jogada_alternativa[3]=valor_matriz[8]+valor_matriz[4]+valor_matriz[0]; //soma as posições da diagonal principa)
                jogada_alternativa[4]=valor_matriz[6]+valor_matriz[4]+valor_matriz[2]; //soma as posições da diagonal secundaria
                if(jogada_alternativa[0]==3 || jogada_alternativa[1]==3 || jogada_alternativa[2]==3 || jogada_alternativa[3]==3 || jogada_alternativa[4]==3){
                    indicador_de_vitoria=1;
                }else if(jogada_alternativa[0]==30 || jogada_alternativa[1]==30 || jogada_alternativa[2]==30 || jogada_alternativa[3]==30 || jogada_alternativa[4]==30){
                    indicador_de_vitoria=2;
                }
            }
        }
        if(rodadas==9 && indicador_de_vitoria==0){
            indicador_de_vitoria=3;
        }
    }
}
void mostrar(){
    for(i=0;i<=8;i++){
        if(valor_matriz[i]==1){
            desenho_matriz[i]='X';
        }else if(valor_matriz[i]==10){
            desenho_matriz[i]='O';
        }else{
            desenho_matriz[i]=' ';
        }
    }
    printf(" %c | %c | %c\n---|---|---\n %c | %c | %c \n---|---|---\n %c | %c | %c\n",desenho_matriz[0],desenho_matriz[1],desenho_matriz[2],desenho_matriz[3],desenho_matriz[4],desenho_matriz[5],desenho_matriz[6],desenho_matriz[7],desenho_matriz[8]);
}
int main(){
    for(i=0;i<=8;i++){
        valor_matriz[i]=-1;
    }
    printf(" 1 | 2 | 3\n---|---|---\n 4 | 5 | 6 \n---|---|---\n 7 | 8 | 9\n");
    do{
        jogada(1);
        rodadas++;
        mostrar();
        calculo_do_jogo();
        if(indicador_de_vitoria==0){
            jogada(10);
            rodadas++;
            mostrar();
            calculo_do_jogo();
        }
    }
    while(indicador_de_vitoria==0);

    if(indicador_de_vitoria==3){
        printf("Empate\n");
    } else {
        printf("Vitória do jogador %d\n",indicador_de_vitoria);
    }

return 0;
}

