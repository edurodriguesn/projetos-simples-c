#include <stdio.h>
#include <math.h>
int main()
{
    float ini,fim,fim_retangulo,inicio_retangulo,sigmarn=0,sigmaln=0;
    int i,qnt_subretangulos;
    double base;
    printf("O intervalo vai de: ");
    scanf("%f",&ini);
    printf("Ate: ");
    scanf("%f",&fim);
    if(fim<ini){
        float aux=ini;
        ini=fim;
        fim=aux;
    }
    printf("Informe quantos sub-retangulos voce quer usar para o calculo: ");
    scanf("%d",&qnt_subretangulos);
    base=(fim-ini)/qnt_subretangulos;
    float max[qnt_subretangulos],min[qnt_subretangulos];
    printf("No intervalo [%.2f,%.2f] dividindo a largura total em %d sub-retangulos obtemos uma largura de %.5lf para cada sub-retangulo aproximante\n",ini,fim,qnt_subretangulos,base);
    fim_retangulo=ini+base,inicio_retangulo=ini;
    for(i=0;i<qnt_subretangulos;i++){
        max[i]=pow(fim_retangulo,2);
        fim_retangulo=fim_retangulo+base;
        sigmarn=sigmarn+(max[i]*base);
    }
    printf("Somatorio de Rn: %.3f\n",sigmarn);
    fim_retangulo=ini+base,inicio_retangulo=ini;
    for(i=0;i<qnt_subretangulos;i++){
        min[i]=pow(inicio_retangulo,2);
        inicio_retangulo=inicio_retangulo+base;
        sigmaln=sigmaln+(min[i]*base);
    }
    printf("Somatorio de Ln: %.3f\n",sigmaln);
    printf("Dessa forma, a area do intervalo [%.2f,%.2f] na funcao x^2 esta entre Asup = %.3f e Ainf = %.3f\n\n",ini,fim,sigmarn,sigmaln);
    printf("- Por estar trabalhando com valores constantes o limite de cada somatorio e igual ao proprio somatorio\n- Ao dividir a largura da base total pelo numero de retangulos obtemos o mesmo que xi-(xi-1), sendo o valor igual para todos\n- Na funcao x^2 o valor minimo e o f(xi-1), ou seja, a imagem do primeiro valor no intervalo em questao\n- O valor maximo e a imagem do ultimo valor no intervalo em questao, no caso o f(xi)\n");
    printf("A forma como este programa foi construido e adaptada para as propriedades da funcao x^2, portanto nao representa uma forma geral de resolver integrais");
    return 0;
}
