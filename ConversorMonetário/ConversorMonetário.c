#include <stdio.h>
#include <string.h>
#include <math.h>
int servico;
void venderbtc(float moeda1,float moeda2)
{
    float btc=moeda1/moeda2;
    char resultado[6];
    printf("Valor da BTC na venda: R$ ");
    scanf("%f",&moeda2);
    printf("Seu novo saldo de R$ em BTC é de R$ %.2f\n",btc*moeda2);
    if((btc*moeda2)-moeda1>=0)
        strcpy(resultado,"Lucro");
        else
            strcpy(resultado,"Perda");
    float diferenca=sqrt(pow((btc*moeda2)-moeda1,2));
    printf("%s: R$ %.2f",resultado,diferenca);
}
void exchange()
{
    float moeda1,moeda2;
    int continuar;
    char moedaa[4],moedab[4];
    if(servico==1)
    {
        printf("Informe a sigla ou símbolo da sua moeda atual: ");
        scanf("%s",moedaa);
        printf("Qual a sigla ou símbolo da moeda para qual você irá converter?: ");
        scanf("%s",moedab);
    }
    else
    {
        strcpy(moedaa,"R$");
        strcpy(moedab,"BTC");
    }
    printf("Quantos %s você possui?: ",moedaa);
    scanf("%f",&moeda1);
    printf("%s 1 custa quantos %s?: ",moedab,moedaa);
    scanf("%f",&moeda2);
    if(servico==1)
        printf("Seus %s %.2f valem %s %.2f",moedaa,moeda1,moedab,moeda1/moeda2);
        else
            printf("Você pode comprar %.8f Bitcoins com seus %s %.2f\n",moeda1/moeda2,moedaa,moeda1);
    printf("Você quer calcular quanto você teria após uma mudança no valor do %s?\n1-sim\n2-nao\n",moedab);
    do
        scanf("%d",&continuar);
    while(continuar<1||continuar>2);
    if(continuar==1)
        venderbtc(moeda1,moeda2);
}
void mensurar()
{
    float numero;
    char decimal[15];
    printf("Digite o valor: ");
    scanf("%f",&numero);
    if(numero>999)
    {
        if(numero<1000000)
        {
            strcpy(decimal,"mil");
            numero=numero/1000;
        }
        else if(numero>=1000000&&numero<1000000000)
        {
            numero=numero/1000000;
            if(numero<2)
                strcpy(decimal,"milhão");
                else
                    strcpy(decimal,"milhões");
        }
        else if(numero>=1000000000&&numero<1000000000000)
        {
            numero=numero/1000000000;
            if(numero<2)
                strcpy(decimal,"bilhão");
                else
                    strcpy(decimal,"bilhões");
        }
        else if(numero>=1000000000&&numero<1000000000000)
        {
            numero=numero/1000000000;
            if(numero<2)
                strcpy(decimal,"bilhão");
                else
                    strcpy(decimal,"bilhões");
        }
        else if(numero>=1000000000000&&numero<1000000000000000)
        {
            numero=numero/1000000000000;
            if(numero<2)
                strcpy(decimal,"trilhão");
                else
                    strcpy(decimal,"trilhões");
        }
    }
    else
        strcpy(decimal,"");
    int inteiro=(int)numero;
    if(numero-inteiro==0)
        printf("%d %s",inteiro,decimal);
        else
            printf("%.3f %s",numero,decimal);
}
int main()
{
    float moeda1,moeda2;
    printf("Escolha o serviço:\n1 - Conversão de moedas\n2 - Compra de bitcoins\n3 - Venda de bitcoins\n4 - Mensurar valor (milhar,milhão,etc)\n");
    scanf("%d",&servico);
    switch(servico)
    {
        case 1:
            exchange();
            break;
        case 2:
            exchange();
            break;
        case 3:
            printf("Valor gasto na compra: R$ ");
            scanf("%f",&moeda1);
            printf("Valor do BTC na compra: R$ ");
            scanf("%f",&moeda2);
            venderbtc(moeda1,moeda2);
            break;
        case 4:
            mensurar();
            break;
        default:
            printf("Inválido");
    }
    return 0;
}

//opcao comprar ou vender
