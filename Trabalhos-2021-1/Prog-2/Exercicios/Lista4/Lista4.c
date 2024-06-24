#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void i()
{
    char vogal[5],mes[12][10],nomemes[10];
    float alt[10];
    int i,j;
    printf("Informe as vogais do alfabeto: ");
    scanf("%s",vogal);
    for(i=0;i<10;i++)
    {
        printf("Informe a altura da pessoa %d: ",i+1);
        scanf("%f",&alt[i]);
    }
    for(i=0;i<12;i++)
    {
        printf("Informe o mês %d: ",i+1);
        scanf("%s",nomemes);
        for(j=0;j<strlen(nomemes);j++)
        {
            mes[i][j]=nomemes[j];
        }
    }
}
void ii()
{
    int i,a[10],maior=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>maior)
        {
            maior=a[i];
        }
    }
    printf("Maior: %d",maior);
}
void iii()
{
    int i,a[10],menor=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<menor)
        {
            menor=a[i];
        }
    }
    printf("Menor: %d",menor);
}
void iv()
{
    int W[11],i=5,j;
	for(j=0;j<11;j++)
	{
		W[j]=0;
	}
	W[1]=17;
	W[i/2]=9;
	W[2*i-1]=95;
	W[i-1]=W[9]/2;
	W[i]=W[2];
	W[i+1]=W[i]+W[i-1];
	W[W[2]-2]=78;
	W[W[i]-1]=W[1]*W[i];
	W[W[2]%2+2]=W[i+9/2]+3*W[i-1*2];
	for(j=1;j<10;j++)
	{
		printf("%d\n",W[j]);
	}
}
void v()
{
    int n,i;
    scanf("%d",&n);
    int vet[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&vet[i]);
    }
    for(i=n;i>0;i--)
    {
        printf("%d ",vet[i-1]);
    }
}
void vi()
{
    int n,i,aux;
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<n;i++)
    {
        if(i>0)
        {
            if(x[i]<x[i-1])
            {
                aux=x[i-1];
                x[i-1]=x[i];
                x[i]=aux;
                i=0;
            }
        }
    }
    for(i=n;i>0;i--)
    {
        printf("%d | ",x[i-1]);
    }
}
void vii()
{
    int x[15],i,par=0;
    for(i=0;i<15;i++)
    {
        scanf("%d",&x[i]);
        if(x[i]%2==0)
        {
            par++;
        }
    }
    printf("pares: %d",par);
}
void viii()
{
    int i,soma=0;
    float x[20];
    for(i=0;i<20;i++)
    {
        scanf("%f",&x[i]);
        soma=soma+x[i];
    }
    printf("%d",soma);
}
void ix()
{
    int x[10],a,i,y=0;
    srand(time(NULL));
    for(i=0;i<10;i++)
    {
        x[i]=rand()%1000;
    }
    scanf("%d",&a);
    for(i=0;i<10;i++)
    {
        if(a==x[i])
        {
            printf("Igual x[%d] ",i);
            y=1;
        }
    }
    if(y==0)
    {
        printf("Não igual");
    }
}
void x()
{
    int a[10],b[10],i,uniao;
    for(i=0;i<20;i++)
    {
        if(i<10)
        {
            scanf("%d",&a[i]);
        }
        else
        {
            scanf("%d",&b[i-10]);
        }
    }
    uniao=a[0]+a[1]+b[0]+b[1];
    printf("soma: %d",uniao);
}
void xi()
{
    int x[30],i,j=0,k=0,par=0,impar=0;
    for(i=0;i<30;i++)
    {
        scanf("%d",&x[i]);
        if(x[i]%2==0)
        {
            par++;
        }
        else
        {
            impar++;
        }
    }
    int a[par],b[impar];
    for(i=0;i<30;i++)
    {
        if(x[i]%2==0)
        {
            a[j]=x[i];
            j++;
        }
        else
        {
            b[k]=x[i];
            k++;
        }
    }
    for(i=0;i<30;i++)
    {
        if(i<par)
        {
            printf("par: %d\n",a[i]);
        }
        else
        {
            printf("impar: %d\n",b[i-par]);
        }
    }
}
void xii()
{
    int n,i,mai=0;
    float med,som=0;
    printf("Número de alunos: ");
    scanf("%d",&n);
    float nota[n];
    for(i=0;i<n;i++)
    {
        scanf("%f",&nota[i]);
        if(nota[i]>6)
        {
            mai++;
        }
        som=som+nota[i];
    }
    printf("Media: %.2f | ",som/n);
    if(mai==0)
    {
        printf("Ninguem tirou nota maior que 5");
    }
    else
    {
        printf("Maior que 5: %d",mai);
    }
}
void xiii()
{
    float temp[7],med,soma=0;
    int i,acima=0;
    for(i=0;i<7;i++)
    {
        scanf("%f",&temp[i]);
        soma=soma+temp[i];
    }
    med=soma/7;
    for(i=0;i<7;i++)
    {
        if(temp[i]>med)
        {
            acima++;
        }
    }
    printf("%d dias estiveram acima da temperatura média",acima);
}
void xiv()
{
    int i,j=9,a[10],b[10],c[10];
    for(i=0;i<20;i++)
    {
        if(i<10)
        {
            scanf("%d",&a[i]);
        }
        else
        {
            scanf("%d",&b[i-10]);
        }
    }
    for(i=0;i<10;i++)
    {
        c[i]=a[i]+b[j];
        j--;
    }
    for(i=0;i<10;i++)
    {
        printf("%d|",c[i]);
    }
}
void xv()
{
    int a[10],b[10],c[10],i,aux;
    for(i=0;i<20;i++)
    {
        if(i<10)
        {
            scanf("%d",&a[i]);
        }
        else
        {
            scanf("%d",&b[i-10]);
        }
    }
    for(i=0;i<10;i++)
    {
        if(a[i]<a[i-1])
        {
            aux=a[i];
            a[i]=a[i-1];
            a[i-1]=aux;
            i=0;
        }
    }
    for(i=0;i<10;i++)
    {
        if(b[i]<b[i-1])
        {
            aux=b[i];
            b[i]=b[i-1];
            b[i-1]=aux;
            i=0;
        }
    }
    for(i=0;i<10;i++)
    {
        c[i]=a[i]+b[i];
        printf("%d|",c[i]);
    }
}
void xvi()
{
    int i;
    float nota[5],aux;
    for(i=0;i<5;i++)
    {
        scanf("%f",&nota[i]);
    }
    for(i=0;i<5;i++)
    {
        if(nota[i]<nota[i-1])
        {
            aux=nota[i];
            nota[i]=nota[i-1];
            nota[i-1]=aux;
            i=0;
        }
    }
    printf("Maior nota: %.2f\nMenor nota: %.2f",nota[4],nota[0]);
}
void xvii()
{
    int a[15],x,y;
    for(x=0;x<15;x++)
    {
        scanf("%d",&a[x]);
    }
    while(x>14||x<0||y>14||y<0)
    {
        scanf("%d%d",&x,&y);   
    }
    printf("Soma: %d",a[x]+a[y]);
}
void xviii()
{
    int a[10],i,aux[5];
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        if(i<5)
        {
            aux[i]=a[i];    
        }
    }
    for(i=0;i<5;i++)
    {
        a[i]=a[i+5];
        a[i+5]=aux[i];
    }
    for(i=0;i<10;i++)
    {
        printf("%d|",a[i]);
    }
}
void xix()
{
    int a[20],i,x,val=0;
    for(i=0;i<20;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("x: ");
    scanf("%d",&x);
    for(i=0;i<20;i++)
    {
        if(x==a[i])
        {
            printf("Valor %d encontrado na posição %d\n",x,i);
            val=1;
        }
    }
    if(val==0)
    {
        printf("Valor não encontrado");
    }
}
void xx()
{
    int a,i=0;
    do
    {
        scanf("%d",&a);
    }
    while(a<10);
    //printf("%d",a);
    if(a<100)
    {
        if(a-((a/10)*10)==a/10)
        {
            i=1;
        }
    }
    else if(a>=100&&a<1000)
    {
        if(a-((a/10)*10)==a/100)
        {
            i=1;
        }
    }
    else if(a>=1000&&a<10000)
    {
        if(a-((a/10)*10)==a/1000&&(a-((a/1000)*1000))/100==(a-((a/100)*100))/10)
        {
            i=1;
        }
    }
    if(i==1)
    {
        printf("Palíndromo");
    }
    else
    {
        printf("Não palíndromo");
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
        default:
        printf("Opção inválida");
    }
    return 0;
}