#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i,j,TamVetor,Gerar,Alcance,*Vet,*Ordenado;
int count()
{
    int maior=0;
    for(i=0;i<TamVetor;i++)
        if(Vet[i]>maior)
            maior=Vet[i];
    maior=maior+1;
    int a[maior],b[maior],c[maior];
    for(i=0;i<maior;i++)
        a[i]=0;
    for(i=0;i<maior;i++)
        for(j=0;j<TamVetor;j++)
            if(Vet[j]==i)
                a[i]++;
    for(i=0;i<maior;i++)
        b[i]=a[i];
    j=0;
    for(i=1;i<maior;i++)
    {
        b[i]=a[i]+b[j];
        j++;
    }
    for(i=0;i<maior;i++)
        if(a[i]<b[i])
            c[i]=b[i]-a[i];
            else
                c[i]=a[i]-b[i];
    for(i=0;i<maior;i++)
        for(j=0;j<a[i];j++)
        {
            Ordenado[c[i]]=i;
            c[i]++;    
        }
    
    return 0;
}
int main()
{
    srand(time(NULL));
    printf("Informe o tamanho do seu vetor: ");
    scanf("%d",&TamVetor);
    Ordenado=(int *)malloc(sizeof(int)*TamVetor);
    Vet = (int *)malloc(sizeof(int)*TamVetor);
    printf("Digitar os valores(1) / Gerar valores(2): ");
    do
        scanf("%d",&Gerar);
    while(Gerar<1||Gerar>2);
    if(Gerar==1)
    {
        printf("Agora digite os valores:\n");
        for(i=0;i<TamVetor;i++)
            scanf("%d",&Vet[i]);
    }
    else
    {
        printf("Defina o alcance máximo dos valores: ");
        scanf("%d",&Alcance);
        for(i=0;i<TamVetor;i++)
            Vet[i]=rand()%(Alcance+1);
    }
    count();
    printf("Original: ");
    for(i=0;i<TamVetor;i++)
        printf("%2d | ",Vet[i]);
    printf("\nOrdenado: ");
    for(i=0;i<TamVetor;i++)
        printf("%2d | ",Ordenado[i]);
    return 0;
}


