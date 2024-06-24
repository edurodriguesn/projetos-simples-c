#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,j,k,l,m,Linha,Coluna,val,a[380],b[380],LogColuna[10],PartidasPadrao[19][20],PartidasSorteadas[19][20];
    k=0;
    //cada número de 0 a 19 corresponde a uma equipe
    //1-criar as equipes para cada jogo
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++) //1.1foram usados dois 'for' porque serão comparados dois times
        {
            if(i!=j&&i<j) //1.2 esse if garante que uma equipe não enfrenta a si mesma
            {
                a[k]=i;
                b[k]=j;
                k++; //1.3 cada posição é um jogo, no total são 190 jogos, 10 em cada rodada ao longo de 19 rodadas
            }
        }
    }
    //a matriz "PartidasPadrao" organiza todos os jogos em rodadas
    k=18; //nessa posição a=0 e b=19;
    //para testar use um for para exibir as 19 primeiras posições de 'a' e 'b'
    for(i=0;i<19;i++) //2- registrar os pontos fixos
    {
        //o 'i' são as linhas, cada linha é uma rodada, a cada duas colunas é um confronto (por exemplo coluna 0 e coluna 1, coluna 2 e coluna 3,...)
        PartidasPadrao[i][0]=a[k]; //2.1 o ponto fixo fica no começo de cada rodada, é um valor único, e alteram-se apenas seus adversãrios por rodada
        PartidasPadrao[i][1]=b[k]; //2.2 o valor do adversário diminui a cada rodada
        k--; //2.3 A cada posição decrescida o 'b' diminui em 1, e o 'a' permance como ponto fixo em 0.
    }
    //Agora o primeiro jogo de cada uma das 19 rodadas começa pelo time 0 e seu adversário
    for(i=0;i<19;i++)
    {
        //3- Esse 'for' vai organizar todos os jogos por rodada, garantindo que nenhum time irá jogar mais de uma vez em uma rodada (linha da matriz)
        //3- basicamente cada linha da matriz terá 20 números, e nenhum irá se repetir, cada par de números é um jogo
        k=PartidasPadrao[i][1]+1;
        if(k==20)
            k=0;
        for(j=3;j<=19;j+=2)
        {
            val=0;
            for(l=0;l<j;l++)
            {
                if(k==PartidasPadrao[i][l])
                {
                    val=1;
                    l=j;
                }
            }
            if(val==0)
            {
                PartidasPadrao[i][j]=k;
            }
            k++;
            if(val==1)
                j-=2;
            if(k==20)
                k=0;
        }
        k=PartidasPadrao[i][19]+1;
        if(k==20)
            k=0;
        for(j=18;j>=2;j-=2)
        {
            val=0;
            for(l=0;l<j;l++)
            {
                if(PartidasPadrao[i][l]!=-1)
                    if(k==PartidasPadrao[i][l]||k==PartidasPadrao[i][l+2])
                    {
                        val=1;
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
            if(k==20)
                k=0;
        }
    }
    for(i=0;i<19;i++)
    {
        Linha=rand()%19;
        k=0;
        for(j=0;j<10;j++)
            LogColuna[j]=-1;
        if(PartidasPadrao[Linha][0]==-1)
            i--;
            else
            {
                for(j=0;j<=18;j+=2)
                {
                    do
                    {
                        val=0;
                        Coluna=rand()%19;
                        for(l=0;l<10;l++)
                            if(Coluna==LogColuna[l])
                            {
                                val=1;
                                l=20;
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
    for(i=0;i<38;i++)
    {
        for(j=0;j<=18;j+=2)
        {
            if(i<19)
            {
                a[k]=PartidasSorteadas[i][j];
                b[k]=PartidasSorteadas[i][j+1];    
            }
            else
            {
                b[k]=PartidasSorteadas[i-19][j];
                a[k]=PartidasSorteadas[i-19][j+1];
            }
            k++;
        }
    }
    return 0;
}

