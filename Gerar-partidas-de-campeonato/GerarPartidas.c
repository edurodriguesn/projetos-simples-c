#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int QntEquipes=6,IdaEvolta=1;//Se tem só ida, 2 se tem ida e volta
int i,j,k,l,m,Linha,Coluna,aux,val;
int a[15],b[15],LogColuna[6],PartidasPadrao[5][6],PartidasSorteadas[5][6];
char *nome[]={"Olimpio","Eduardo","Joao","Luiz","Luma","Caio"};
void OrganizarPartidas()
{
    k=0;
    for(i=0;i<QntEquipes;i++)//Equipes i
    {
        for(j=0;j<QntEquipes;j++)//Equipes j
        {
            if(i!=j&&i<j)//Nao podem ser iguais e definido que i é menor que j
            {
                a[k]=i; //A é casa
                b[k]=j; //B é fora
                k++;
                //A primeira equipe recebe todos os outros em casa, por exemplo 0, recebe todos em casa. 1 recebe 18 equipes em casa(pois 0 ja jogou com 1), 2 recebe 17, etc...
                //Cada indice de a[] e b[] representa um jogo. no total ocorrem (QntEquipes-1)*(QntEquipes/2)
                //Depois multiplica por IdaEvolta
            }
        }
    }
    k=QntEquipes-2;//Como ocorrem QntEquipes-1 jogos, e o indice começa em 0 (ex: 5º posição é [4]), subtrai 2 
    for(i=0;i<QntEquipes-1;i++)//Percorre o total de jogos de um time, (enfrenta todos menos ele mesmo)
    {
        PartidasPadrao[i][0]=a[k]; //A primeira partida de todas as rodadas são todas do time 0, com os demais. 
        PartidasPadrao[i][1]=b[k]; //O i é a linha (rodada, 0 é a coluna do time casa(sempre o 0, 1 do time fora). As colunas dos times casa é par, do fora são impar
        k--;//O primeiro enfrenta o ultimo, o segundo enfrenta o penultimo, etc... Por isso vai decrescendo, pois o primeiro jogo é do primeiro com o segundo, o ultimo caso
    }
    for(i=0;i<QntEquipes-1;i++)//Percorre todas as rodadas
    {
        k=PartidasPadrao[i][1]+1;
        //printf("%d\n",PartidasPadrao[i][1]+1);
        if(k==QntEquipes)//Volta pro começo se chegar na ultima equipe, e o numero é invalido como indice
            k=0;
        for(j=3;j<=QntEquipes-1;j+=2)//Começa a partir da segunda equipe fora, e sempre verifica a equipe fora. Para registrar todas as equipes fora
        {
            val=0;//Validador, por padrão é falso
            for(l=0;l<j;l++)//Verifica os times dos jogos já registrados anteriormente. Vai de 0 a j
            {
                if(k==PartidasPadrao[i][l])//Se o time k ja jogou em um jogo anterior
                {
                    val=1;//Validador verdadeiro
                    l=j;//break
                }
            }
            if(val==0)//Se não verificar time ja registrado na rodada
            {
                PartidasPadrao[i][j]=k;//Então o time k é registrado como time fora, da coluna j
            }
            k++;//Avança para o próximo time
            if(val==1)//Se verificar time repetido
                j-=2;//Retorna à mesma posição, pois no final do for, vai incrimentar 2, logo 3-2+2=3
            if(k==QntEquipes)//Se chegar ao final, volta pro começo
                k=0;
        }
        k=PartidasPadrao[i][QntEquipes-1]+1;//Comeeça depois do time fora do ultimo jogo
        if(k==QntEquipes)
            k=0;
        for(j=QntEquipes-2;j>=2;j-=2)//Começa a partir do ultimo time casa, decrescendeço para o inicio
        {
            val=0;//Validador por padrão é falso
            for(l=0;l<j;l++)//Verifica os jogos anteriores
            {
                if(PartidasPadrao[i][l]!=-1)
                    if(k==PartidasPadrao[i][l]||k==PartidasPadrao[i][l+2])
                    {
                        val=1;//Verifica se o time já jogou na rodada
                        l=j;
                    }
            }
            if(val==0)
            {
                PartidasPadrao[i][j]=k;
            }
            k++;
            if(val==1)
                j+=2;
            if(k==QntEquipes)
                k=0;
        }
    }
    for(i=0;i<QntEquipes-1;i++)
    {
        Linha=rand()%QntEquipes-1;
        k=0;
        for(j=0;j<QntEquipes/2;j++)
            LogColuna[j]=-1;
        if(PartidasPadrao[Linha][0]==-1)
            i--;
            else
            {
                for(j=0;j<=QntEquipes-2;j+=2)
                {
                    do
                    {
                        val=0;
                        Coluna=rand()%QntEquipes-1;
                        for(l=0;l<QntEquipes/2;l++)
                            if(Coluna==LogColuna[l])
                            {
                                val=1;
                                l=QntEquipes;
                            }
                    }
                    while(val==1||Coluna%2!=0);
                    LogColuna[k]=Coluna;
                    k++;
                    PartidasSorteadas[i][j]=PartidasPadrao[Linha][Coluna];
                    PartidasSorteadas[i][j+1]=PartidasPadrao[Linha][Coluna+1];
                }
                PartidasPadrao[Linha][0]=-1;
            }
    }
    k=0;
    for(i=0;i<(QntEquipes-1)*IdaEvolta;i++)
    {
        for(j=0;j<=QntEquipes-2;j+=2)
        {
            if(i<QntEquipes-1)
            {
                a[k]=PartidasSorteadas[i][j];
                b[k]=PartidasSorteadas[i][j+1];    
            }
            else
            {
                b[k]=PartidasSorteadas[i-(QntEquipes-1)][j];
                a[k]=PartidasSorteadas[i-(QntEquipes-1)][j+1];
            }
            k++;
        }
    }
}
void ExibirPlacares()
{
    k=0;
    for(i=0;i<(QntEquipes-1)*IdaEvolta;i++)
    {
        printf("-------------------------------\n            Rodada %d\n-------------------------------\n",i+1);
        for(j=0;j<QntEquipes/2;j++)
        {
            printf("%14s - %s\n",nome[a[k]],nome[b[k]]);
            k++;
        }
    }
}
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"");
    OrganizarPartidas();
    ExibirPlacares();
    return 0;
}