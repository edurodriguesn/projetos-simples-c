#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    float valor = 50,lucro;
    int i,apostas,green,red,j;
    for(i=0; i<30;i++)
    {
        lucro=0;
        apostas = rand()%20;
        green=rand()%apostas;
        red=apostas-green;
        for(j=0;j<green;j++)
            lucro=(valor*0.05)*(((rand()/RAND_MAX)*0.7)+1.3);
        valor+=(valor+lucro)-(red*valor*0.05);
        printf("Dia %d = R$ %.2f Unidade: %.2f Lucro: %.2f%%\n",i,valor,valor*0.05,(lucro/valor)*100);
    }
    
    return 0;
}

