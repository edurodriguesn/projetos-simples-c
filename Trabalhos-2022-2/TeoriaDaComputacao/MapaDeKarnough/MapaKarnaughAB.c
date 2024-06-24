#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int s[4],a,b,k=0,karnoughdois[2][2],somatotal=0,adicionarmais=0,A=0,B=0,NA=0,NB=0;
    char expressao[20];
    for(a=0;a<=1;a++)
    {
        for(b=0;b<=1;b++)
        {
            s[k]=(pow(a-1,2)*b)+(a*b);
            if(s[k]>1)
                s[k]=1;
            karnoughdois[a][b]=s[k];
            if(a==0)
                NA+=karnoughdois[a][b];
                else
                    A+=karnoughdois[a][b];
            if(b==0)
                NB+=karnoughdois[a][b];
                else
                    B+=karnoughdois[a][b];
            
            somatotal+=s[k];
            k++;
            printf("%d ",karnoughdois[a][b]);
        }
        printf("\n");
    }
    if(somatotal==4)
        strcpy(expressao,"1");
        else if(A==2||NA==2||B==2||NB==2)
        {
            if(NA==2)
            {
                strcpy(expressao,"A'");
                adicionarmais++;
            }
            if(A==2)
            {
                if(adicionarmais>0)
                    strcat(expressao,"+A");
                    else
                        strcpy(expressao,"A");
                adicionarmais++;
            }
            if(NB==2)
            {
                if(adicionarmais>0)
                    strcat(expressao,"+B'");
                    else
                        strcpy(expressao,"B'");
                adicionarmais++;
            }
            if(B==2)
            {
                if(adicionarmais>0)
                    strcat(expressao,"+B");
                    else
                        strcpy(expressao,"B");
            }
        }
        else
        {
            if(karnoughdois[0][0]==1)
            {
                strcpy(expressao,"A'B'");
                adicionarmais++;
            }
            if(karnoughdois[0][1]==1)
            {
                if(adicionarmais>0)
                    strcat(expressao,"+A'B");
                    else
                        strcpy(expressao,"A'B");
                adicionarmais++;
            }
            if(karnoughdois[1][0]==1)
            {
                if(adicionarmais>0)
                    strcat(expressao,"+AB'");
                    else
                        strcpy(expressao,"AB'");
                adicionarmais++;
            }
            if(karnoughdois[1][1]==1)
            {
                if(adicionarmais>0)
                    strcat(expressao,"+AB");
                    else
                        strcpy(expressao,"AB");
            }
        }
    printf("%s",expressao);

    return 0;
}