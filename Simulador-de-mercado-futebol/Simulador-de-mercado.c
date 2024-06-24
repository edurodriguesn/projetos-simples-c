#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
    char nome_jogador[15],clube_atual[15],continuar[1],novo_clube[15],nome_tipo_transferencia[15];
    int overall,variacao_overall,ano_atual,clube_sorteado,tipo_de_transferencia,tipo_de_processamento,anos_de_simulacao,i,idade_jogador,j;
void clube(){
    clube_sorteado=rand()%31;
    if(clube_sorteado==0){		
	    strcpy(novo_clube,"M. City");
	}else if(clube_sorteado==1){	
		strcpy(novo_clube,"Chelsea");
	}else if(clube_sorteado==2){	
		strcpy(novo_clube,"Liverpoveralll");
	}else if(clube_sorteado==3){	
		strcpy(novo_clube,"M. United");
	}else if(clube_sorteado==4){	
		strcpy(novo_clube,"Tottenham");
	}else if(clube_sorteado==5){	
		strcpy(novo_clube,"Arsenal");
	}else if(clube_sorteado==6){	
		strcpy(novo_clube,"Everton");
	}else if(clube_sorteado==7){	
		strcpy(novo_clube,"PSG");
	}else if(clube_sorteado==8){	
		strcpy(novo_clube,"Lyon");
	}else if(clube_sorteado==9){	
		strcpy(novo_clube,"Marseille");
	}else if(clube_sorteado==10){	
		strcpy(novo_clube,"Bayern");
	}else if(clube_sorteado==11){	
		strcpy(novo_clube,"BVB");
	}else if(clube_sorteado==12){	
		strcpy(novo_clube,"Leipzig");
	}else if(clube_sorteado==13){	
		strcpy(novo_clube,"Real Madrid");
	}else if(clube_sorteado==14){	
		strcpy(novo_clube,"Barcelona");
	}else if(clube_sorteado==15){	
		strcpy(novo_clube,"Atl. Madrid");
	}else if(clube_sorteado==16){	
		strcpy(novo_clube,"Sevilla");
	}else if(clube_sorteado==17){	
		strcpy(novo_clube,"Villareal");
	}else if(clube_sorteado==18){	
		strcpy(novo_clube,"Juventus");
	}else if(clube_sorteado==19){	
		strcpy(novo_clube,"Inter");
	}else if(clube_sorteado==20){	
		strcpy(novo_clube,"Milan");
	}else if(clube_sorteado==21){	
		strcpy(novo_clube,"Roma");
	}else if(clube_sorteado==22){	
		strcpy(novo_clube,"Napoli");
	}else if(clube_sorteado==23){	
		strcpy(novo_clube,"Lazio");
	}else if(clube_sorteado==24){	
		strcpy(novo_clube,"Atalanta");
	}else if(clube_sorteado==25){	
		strcpy(novo_clube,"Ajax");
	}else if(clube_sorteado==26){	
		strcpy(novo_clube,"PSV");
	}else if(clube_sorteado==27){	
		strcpy(novo_clube,"Galatasaray");
	}else if(clube_sorteado==28){	
		strcpy(novo_clube,"Shaktar");
	}else if(clube_sorteado==29){	
		strcpy(novo_clube,"Benfica");
	}else{	
		strcpy(novo_clube,"Porto");
	}
}
void ponto_de_parada(){
    do{
        printf("Continuar?(s/n): ");
        scanf("%s",continuar);
    }
    while(strcmp(continuar,"s")!=0 && strcmp(continuar,"n")!=0);
}
void processar_transferencia(){
    variacao_overall=(rand()%7)-3;
    overall+=variacao_overall;
    tipo_de_transferencia=rand()%3;
    ano_atual++;
    idade_jogador++;
    if(tipo_de_transferencia==0){
        do{
            clube();
        }
        while(strcmp(clube_atual,novo_clube)==0);
            strcpy(clube_atual,novo_clube);
            strcpy(nome_tipo_transferencia,"Transferencia");
    }else if(tipo_de_transferencia==2){
        do{
            clube();
        }
        while(strcmp(clube_atual,novo_clube)==0);
        strcpy(nome_tipo_transferencia,"Emprestimo");
    }else{
        strcpy(nome_tipo_transferencia,"Permanencia");
    }
}
int main(){
    srand (time(NULL));
    printf("Automático(1) ou Manual?(2): ");
    scanf("%d",&tipo_de_processamento);
    printf("Nome: ");
    scanf("%s",nome_jogador);
    printf("Overall: ");
    scanf("%d",&overall);
    printf("Clube: ");
    scanf("%s",clube_atual);
    printf("Idade: ");
    scanf("%d",&idade_jogador);
    printf("Ano: ");
    scanf("%d",&ano_atual);
    printf("%d:(%d)|%s| (%d)(%s) -\n",ano_atual,idade_jogador,nome_jogador,overall,clube_atual);
    if(tipo_de_processamento==2){
    do{
        processar_transferencia();
        if(tipo_de_transferencia==2){
            printf("%d:(%d)|%s| (%d)(%s) - %s |",ano_atual,idade_jogador,nome_jogador,overall,novo_clube,nome_tipo_transferencia);
        }else{
            printf("%d:(%d)|%s| (%d)(%s) - %s |",ano_atual,idade_jogador,nome_jogador,overall,clube_atual,nome_tipo_transferencia);
        }
        ponto_de_parada();
    }
    while(strcmp(continuar,"continuar")!=0);
    }else{
        printf("Quantos anos?: ");
        scanf("%d",&anos_de_simulacao);
        for(i=1;i<=anos_de_simulacao;i++){
            processar_transferencia();
            if(tipo_de_transferencia==2){
                printf("%d:(%d)|%s| (%d)(%s) - %s\n",ano_atual,idade_jogador,nome_jogador,overall,novo_clube,nome_tipo_transferencia);
            }else{
                printf("%d:(%d)|%s| (%d)(%s) - %s\n",ano_atual,idade_jogador,nome_jogador,overall,clube_atual,nome_tipo_transferencia);
            }
        }
    }
    return 0;
}
