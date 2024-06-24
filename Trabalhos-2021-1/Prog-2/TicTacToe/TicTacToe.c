#include <stdio.h>
#include <ctype.h>
int main()
{
    char tab[3][3],simb;
    int i,j,x,y,vit=0,timer=0,lx=0,lo=0,cx=0,co=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            tab[i][j]=' ';
        }
    }
    printf(" %c | %c | %c\n---|---|---\n %c | %c | %c\n---|---|---\n %c | %c | %c\n",tab[0][0],tab[0][1],tab[0][2],tab[1][0],tab[1][1],tab[1][2],tab[2][0],tab[2][1],tab[2][2]);
    do
    {
        do
        {
            printf("Linha: ");
            scanf("%d",&x);
            printf("Coluna: ");
            scanf("%d",&y);
        }
        while(tab[x-1][y-1]!=' '||y<1||y>3);
        printf("X ou O:\n");
        for(i=0;i<1;i++)
        {
            scanf("%c",&simb);
            simb=toupper(simb);
            if(simb!='X'&&simb!='O')
            {
                i--;
            }
        }
        tab[x-1][y-1]=simb;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(tab[i][j]=='X')
                {
                    lx++;
                }
                else if(tab[i][j]=='O')
                {
                    lo++;
                }
                if(tab[j][i]=='X')
                {
                    cx++;
                }
                else if(tab[j][i]=='O')
                {
                    co++;
                }
            }
            if(lx==3||cx==3||tab[0][0]=='X'&&tab[1][1]=='X'&&tab[2][2]=='X'||tab[0][2]=='X'&&tab[1][1]=='X'&&tab[2][0]=='X')
            {
                vit=1;
            }
            else if(lo==3||co==3||tab[0][0]=='O'&&tab[1][1]=='O'&&tab[2][2]=='O'||tab[0][2]=='O'&&tab[1][1]=='O'&&tab[2][0]=='O')
            {
                vit=2;
            }
            else
            {
                lx=0;
                lo=0;
                cx=0;
                co=0;
            }
        }
        printf(" %c | %c | %c\n---|---|---\n %c | %c | %c \n---|---|---\n %c | %c | %c\n",tab[0][0],tab[0][1],tab[0][2],tab[1][0],tab[1][1],tab[1][2],tab[2][0],tab[2][1],tab[2][2]);
        timer++;
        if(timer==9)
        {
            vit=3;
        }
    }
    while(vit==0);
    if(vit==3)
    {
        printf("Empate");
    }
    else if(vit==2)
    {
        printf("Vitória de O");
    }
    else
    {
        printf("Vitória de X");
    }
    return 0;
}