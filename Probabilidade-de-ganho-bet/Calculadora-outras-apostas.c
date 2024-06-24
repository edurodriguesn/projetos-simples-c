#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int i;
void fifa()
{
    float banca,unidade;
    int i=1;
    printf("Banca: R$ ");
    scanf("%f",&banca);
    while(banca<300)
    {
        if(banca<100)
            unidade=(banca-fmod(banca,10))/10;
            else
                unidade=((banca/10-fmod(banca/10,10))/10)*10;
        banca+=(unidade*1.5*2)-(unidade*2);
        printf("%dº | Unidade: R$ %.2f | Banca: R$ %.2f\n",i,unidade,banca);
        i++;
    }
}
void virtual()
{
    srand(time(NULL));
    float banca,unidade=0.05,percentual,x=0,v=0;
    int resultado, sequencia=0;
    printf("Banca: R$ ");
    scanf("%f",&banca);
    for(int i=0;i<300;i++)
    {
        if(banca*0.05<0.75)
            unidade=0.75/banca;
            else
                unidade=0.05;
        resultado = rand()%100;
        if(resultado>3)
        {
            sequencia++;
            banca += banca*unidade;
            printf("V: R$ %.2f | %d seguidos\n",banca,sequencia);
            v++;
        }
        else
        {
            banca -= banca*unidade*7;
            printf("X: R$ %.2f\n",banca);
            x++;
            sequencia=0;
        }
    }
    percentual=(v/(x+v))*100.0;
    printf("Banca final: R$ %.2f | GREEN: %.0f | RED: %.0f | Ganho: %.2f%%",banca,v,x,percentual);
}

void roleta()
{
    float banca,un, moeda=0.5;
    int red[51],entradas;
    printf("Banca: R$ ");
    scanf("%f",&banca);
    for(int k=0;k<23;k++)
    {
        printf("Entradas: ");
        scanf("%d",&entradas);
        printf("Numero do red:\n");
        for(i=0;i<50;i++)//-1 para terminar
            if(red[i-1]!=-1)
                scanf("%d",&red[i]);
                else
                    red[i]=-1;
        for(i=0;i<entradas;i++)
        {
            red[50]=0;
            un=(banca-fmod(banca,50))*0.01;
            if(banca<500)
                un=5;
            for(int j=0;j<entradas;j++)
                if(i==red[j])
                    red[50]=1;
            if(red[50]==1)
                if(banca<500)
                    banca-=136.5;
                    else
                        banca-=un*27.3;
            else
                banca+=un;
            printf("Final: R$ %.2f\n",banca);
        }
        printf("Final: R$ %.2f\n",banca);
        
    }
}
void ganho()
{
    float banca, unidade, odd, green, red, ganho;
    printf("Banca: R$ ");
    scanf("%f",&banca);
    printf("Unidade: R$ ");
    scanf("%f",&unidade);
    printf("Odd média: ");
    scanf("%f",&odd);
    printf("Green: ");
    scanf("%f",&green);
    printf("Red: ");
    scanf("%f",&red);
    ganho = banca - (red*unidade) + ((green*odd*unidade)-(green*unidade));
    printf("| Green: R$ %.2f - R$ %.2f = R$ %.2f | Red: R$ %.2f | Ganho: R$ %.2f (%.2f%%) |",green*odd*unidade, green*unidade, green*odd*unidade-green*unidade,red*unidade,ganho,banca/(ganho/100));
}
int main()
{
    int opcao;
    printf("1 - FIFA\n2 - Virtual\n3 - Ganho médio\n4 - Roleta\n: ");
    scanf("%d",&opcao);
    switch(opcao)
    {
        case 1:
            fifa();
            break;
        case 2:
            virtual();
            break;
        case 3:
            ganho();
            break;
        case 4:
            roleta();
            break;
        default:
            printf("Inválido");
    }
    return 0;
}






