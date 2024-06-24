#include <stdio.h>
#include <string.h>
#include <ctype.h>
void i()
{
    int a, b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d+%d=%d",a,b,a+b);
}
void ii()
{
    float a,b;
    scanf("%f",&a);
    scanf("%f",&b);
    printf("%.2f+%.2f=%.2f\n%.2f-%.2f=%.2f\n%.2f*%.2f=%.2f\n%.2f/%.2f=%.2f",a,b,a+b,a,b,a-b,a,b,a*b,a,b,a/b);
}
void iii()
{
    float dist,comb;
    printf("Distancia total percorrida (km): ");
    scanf("%f",&dist);
    printf("Total de combustível gasto (L): ");
    scanf("%f",&comb);
    printf("Consumo médio: %.2f L/km",dist/comb);
}
void iv()
{
    char nome[20];
    float sal,ven;
    printf("Nome do vendedor: ");
    scanf("%s",nome);
    printf("Salário fixo: ");
    scanf("%f",&sal);
    printf("Vendas (R$): ");
    scanf("%f",&ven);
    printf("%s\nSalário fixo: %.2f\nSalário final: %.2f",nome,sal,sal+(ven*0.15));
}
void v()
{
    char nome[20];
    float n1,n2,n3;
    printf("Nome do aluno: ");
    scanf("%s",nome);
    printf("Informe as 3 notas: \n");
    scanf("%f",&n1);
    scanf("%f",&n2);
    scanf("%f",&n3);
    printf("%s\nMédia: %.2f",nome,(n1+n2+n3)/3);
}
void vi()
{
    int a,b,aux;
    printf("A: ");
    scanf("%d",&a);
    printf("B: ");
    scanf("%d",&b);
    aux=a;
    a=b;
    b=aux;
    printf("A: %d | B: %d",a,b);
}
void vii()
{
    float c,f;
    printf("Celsius: ");
    scanf("%f",&c);
    f=(9*c+160)/5;
    printf("%.2fºC = %.2fºF",c,f);
}
void viii()
{
    float conv,cart;
    printf("Quantos R$ vale US$ 1: ");
    scanf("%f",&conv);
    printf("Quantos dólares você tem?: ");
    scanf("%f",&cart);
    printf("Seu valor de US$ %.2f vale R$ %.2f",cart,conv*cart);
}
void ix()
{
    float cart;
    printf("Valor depositado: R$ ");
    scanf("%f",&cart);
    printf("Rendimento em um mês: R$ %.2f\nSaldo total: R$ %.2f",cart*0.07,cart+(cart*0.07));
}
void x()
{
    float val;
    printf("Valor da compra: R$ ");
    scanf("%f",&val);
    printf("Valor da prestação: R$ %.2f",val/5);
}
void xi()
{
    float cust,porc;
    printf("Preço de custo: R$ ");
    scanf("%f",&cust);
    printf("%% sobre o custo para venda: ");
    scanf("%f",&porc);
    printf("Valor da venda: R$ %.2f",cust+(cust*(porc/100)));
}
void xii()
{
    float custfab,aux;
    printf("Custo de fábrica do carro: R$ ");
    scanf("%f",&custfab);
    aux=(0.45*custfab)+custfab;
    printf("Custo do veículo para o consumidor: R$ %.2f",aux+(aux*0.28));
}
void xiii()
{
    int a;
    scanf("%d",&a);
    if(a>10)
    {
        printf("Maior que 10");
    }
}
void xiv()
{
    int a,b;
    do
    {
    scanf("%d",&a);
    scanf("%d",&b);
    }
    while(a==b);
    int maior=a;
    if(a<b)
    {
        maior=b;
    }
    printf("Maior: %d",maior);
}
void xv()
{
    int a;
    scanf("%d",&a);
    if(a>=100&&a<=200)
    {
        printf("%d está entre 100 e 200",a);
    }
}
void xvi()
{
    char nome[20];
    float n1,n2,n3;
    printf("Nome do aluno: ");
    scanf("%s",nome);
    printf("Notas:\n");
    scanf("%f",&n1);
    scanf("%f",&n2);
    scanf("%f",&n3);
    float med=(n1+n2+n3)/3;
    if(med>=7)
    {
        printf("%s\nAprovado",nome);
    }
    else if(med>=5.1&&med<=6.9)
    {
        printf("%s\nRecuperaçao",nome);
    }
    else
    {
        printf("%s\nReprovado",nome);
    }
}
void xvii()
{
    int a[80],i,acum=0;
    for(i=0;i<80;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=10&&a[i]<=150)
        {
            acum++;
        }
    }
    printf("%d números estão entre 10 e 150",acum);
}
void xviii()
{
    int idade,i;
    for(i=1;i<=75;i++)
    {
        scanf("%d",&idade);
        if(idade>=18)
        {
            printf("maior de idade\n");
        }
        else
        {
            printf("menor de idade\n");
        }
    }
}
void xix()
{
    char sex[10],nome[20];
    int hom=0,mul=0,i,j;
    for(i=1;i<=56;i++)
    {
        printf("Nome: ");
        scanf("%s",nome);
        do
        {
            printf("Sexo: ");
            scanf("%s",sex);
            for(j=0;j<strlen(sex);j++)
            {
                sex[j]=tolower(sex[j]);
            }
        }
        while(strcmp(sex,"mulher")!=0&&strcmp(sex,"f")!=0&&strcmp(sex,"feminino")!=0&&strcmp(sex,"homem")!=0&&strcmp(sex,"m")!=0&&strcmp(sex,"masculino")!=0);
        if(strcmp(sex,"mulher")==0||strcmp(sex,"f")==0||strcmp(sex,"feminino")==0)
        {
            printf("%s - mulher\n",nome);
            mul++;
        }
        else if(strcmp(sex,"homem")==0||strcmp(sex,"m")==0||strcmp(sex,"masculino")==0)
        {
            printf("%s - homem\n",nome);
            hom++;
        }
    }
    printf("Homens: %d\nMulheres: %d",hom,mul);
}
void xx()
{
    char ver[5];
    int ano,doismil,j;
    float val,desctot=0,desc,valtot=0;
    do
    {
        printf("Ano do carro: ");
        scanf("%d",&ano);
        printf("Valor do carro: R$ ");
        scanf("%f",&val);
        if(ano<=2000)
        {
            desc=val*0.12;
            
        }
        else
        {
            desc=val*0.07;
        }
        printf("Desconto: R$ %.2f\nValor final: R$ %.2f\n",desc,val-desc);
        desctot=desctot+desc;
        valtot=valtot+(val-desc);
        printf("Continuar?: ");
        scanf("%s",ver);
        for(j=0;j<strlen(ver);j++)
        {
            ver[j]=tolower(ver[j]);
        }
    }
    while(strcmp(ver,"n")!=0&&strcmp(ver,"nao")!=0&&strcmp(ver,"não")!=0);
    printf("Desconto total: R$ %.2f\nValor total a pagar: R$ %.2f",desctot,valtot);
}
void xxi()
{
    char nome[20],sex[10],saude[10];
    int idade,n,i,apt=0,j;
    printf("Quantas pessoas serão entrevistadas?: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Nome: ");
        scanf("%s",nome);
        do
        {
            printf("Sexo: ");
            scanf("%s",sex);
            for(j=0;j<strlen(sex);j++)
            {
                sex[j]=tolower(sex[j]);
            }
        }
        while(strcmp(sex,"mulher")!=0&&strcmp(sex,"f")!=0&&strcmp(sex,"feminino")!=0&&strcmp(sex,"homem")!=0&&strcmp(sex,"m")!=0&&strcmp(sex,"masculino")!=0);
        printf("Idade: ");
        scanf("%d",&idade);
        do
        {
            printf("Possui alguma doença de grau medio ou alto?: ");
            scanf("%s",saude);
            for(j=0;j<strlen(saude);j++)
            {
                saude[j]=tolower(saude[j]);
            }
        }
        while(strcmp(saude,"sim")!=0&&strcmp(saude,"s")!=0&&strcmp(saude,"nao")!=0&&strcmp(saude,"não")!=0&&strcmp(saude,"n")!=0);
        if(strcmp(saude,"s")==0||strcmp(saude,"sim")==0||idade<18||strcmp(sex,"mulher")==0||strcmp(sex,"f")==0||strcmp(sex,"feminino")==0)
        {
            printf("Não apto a sevir\n");
        }
        else
        {
            printf("apto a servir\n");
            apt++;
        }
    }
    printf("Total de pessoas aptas a sevir ao exército: %d",apt);
}
void xxii()
{
    float preccus,precven,custot=0,ventot=0,i;
    for(i=1;i<=40;i++)
    {
        printf("Preço de custo: R$ ");
        scanf("%f",&preccus);
        printf("Preço de venda: R$ ");
        scanf("%f",&precven);
        if(preccus>precven)
        {
            printf("Prejuízo\n");
        }
        else if(preccus<precven)
        {
            printf("Lucro\n");
        }
        else
        {
            printf("Empate\n");
        }
        custot=custot+preccus;
        ventot=ventot+precven;
    }
    printf("Média do preço de custo: R$ %.2f\nMédia do preço de vendas: R$ %.2f",custot/40,ventot/40);
}
void xxiii()
{
    int a;
    scanf("%d",&a);
    if(a>80)
    {
        printf("Maior que 80");
    }
    if(a<25)
    {
        printf("Menor que 25");
    }
    if(a==40)
    {
        printf("Igual a 40");
    }
}
void xxiv()
{
    int n,a,i;
    printf("Quantidade de numeros: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a>0)
        {
            printf("positivo\n");
        }
        else if(a<0)
        {
            printf("negativo\n");
        }
        else
        {
            printf("zero\n");
        }
    }
}
void xxv()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    if(a==b)
    {
        printf("Iguais");
    }
    else
    {
        int maior=a;
        if(b>a)
        {
            maior=b;
        }
        printf("Diferentes\nMaior: %d",maior);
    }
}
void xxvi()
{
    int a;
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        printf("um");
        break;
        case 2:
        printf("dois");
        break;
        case 3:
        printf("tres");
        break;
        case 4:
        printf("quatro");
        break;
        case 5:
        printf("cinco");
        break;
        default:
        printf("Inválido");
    }
}
void xxvii()
{
    int j;
    float val,desc,desctot=0,valtot=0;
    char tipo[10];
    do
    {
        printf("Valor do veículo: R$ ");
        scanf("%f",&val);
        if(val!=0)
        {
            do
            {
                printf("Tipo (diesel, gasolina, alcool): ");
                scanf("%s",tipo);
                for(j=0;j<strlen(tipo);j++)
                {
                    tipo[j]=tolower(tipo[j]);
                }
            }
            while(strcmp(tipo,"diesel")!=0&&strcmp(tipo,"gasolina")!=0&&strcmp(tipo,"alcool")!=0&&strcmp(tipo,"álcool")!=0);
            if(strcmp(tipo,"diesel")==0)
            {
                desc=0.14;
            }
            else if(strcmp(tipo,"gasolina")==0)
            {
                desc=0.21;
            }
            else
            {
                desc=0.25;
            }
            printf("Desconto: R$ %.2f\nValor a ser pago: R$ %.2f\n",val*desc,val-(val*desc));
            desctot=desctot+(val*desc);
            valtot=valtot+(val-(val*desc));
        }
    }
    while(val!=0);
    printf("Total em desconto: R$ %.2f\nTotal pago: R$ %.2f",desctot,valtot);
}
void xxviii()
{
    float sal,salmin,folha=0,ajuste,ajustot=0;
    int i;
    char nome[20];
    printf("Valor do salário mínimo: R$ ");
    scanf("%f",&salmin);
    for(i=1;i<=584;i++)
    {
        printf("Nome do funcionário: ");
        scanf("%s",nome);
        printf("Salário: R$ ");
        scanf("%f",&sal);
        if(sal/salmin<3)
        {
            ajuste=sal*0.5;
        }
        else if(sal/salmin>=3&&sal/salmin<=10)
        {
            ajuste=sal*0.2;
        }
        else if(sal/salmin>10&&sal/salmin<20)
        {
            ajuste=sal*0.15;
        }
        else
        {
            ajuste=sal*0.1;
        }
        printf("Nome: %s | Ajuste: R$ %.2f | Salario final: R$ %.2f\n",nome,ajuste,sal+ajuste);
        folha=folha+(sal+ajuste);
        ajustot=ajustot+ajuste;
    }
    printf("Com um aumento de R$ %2.f a folha salarial passa a ser de R$ %.2f",ajustot,folha);
}
void xxix()
{
   int mes;
   scanf("%d",&mes);
   switch(mes)
   {
       case 1:
       printf("janeiro");
       break;
       case 2:
       printf("fevereiro");
       break;
       case 3:
       printf("março");
       break;
       case 4:
       printf("abril");
       break;
       case 5:
       printf("março");
       break;
       case 6:
       printf("junho");
       break;
       case 7:
       printf("julho");
       break;
       case 8:
       printf("agosto");
       break;
       case 9:
       printf("setembro");
       break;
       case 10:
       printf("outubro");
       break;
       case 11:
       printf("novembro");
       break;
       case 12:
       printf("dezembro");
       break;
       default:
       printf("inválido");
   }
}
void xxx()
{
    char nome[20];
    int idade,sex,abono;
    float salfix;
    printf("Informe seu nome: ");
    scanf("%s",nome);
    printf("Informe sua idade: ");
    do
    {
        scanf("%d",&idade);
    }
    while(idade<1);
    printf("Qual seu sexo? masculino(1) / feminino(2)\n");
    do
    {
        scanf("%d",&sex);
    }
    while(sex!=1&&sex!=2);
    printf("Informe seu salário fixo: R$ ");
    do
    {
        scanf("%f",&salfix);
    }
    while(salfix<1);
    if(sex==1)
    {
        if(idade>=30)
        {
            abono=100;
        }
        else
        {
            abono=50;
        }
    }
    else
    {
        if(idade>=30)
        {
            abono=200;
        }
        else
        {
            abono=80;
        }
    }
    printf("Nome: %s\nSalario líquido: R$ %.2f",nome,salfix+abono);
}
void xxxi()
{
    int a,b,c,aux;
    do
    {
        scanf("%d%d%d",&a,&b,&c);
    }
    while(a==b||a==c||b==c);
    if(c>b&&c>a&&b>a)
    {
        aux=a;
        a=c;
        c=aux;
    }
    else if(c>b&&c>a&&a>b)
    {
        aux=c;
        c=b;
        b=a;
        a=aux;
    }
    else if(b>a&&b>c&&a>c)
    {
        aux=b;
        b=a;
        a=aux;
    }
    else if(b>a&&b>c&&c>a)
    {
        aux=b;
        b=c;
        c=a;
        a=aux;
    }
    else if(a>b&&a>c&&c>b)
    {
        aux=c;
        c=b;
        b=aux;
    }
    printf("1º: %d\n2º: %d\n3º: %d",a,b,c);
}
void xxxii()
{
    float a,b,res;
    char c,aux='0';
    scanf("%f%c%f",&a,&c,&b);
    if(c=='+')
    {
        res=a+b;
    }
    else if(c=='-')
    {
        res=a-b;
    }
    else if(c=='*'||c=='x')
    {
        res=a*b;
    }
    else if(c=='/'||c==':')
    {
        res=a/b;
        if(b==0)
        {
            aux='1';
        }
    }
    else
    {
        aux='2';
    }
    if(aux=='2')
    {
        printf("Operação inválida");
    }
    else if(aux=='1')
    {
        printf("erro de divisão por 0");
    }
    else
    {
        printf("%f",res);
    }
}
void xxxiii()
{
    int a,b,c,tipo;
    scanf("%d%d%d",&a,&b,&c);
    if(a==b&&b==c)
    {
        tipo=1;
    }
    else if(a==b&&b!=c||a==c&&c!=b||b==c&&c!=a)
    {
        tipo=2;
    }
    else
    {
        tipo=3;
    }
    if(tipo==1)
    {
        printf("Equilátero e isóceles");
    }
    else if(tipo==2)
    {
        printf("Isóceles");
    }
    else
    {
        printf("Escaleno");
    }
}
void xxxiv()
{
    int nivprof,dias,pag;
    float hrs;
    printf("Você é professor nível 1,2 ou 3?: ");
    do
    {
        scanf("%d",&nivprof);
    }
    while(nivprof<1||nivprof>3);
    printf("Quantas horas de aula diária você dá?: ");
    do
    {
        scanf("%f",&hrs);
    }
    while(hrs<1);
    printf("Você trabalhou quantos dias?: ");
    do
    {
        scanf("%d",&dias);
    }
    while(dias<1);
    if(nivprof==1)
    {
        pag=12;
    }
    else if(nivprof==2)
    {
        pag=17;
    }
    else
    {
        pag=25;
    }
    printf("Seu salário é R$ %.2f",hrs*dias*pag);
}
void xxxv()
{
    int idade;
    scanf("%d",&idade);
    if(idade>=5&&idade<=7)
    {
        printf("Infantil A");
    }
    else if(idade>=8&&idade<=10)
    {
        printf("Infantil B");
    }
    else if(idade>=11&&idade<=13)
    {
        printf("Juvenil A");
    }
    else if(idade>=14&&idade<=17)
    {
        printf("Juvenil B");
    }
    else if(idade>=18&&idade<=25)
    {
        printf("Senior");
    }
    else
    {
        printf("idade fora da faixa etária");
    }
}
void xxxvi()
{
    int tip;
    float kw,kh;
    printf("Qual tipo de unidade? comercio(1)/residencia(2)/industria(3): ");
    do
    {
        scanf("%d",&tip);
    }
    while(tip<1||tip>3);
    printf("Quantos Kw/h seu contador apresentou?: ");
    do
    {
        scanf("%f",&kw);
    }
    while(kw<0);
    if(tip==1)
    {
        kh=0.6;
    }
    else if(tip==2)
    {
        kh=0.48;
    }
    else
    {
        kh=1.29;
    }
    printf("Sua conta deu R$ %.2f",kw*kh);
}
void xxxvii()
{
    char nome[20];
    int sex,idade;
    float pesoideal,alt;
    printf("Digite seu nome: ");
    scanf("%s",nome);
    printf("Informe seu sexo: masculino(1)/feminino(2): ");
    do
    {
        scanf("%d",&sex);
    }
    while(sex!=1&&sex!=2);
    printf("Informe sua idade: ");
    do
    {
        scanf("%d",&idade);
    }
    while(idade<1);
    printf("Informe sua altura (cm): ");
    do
    {
        scanf("%f",&alt);
    }
    while(alt<1);
    alt=alt/100;
    if(sex==1)
    {
        if(alt>170)
        {
            if(idade<=20)
            {
                pesoideal=(72.7*alt)-58;
            }
            else if(idade>20&&idade<40)
            {
                pesoideal=(72.7*alt)-53;
            }
            else
            {
                pesoideal=(72.7*alt)-45;
            }
        }
        else
        {
            if(idade<=40)
            {
                pesoideal=(72.7*alt)-50;
            }
            else
            {
                pesoideal=(72.7*alt)-58;
            }
        }
    }
    else
    {
        if(alt>150)
        {
           pesoideal=(62.1*alt)-44.7; 
        }
        else
        {
            if(idade>=35)
            {
                pesoideal=(62.1*alt)-45; 
            }
            else
            {
                pesoideal=(62.1*alt)-49; 
            }
        }
    }
    printf("%s, seu peso ideal é: %.2f kg",nome,pesoideal);
}

void xxxviii()
{
    float a,b,c,mp;
    printf("Informe a nota do laboratório: ");
    do
    {
        scanf("%f",&a);
    }
    while(a<0||a>10);
    printf("Informe a nota da avaliação semestral: ");
    do
    {
        scanf("%f",&b);
    }
    while(b<0||b>10);
    printf("Informe a nota do exame final: ");
    do
    {
        scanf("%f",&c);
    }
    while(c<0||c>10);
    mp=((a*2)+(b*3)+(c*5))/10;
    printf("Sua média ponderada é: %.2f",mp);
}
void xxxix()
{
    char nome[20],clas;
    float a,b,c,mp;
    double matricula;
    printf("Nome: ");
    scanf("%s",nome);
    printf("Informe seu número de matrícula: ");
    scanf("%lf",&matricula);
    printf("Informe a nota do laboratório: ");
    do
    {
        scanf("%f",&a);
    }
    while(a<0||a>10);
    printf("Informe a nota da avaliação semestral: ");
    do
    {
        scanf("%f",&b);
    }
    while(b<0||b>10);
    printf("Informe a nota do exame final: ");
    do
    {
        scanf("%f",&c);
    }
    while(c<0||c>10);
    mp=((a*2)+(b*3)+(c*5))/10;
    if(mp>=8&&mp<=10)
    {
       clas='A'; 
    }
    else if(mp>=7&&mp<8)
    {
        clas='B';
    }
    else if(mp>=6&&mp<7)
    {
        clas='C';
    }
    else if(mp>=5&&mp<6)
    {
        clas='D';
    }
    else
    {
        clas='R';
    }
    printf("Nome: %s\nMatrícula: %.0f\nMédia ponderada: %.2f | Classificação: %c",nome,matricula,mp,clas);
}
void xl()
{
    char nome[20];
    int idade, grupo,faixa;
    printf("Nome: ");
    scanf("%s",nome);
    printf("Idade: ");
    scanf("%d",&idade);
    if(idade>=17&&idade<=70)
    {
        printf("Grupo de risco: baixo(1) medio(2) alto (3): ");
        do
        {
            scanf("%d",&grupo);
        }
        while(grupo<1||grupo>3);
        if(idade>=17&&idade<=20)
        {
            if(grupo==1)
            {
                faixa=1;
            }
            else if(grupo==2)
            {
                faixa=2;
            }
            else
            {
                faixa=3;
            }
        }
        else if(idade>=21&&idade<=24)
        {
            if(grupo==1)
            {
                faixa=2;
            }
            else if(grupo==2)
            {
                faixa=3;
            }
            else
            {
                faixa=4;
            }
        }
        else if(idade>=25&&idade<=34)
        {
            if(grupo==1)
            {
                faixa=3;
            }
            else if(grupo==2)
            {
                faixa=4;
            }
            else
            {
                faixa=5;
            }
        }
        else if(idade>=35&&idade<=64)
        {
            if(grupo==1)
            {
                faixa=4;
            }
            else if(grupo==2)
            {
                faixa=5;
            }
            else
            {
                faixa=6;
            }
        }
        else
        {
            if(grupo==1)
            {
                faixa=7;
            }
            else if(grupo==2)
            {
                faixa=8;
            }
            else
            {
                faixa=9;
            }
        }
        printf("Nome: %s\nIdade: %d\nCategoria: %d",nome,idade,faixa);
    }
    else
    {
        printf("Idade não permitida");
    }
}
int main()
{
    int numq;
    printf("Número da questão: ");
    scanf("%d",&numq);
    switch(numq)
    {
        case 1:
        i();
        break;
        case 2:
        ii();
        break;
        case 3:
        iii();
        break;
        case 4:
        iv();
        break;
        case 5:
        v();
        break;
        case 6:
        vi();
        break;
        case 7:
        vii();
        break;
        case 8:
        viii();
        break;
        case 9:
        ix();
        break;
        case 10:
        x();
        break;
        case 11:
        xi();
        break;
        case 12:
        xii();
        break;
        case 13:
        xiii();
        break;
        case 14:
        xiv();
        break;
        case 15:
        xv();
        break;
        case 16:
        xvi();
        break;
        case 17:
        xvii();
        break;
        case 18:
        xviii();
        break;
        case 19:
        xix();
        break;
        case 20:
        xx();
        break;
        case 21:
        xxi();
        break;
        case 22:
        xxii();
        break;
        case 23:
        xxiii();
        break;
        case 24:
        xxiv();
        break;
        case 25:
        xxv();
        break;
        case 26:
        xxvi();
        break;
        case 27:
        xxvii();
        break;
        case 28:
        xxviii();
        break;
        case 29:
        xxix();
        break;
        case 30:
        xxx();
        break;
        case 31:
        xxxi();
        break;
        case 32:
        xxxii();
        break;
        case 33:
        xxxiii();
        break;
        case 34:
        xxxiv();
        break;
        case 35:
        xxxv();
        break;
        case 36:
        xxxvi();
        break;
        case 37:
        xxxvii();
        break;
        case 38:
        xxxviii();
        break;
        case 39:
        xxxix();
        break;
        case 40:
        xl();
        break;
        default:
        printf("Inválido: ");
    }
    return 0;
}

