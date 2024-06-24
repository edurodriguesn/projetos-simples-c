#include <stdio.h>
#include <stdlib.h>
int m,n,res=0,*mm,*nn,*resres,i,j,k=-1,l=1,mtemp,ntemp,adicionarmn;
void VerificacaoPrincipal()
{
    adicionarmn=0;
    if(m==0)
            res=n+1;
    else if(n==0)
    {
        m--;
        n=1;
        VerificacaoPrincipal();
    }
    else
    {
        adicionarmn=1;
        m--;
    }
}
void Processomn()
{
    for(i=0;i<1;i++);
    {
        k++;
        l++;
        mm=(int *)realloc(mm,sizeof(int)*l);
        nn=(int *)realloc(nn,sizeof(int)*l);
        resres=(int *)realloc(resres,sizeof(int)*l);
        mm[k]=m;
        if(l>1)
            nn[k]=nn[k-1]-1;
            else
                nn[k]=n-1;
        resres[k]=0;
        if(mm[k]==0)
        {
            resres[k]=nn[k]+1;
            if(k==0)
                n=resres[k];
                else
                {
                    nn[k-1]=resres[k];
                    k--;
                }
        }
        else if(nn[k]==0)
        {
            mm[k]--;
            nn[k]=1;
            if(mm[k]==0)
            {
                resres[k]=nn[k]+1;
                if(k==0)
                    n=resres[k];
                    else
                    {
                        nn[k-1]=resres[k];
                        k--;
                    }
            }
        }
        else
        {
            mm[k]--;
            k++;
            l++;
            mm=(int *)realloc(mm,sizeof(int)*l);
            nn=(int *)realloc(nn,sizeof(int)*l);
            resres=(int *)realloc(resres,sizeof(int)*l);
            mm[k]=mm[k-1];
            nn[k]=nn[k-1]-1;
            resres[k]=0;
        }
        if(resres[0]==0)
            i--;
        printf("k: %d  l: %d\n",k,l);
    }
    l=1;
    k=-1;
    free(mm);
    free(nn);
    free(resres);
    mm=(int *)realloc(mm,sizeof(int)*l);
    nn=(int *)realloc(nn,sizeof(int)*l);
    resres=(int *)realloc(resres,sizeof(int)*l);
}
int main()
{
    mm=(int *)malloc(sizeof(int)*1);
    nn=(int *)malloc(sizeof(int)*1);
    resres=(int *)malloc(sizeof(int)*1);
    printf("Digite os dois números do conjunto A():\n");
    scanf("%d%d",&m,&n);
    VerificacaoPrincipal();
    while(adicionarmn==1)
    {
        Processomn();
        VerificacaoPrincipal();
    }
    printf("%d",res);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,a[1],*b,k=1;
    a[0]=4;
    b=(int *)malloc(sizeof(int)*1);
    for(i=0;i<5;i++)
    {
        b=(int *)realloc(b,sizeof(int)*k);
        b[i]=k+2;
        k++;
    }
    for(i=0;i<5;i++)
        printf("%d\n",b[i]);
    free(b);
    return 0;
}*/
