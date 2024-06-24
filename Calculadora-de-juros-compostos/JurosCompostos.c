#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    float valor,taxa,quantidade_do_periodo,total;
    int tipotaxa,tipo_de_periodo;
    char identificao_de_periodo[6];

    printf("Valor R$: ");
    scanf("%f",&valor);
    printf("Taxa(%%): ");
    scanf("%f",&taxa);
    printf("1- Ao dia\n2- Ao mes\n3- Ao ano\n");
    do
        scanf("%d",&tipotaxa);
    while(tipotaxa<1||tipotaxa>3);

    printf("Seu periodo sera em:\n1- Dias\n2- Meses\n3- Anos\n");
    do
        scanf("%d",&tipo_de_periodo);
    while(tipo_de_periodo<1||tipo_de_periodo>3);

    if(tipo_de_periodo==1)
        strcpy(identificao_de_periodo,"Dias");
        else if(tipo_de_periodo==2)
            strcpy(identificao_de_periodo,"Meses");
            else
                strcpy(identificao_de_periodo,"Anos");

    printf("Quantidade de %s: ",identificao_de_periodo);
    scanf("%f",&quantidade_do_periodo);

    if(tipotaxa==1)
    {
        if(tipo_de_periodo==2)
            quantidade_do_periodo*=30;
            else if(tipo_de_periodo==3)
                quantidade_do_periodo*=365;
    }
    else if(tipotaxa==2)
    {
        if(tipo_de_periodo==1)
            quantidade_do_periodo/=30;
            else if(tipo_de_periodo==3)
                quantidade_do_periodo*=12;
    }
    else
        if(tipo_de_periodo==1)
            quantidade_do_periodo/=365;
            else if(tipo_de_periodo==2)
                quantidade_do_periodo/=12;

    total=valor*pow(1+(taxa/100),quantidade_do_periodo);

    printf("Total R$ %.2f",total);
    
    return 0;
}
