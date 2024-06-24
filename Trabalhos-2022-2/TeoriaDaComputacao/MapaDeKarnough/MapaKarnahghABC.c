#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int s[8],a,b,c,k=0,karnoughtres[2][4],somatotal=0,adicionarmais=0,linha,coluna;
    char expressao[20];
    for(a=0;a<=1;a++)
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
            {
                s[k]=a+(b*c);
                if(s[k]>1)
                    s[k]=1;
                printf("%d %d %d| %d\n",a,b,c,s[k]);
                k++;
            }
    k=0;
    for(linha=0;linha<=1;linha++)
    {
        for(coluna=0;coluna<=3;coluna++)
        {
            if(coluna<2)
            {
                karnoughtres[linha][coluna]=s[k];
                k++;
            }
            else
            {
                k++;
                karnoughtres[linha][coluna]=s[k];
                k-=2;
            }
        }
        k=4;
    }
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=3;j++)
            printf("%d ",karnoughtres[i][j]);
        printf("\n");
    }
    return 0;
}