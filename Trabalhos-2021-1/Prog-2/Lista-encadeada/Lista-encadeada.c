#include <stdio.h>
#include <stdlib.h>
typedef struct lista 
{
	int numero;
	Lista *proximo;
	Lista *anterior;
}Lista;
Lista *inicio,*fim;
int tamanho=0;
void insereInicio(int numero) 
{
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->numero = numero;
	novo->anterior = NULL;
	novo->proximo = NULL;
	//verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
	if(inicio==NULL)
	{
		inicio=novo;
		fim=novo;

	//Se a lista já tiver dado se cria outro lista e aponta o ant para o dado 2 e prox do dado 2 para o 1.
	}
	else
	{
		Lista *aux; //criar novo lista caso tenha dado no inicio da lista.
		aux = inicio;
		novo->proximo = aux;
		aux->anterior = novo;
		inicio = novo;
	}
	tamanho++;
}

//Inserir no fim da lista:
void insereFim(int numero) 
{
	Lista *novo = aloca(numero);   //criar novo lista
	//verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
	if(inicio==NULL)
	{
		inicio=novo;
		fim=novo;
	//Se a lista já tiver dado se cria outro lista e aponta o ant para o dado 2 e prox do dado 2 para o 1.
	}
	else
	{
		Lista *aux; //criar novo lista caso tenha dado no inicio da lista.
		aux = fim;
		novo->anterior = aux;
		aux->proximo = novo;
		fim = novo;
	}
	tamanho++;
}

//Inserir no inicio da lista:
void inserePosicao(int numero, int posicao) {
	posicao = posicao-1;
	Lista *novo = aloca(numero);   //criar novo lista
	//verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
	if(inicio==NULL)
	{
		inicio=novo;
		fim=novo;
	//Se a lista já tiver dado se cria outro lista e aponta o ant para o dado 2 e prox do dado 2 para o 1.
	}
	else
	{
		Lista *aux; //criar novo lista caso tenha dado no inicio da lista.
		Lista *tmp;
		int i;

		// Decidindo o ponto de incio
		if (posicao < (tamanho/2)) 
		{
			aux = inicio;
			i = 0;
		} 
		else 
		{
			aux = fim;
			i = tamanho;
		}

		// Percorrer para encontrar a posição
		while ((i != posicao) && (i >= 0) && (i <= tamanho)) 
		{
			if (i < posicao) 
			{
				i++;
				aux = aux->proximo;
			} else if (i > posicao) {
				i--;
				aux = aux->anterior;
			}

			if (posicao == i) {
				// novo->anterior = 
				// novo->proximo =
				// aux = novo;
				printf("Valor antecessor ao quero inserir %d\n", aux->anterior->numero);
				printf("Valor proximo ao quero inserir %d\n", aux->proximo->numero);
			}
		}



	}
	tamanho++;
}
void removeInicio() 
{
	Lista *aux = inicio;
	inicio = aux->proximo;
	inicio->anterior = NULL;
	tamanho--;
}
void removeFim() 
{
	Lista *aux = fim;
	fim = aux->anterior;
	fim->proximo = NULL;
	tamanho--;
}
/*void removePosicao(int posicao)
{
    if(posicao<=tamanho()-1)
    {
        aux = inicio;
        while(posicao>1) 
        {
            aux = aux->proximo;
            posicao--;
        }
        Lista *morta;
        morta = aux->proximo;
        aux->proximo = morta->proximo;
        tamanho--;
    }
    else
        printf("Posicao inexistente na lista\n");
}*/
void listar() 
{
	Lista *aux;
	aux = inicio;
	while(aux)
	{
		printf("%d\n",aux->numero);
		aux=aux->proximo;
	}
}
int main() {
	int escolha,posicaoexcluir;
    do
    {
        printf("1-Inserir\n2-Excluir\n3-Exibir específico\n4-Exibir tudo\n5-Encerrar\n");
        scanf("%d", &escolha);
        switch(escolha)
        {
            case 1:
                inserir();
                break;
            case 2:
                printf("Defina a posição que você deseja excluir: ");
                scanf("%d",&posicaoexcluir);
                if(posicaoexcluir==0)
                    removeInicio();
                    else if(posicaoexcluir==tamanho-1)
                        removeFim();
                        else
                            remove;
                break;
            case 3:
                visualizar();
                break;
            case 4:
                listar();
                break;
            case 5:
                break;
            default:
                printf("Inválido, tente novamente\n");
        }
    }
    while(escolha!=5);
    return 0;
}
