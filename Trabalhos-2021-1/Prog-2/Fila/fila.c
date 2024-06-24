#include <stdio.h>
#include <stdlib.h>
typedef struct Fila
{
    int numero;
    struct Fila *frente;
    struct Fila *atras;
}Fila;
struct Fila *novo,*aux,*iniciofila,*fimfila;
int tamanho=0;
void inserir(int numero)
{
    novo=malloc(sizeof(Fila));
    novo->numero=numero;
    if(!iniciofila)
    {
        iniciofila=novo;
        fimfila=novo;
        iniciofila->frente=NULL;
        iniciofila->atras=fimfila;
        fimfila->frente=iniciofila;
        fimfila->atras=NULL;
    }
    else
    {
        fimfila->atras=novo;
        novo->frente=fimfila;
        fimfila=novo;
        fimfila->atras=NULL;
    }
    tamanho++;
}
void exibir(int posicao) //excluir funcao exibir tudo e adicionar na exibirespecifo
{
    aux=iniciofila;
    if(posicao==tamanho)
        while(posicao>0)
        {
            printf("%d|",aux->numero);
            aux=aux->atras;
            posicao--;
        }
    printf("\n\n");
}
int main()
{
    int opcao,controle,tipodeposicao,posicao,numero;
    do
    {
        printf("1 - Inserir      | 4 - Mostrar especifico\n2 - Excluir      | 5 - Exibir tamanho\n3 - Mostrar Tudo | 6 - Encerrar\n");
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
                printf("Informe o valor: ");
                scanf("%d",&numero);
                inserir(numero);
                break;
            /*case 2:
                printf("1 - Inicio\n2 - Fim\n3 - Informar posicão\n: ");
                do
                    scanf("%d",&tipodeposicao);
                while(tipodeposicao<1||tipodeposicao>3);
                posicao=-1;
                do
                {
                    controle=0;
                    if(tipodeposicao==1||posicao==0)
                        excluirInicio();
                        else if(tipodeposicao==2||posicao==tamanho-1)
                            excluirFim();
                            else
                            {
                                printf("Informe a posição: ");
                                do
                                    scanf("%d",&posicao);
                                while(posicao>=tamanho);
                                if(posicao>0&&posicao<tamanho-1)
                                    excluirEntre(posicao);
                                    else
                                        controle=1;
                            }
                }
                while(controle==1);
                break;*/
            case 3:
                exibir(tamanho);
                break;
            /*case 4:
                printf("Informe a posicao: ");
                do
                    scanf("%d",&posicao);
                while(posicao<0||posicao>tamanho-1);
                exibirEspecifico(posicao);
                break;
            case 5:
                printf("Tamanho: %d\n",tamanho);
                break;*/
        }
                    
    }
    while(opcao!=6);
    return 0;
}
//virar pilha
