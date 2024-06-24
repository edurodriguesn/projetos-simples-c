#include <stdio.h>
#include <ctype.h>
int main()
{
    int poltrona[15][30],fileira,cadeira,bilheteria=0,qtd,i,j,k;
    for(j=0;j<15;j++)
    {
        for(k=0;k<30;k++)
        {
            poltrona[j][k]=0;
        }
    }
    do
    {
        printf("Quantos bilhetes serão comprados: ");
        scanf("%d",&qtd);
    }
    while(qtd<1||qtd>450);
    for(i=1;i<=qtd;i++)
    {
        printf("Escolha a fileira: ");
        scanf("%d",&fileira);
        printf("Escolha a poltrona: %d-",fileira);
        scanf("%d",&cadeira);
        if(poltrona[fileira-1][cadeira-1]!=1)
        {
            poltrona[fileira-1][cadeira-1]=1;
        }
        else
        {
            i--;
            printf("Poltrona indisponível\n");
        }
        for(j=0;j<15;j++)
        {
            for(k=0;k<30;k++)
            {
                if(j<2)
                {
                    if(poltrona[j][k]==1)
                    {
                        printf("x ");
                    }
                    else
                    {
                        printf("o ");
                    }
                }
                else if(j>10)
                {
                    if(poltrona[j][k]==1)
                    {
                        printf("x ");
                    }
                    else
                    {
                        printf("* ");
                    }
                }
                else
                {
                    if(poltrona[j][k]==1)
                    {
                        printf("x ");
                    }
                    else
                    {
                        printf("= ");
                    }
                }
            }
            printf("\n");
        }
        if(fileira-1<2)
            {
                printf("Valor do bilhete: R$ 100.00\n");
                bilheteria=bilheteria+100;
            }
            else if(fileira-1>10)
            {
                printf("Valor do bilhete: R$ 20.00\n");
                bilheteria=bilheteria+20;
            }
            else
            {
                printf("Valor do bilhete: R$ 60.00\n");
                bilheteria=bilheteria+60;
            }
    }
    printf("Valor total da bilheteria: R$ %d.00",bilheteria);
    
    return 0;
}
