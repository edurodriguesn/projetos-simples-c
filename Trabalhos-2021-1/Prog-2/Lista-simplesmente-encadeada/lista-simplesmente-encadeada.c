#include <stdio.h>
#include <stdlib.h>
typedef struct Lista
{
    int numero;
    struct Lista *proximo;
}Lista;
struct Lista *novo,*inicio,*fim,*aux;
int tamanho=0;
void inserirInicio(int numero)
{
    novo = malloc(sizeof(Lista));//recebe o tamanho da struct(passa a suportar numero e proximo)
    novo->numero=numero;
    if(!inicio)
    {
        inicio=novo;
        fim=novo;
        fim->proximo=NULL;//sempre é nulo
    }
    else
    {
        novo->proximo=inicio;
        inicio=novo;
    }
    tamanho++;
}
void inserirFim(int numero)
{
    novo=malloc(sizeof(Lista));
    novo->numero=numero;
    int posicao=tamanho-1;
    aux=inicio;
    while(posicao>0)
    {
        aux=aux->proximo;
        posicao--;
    }
    aux->proximo=novo;
    fim=novo;
    fim->proximo=NULL;
    tamanho++;
    //novo->proximo=NULL;
}
void inserirEntre(int numero,int posicao)
{
    novo=malloc(sizeof(Lista));
    novo->numero=numero;
    aux=inicio;
    while(posicao>1)
    {
        aux=aux->proximo;
        posicao--;
    }
    Lista *insercao;
    insercao=aux->proximo;
    aux->proximo=novo;
    novo->proximo=insercao;
    tamanho++;
}
void excluirInicio()
{
    inicio=inicio->proximo;
    tamanho--;
}
void excluirFim()
{
    int posicao=tamanho-2;
    aux=inicio;
    while(posicao>1)
    {
        aux=aux->proximo;
        posicao--;
    }
    fim=aux->proximo;
    fim->proximo=NULL;
    tamanho--;
}
void excluirEntre(int posicao)
{
    aux=inicio;
    while(posicao>1)
    {
        aux=aux->proximo;
        posicao--;
    }
    Lista *lixeira;
    lixeira=aux->proximo;
    aux->proximo=lixeira->proximo;
    tamanho--;
}
void exibirTudo()
{
    int k=0;
    aux=inicio;
    while(k<tamanho)
    {
        printf("%d|",aux->numero);
        aux=aux->proximo;
        k++;
    }
    printf("\n\n");
}
void exibirEspecifico(int posicao)
{
    aux=inicio;
    int lembrarposicao=posicao,continuar;
    while(posicao>0)
    {
        aux=aux->proximo;
        posicao--;
    }
    printf("Valor na posição %d: %d\n",lembrarposicao,aux->numero);
    if(lembrarposicao+1<tamanho)
    {
        printf("1 - Exibir próximo\n2 - Voltar\n");
        do
            scanf("%d",&continuar);
        while(continuar<0||continuar>2);
        if(continuar==1)
            exibirEspecifico(lembrarposicao+1);
    }
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
                if(tamanho==0)
                    inserirInicio(numero);
                    else
                    {
                        printf("1-Inicio\n2-Fim\n3-Informar posicao\n: ");
                        scanf("%d",&tipodeposicao);
                        do
                        {
                            controle=0;
                            if(tipodeposicao==1||posicao==0)
                                inserirInicio(numero);
                                else if(tipodeposicao==2||posicao==tamanho)
                                    inserirFim(numero);
                                else
                                {
                                    printf("Posição: ");
                                    do
                                        scanf("%d",&posicao);
                                    while(posicao>tamanho);
                                    if(posicao>0&&posicao<tamanho)
                                        inserirEntre(numero,posicao);
                                        else
                                            controle=1;
                                }
                        }
                        while(controle==1);
                    }
                break;
            case 2:
                if(tamanho>0)
                {
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
                }
                break;
            case 3:
                exibirTudo();
                break;
            case 4:
                printf("Informe a posicao: ");
                do
                    scanf("%d",&posicao);
                while(posicao<0||posicao>tamanho-1);
                exibirEspecifico(posicao);
                break;
            case 5:
                printf("Tamanho: %d\n",tamanho);
        }
                    
    }
    while(opcao!=6);
    return 0;
}