#include <stdio.h>
#include <string.h>
int main()
{
    char palavra[30],aux[30];
    int i,j=0,comparador=0;

    printf("Digite a palavra: ");
    scanf("%s",palavra);

    for(i=strlen(palavra);i>=0;i--) { //percorre da ultima para a primeira letra da palavra
        aux[j]=palavra[i-1]; //a string auxiliar recebe o inverso da palavra digitada
        j++; //incrementa o indice da auxiliar
    }
    for(i=0;i<strlen(palavra);i++) {
        if(palavra[i]!=aux[i]) {
            comparador++; //compara as duas palavras, se houver diferenca, incremtenta na variavel
        }
    }
    /* Alternativa usando a bibliteca string.h
    if (strcmp(palavra,aux)!=0){
        comparador=1;
        }*/
    if(comparador>0) {
        printf("Nao palindromo\n");
    } else {
        printf("Palindromo\n");
    }
    return 0;
}