#include <stdio.h>
int vetorbinario[8],i;
int binario(int decimal)
{
    i=7;
    while(decimal>=1)
    {
        vetorbinario[i]=decimal%2;
        decimal=decimal/2;
        i--;
    }
    return 0;
}
void complemento_1()
{
    for(i=0;i<8;i++)
        if(vetorbinario[i]==0)
            vetorbinario[i]=1;
            else
                vetorbinario[i]=0;
}
void complemento_2()
{
    i=7;
    int aux=1;
    while(aux==1)
    {
        if(vetorbinario[i]==0)
        {
            vetorbinario[i]=1;
            aux=0;
        }
        else
        {
            vetorbinario[i]=0;
            i--;
        }
    }
}
int converterfinal(int complementar)
{
    int aux=64;
    for(i=1;i<8;i++)
    {
        complementar+=aux*vetorbinario[i];
        aux/=2;
    }
    return complementar;
}
int main()
{
    int decimal,complementar=0;
    for(i=0;i<8;i++)
        vetorbinario[i]=0;
    printf("Informe seu número: ");
    scanf("%d",&decimal);
    binario(decimal);
    for(i=0;i<8;i++)
        printf("%d",vetorbinario[i]);
    printf(" -> ");
    complemento_1();
    for(i=0;i<8;i++)
        printf("%d",vetorbinario[i]);
    printf(" -> ");
    complemento_2();
    for(i=0;i<8;i++)
        printf("%d",vetorbinario[i]);
    printf(" -> ");
    complementar=converterfinal(complementar);
    printf("%d",complementar);
    return 0;
}

