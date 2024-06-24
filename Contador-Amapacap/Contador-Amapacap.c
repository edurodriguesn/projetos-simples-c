#include <stdio.h>
int main()
{
    int Cartela[20],NumeroSorteado,Acertos;
    printf("Informe os seus números: \n");
    for (int i=0;i<20;i++)
        scanf("%d",&Cartela[i]);
    for(int i=0;i<3;i++)
    {
        Acertos=0;
        printf("||| %dº sorteio |||\n",i+1);
        for(int j=0;j<60;j++)
        {
            printf("Número sorteado: ");
            scanf("%d",&NumeroSorteado);
            for(int l=0;l<20;l++) {
                if(NumeroSorteado==Cartela[l])  {
                    Acertos++;
                    break;
                }
            }
            if(Acertos==20) {
                printf("Ganhou no %dº sorteio!\n",i+1);
                break;
            } else {
                printf("Números acertados: %d\nNúmeros sorteados: %d\nFaltam %d números para ganhar\n",Acertos,j+1,20-Acertos);
            }
        }
        if(Acertos<20)
            printf("%dº sorteio não ganho\n",i+1);
    }
    return 0;
}
