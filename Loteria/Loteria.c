#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int NumLoteria[6],NumSorteado[6],Constancia[60],AuxConstancia,NumConstante[6],NumConstanteii[6],maior,acerto,QtdSorteios,i,j,k,temp;
    srand(time(NULL));
    printf("Digite seus 6 números da loteria:\n");
    for(i=0;i<6;i++)
    {
        scanf("%d",&NumLoteria[i]);
        for(j=0;j<i;j++)
            if(NumLoteria[j]==NumLoteria[i])
            {
                i--;
                break;
            }
        if(NumLoteria[i]<1||NumLoteria[i]>60)
            i--;
    }
    for(i=1;i<6;i++)
    {
        if(NumLoteria[i]<NumLoteria[i-1])
        {
            temp=NumLoteria[i];
            NumLoteria[i]=NumLoteria[i-1];
            NumLoteria[i-1]=temp;
            i=0;
        }
    }
    for(i=0;i<60;i++)
        Constancia[i]=0;
    printf("Quantos sorteios você quer realizar?: ");
    scanf("%d",&QtdSorteios);
    printf("Seus numeros escolhidos:\n%d-%d-%d-%d-%d-%d\n",NumLoteria[0],NumLoteria[1],NumLoteria[2],NumLoteria[3],NumLoteria[4],NumLoteria[5]);
    for(i=0;i<QtdSorteios;i++)
    {
        //printf("Numeros do sorteio: ");
        acerto=0;
        for(j=0;j<6;j++)
        {
            NumSorteado[j]=rand()%60+1;
            for(k=0;k<j;k++)
                if(NumSorteado[k]==NumSorteado[j])
                {
                    j--;
                    break;
                }
        }
        for(j=1;j<6;j++)
        {
            if(NumSorteado[j]<NumSorteado[j-1])
            {
                temp=NumSorteado[j];
                NumSorteado[j]=NumSorteado[j-1];
                NumSorteado[j-1]=temp;
                j=0;
            }
        }
        for(j=0;j<6;j++)
        {
            if(NumSorteado[j]==NumLoteria[j])
                    acerto++;
            Constancia[NumSorteado[j]-1]++;
            //printf("%2d ",NumSorteado[j]);
        }
        //printf("| acertos: %d\n",acerto);
        if(acerto==6)
        {
            printf("Ganhou no Sorteio %d\n",i+1);
            break;
        }
        for(j=0;j<6;j++)
        {
            NumSorteado[j]=0;
        }
    }
    k=0;
    for(i=0;i<6;i++)
    {
        maior=0;
        for(j=k;j<k+10;j++)
        {
            if(Constancia[j]>maior)
            {
                maior=Constancia[j];
                AuxConstancia=j;
            }
        }
        k+=10;
        NumConstante[i]=AuxConstancia+1;
        
    }
    for(i=0;i<6;i++)
    {
        maior=0;
        for(j=0;j<60;j++)
        {
            if(Constancia[j]>maior)
            {
                maior=Constancia[j];
                AuxConstancia=j;
            }
        }
        Constancia[AuxConstancia]=0;
        NumConstanteii[i]=AuxConstancia+1;
    }
    for(i=1;i<6;i++)
    {
        if(NumConstante[i]<NumConstante[i-1])
        {
            temp=NumConstante[i];
            NumConstante[i]=NumConstante[i-1];
            NumConstante[i-1]=temp;
            i=0;
        }
    }
    for(i=1;i<6;i++)
    {
        if(NumConstanteii[i]<NumConstanteii[i-1])
        {
            temp=NumConstanteii[i];
            NumConstanteii[i]=NumConstanteii[i-1];
            NumConstanteii[i-1]=temp;
            i=0;
        }
    }
    printf("Números mais constantes por casa: ");
    for(i=0;i<6;i++)
        printf("%2d ",NumConstante[i]);
    printf("\n");
    printf("Números mais constantes geral:    ");
    for(i=0;i<6;i++)
        printf("%2d ",NumConstanteii[i]);
    return 0;
}
//50063860

