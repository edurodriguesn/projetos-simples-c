#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){
    char dado_parte_superior[]="|       |", dado_meio[]="|       |", dado_parte_inferior[]="|       |";
    
    char uma_unidade_central[]="|   o   |", duas_unidades[]="| o   o |", uma_unidade_direita[]="|     o |";
    
    srand(time(NULL));
    
    int valor_sorteado=(rand()%6)+1;
    
    if(valor_sorteado==1){
       strcpy(dado_meio,uma_unidade_central);
    }else if(valor_sorteado==2){
        strcpy(dado_meio,duas_unidades);
    }else if(valor_sorteado==3){
        strcpy(dado_parte_superior,uma_unidade_direita);
        strcpy(dado_meio,uma_unidade_central);
        strcpy(dado_parte_inferior,"| o     |");
    }else if(valor_sorteado==4){
        strcpy(dado_parte_superior,duas_unidades);
        strcpy(dado_parte_inferior,duas_unidades);
    }else if(valor_sorteado==5){
        strcpy(dado_parte_superior,duas_unidades);
        strcpy(dado_meio,uma_unidade_central);
        strcpy(dado_parte_inferior,duas_unidades);
    }else{
        strcpy(dado_parte_superior,duas_unidades);
        strcpy(dado_meio,duas_unidades);
        strcpy(dado_parte_inferior,duas_unidades);
    }
    printf(" _______ \n%s\n%s\n%s\n'-------'\n",dado_parte_superior,dado_meio,dado_parte_inferior);
}
