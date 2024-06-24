#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int i,numero,contagem=0,palpite;
    for(i=0;i<10;i++)
    {
        numero=(rand()%10)+1;
        printf("%d | ",numero);
        if(numero==1||numero==10)
            contagem--;
            else if(numero>1&&numero<7)
                contagem++;
    }
    printf("\nInforme a contagem: ");
    scanf("%d",&palpite);
    if(palpite==contagem)
        printf("acertou\n");
        else
            printf("errou\n");
    printf("Contagem: %d",contagem);
    
    return 0;
}
