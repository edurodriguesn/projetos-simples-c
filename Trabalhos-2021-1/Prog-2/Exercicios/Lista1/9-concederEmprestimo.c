#include <stdio.h>
#include <math.h>
int main()
{
    float a,b;
    printf("Digite o valor do seu salário:\nR$ ");
    scanf("%f",&a);
    printf("Digite o valor da prestação:\nR$ ");
    scanf("%f",&b);
    if(b>a*0.2){
        printf("Empréstimo não concedido");
    }else{
        printf("Empréstimo concedido");
    }
    
    return 0;
}
