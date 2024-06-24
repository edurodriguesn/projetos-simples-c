#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
void i()
{
    int t, i, M[3][4];
    for (t=0; t<3; ++t)
        for (i=0; i<4; ++i)
            M[t][i]=(t*4)+i+1;
    for (t=0; t<3; ++t)
    {
        for (i=0; i<4; ++i)
            printf ("%3d", M[t][i]);
        printf ("\n");
    } 
}
void ii()
{
    int R[4][5],i,j,maior=0,x=0,y=0;
    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            R[i][j]=rand()%100;
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
            printf("%2d ",R[i][j]);
        printf("\n");
    }
    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            if(R[i][j]>maior)
            {
                maior=R[i][j];
                x=i;
                y=j;
            }
    printf("Maior: %d\nX: %d\nY: %d",maior,x,y);
}
void iii()
{
    int m,n,i,j,k=0,soma=0;
    scanf("%d%d",&m,&n);
    int A[m][n],S[n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            A[i][j]=rand()%100;
            printf("%2d ",A[i][j]);
        }
        if((n-1)-i>=0)
        {
            soma+=A[i][k];
            S[i]=A[i][k];
            k++;
        }
        printf("\n");
    }
    printf("Soma: %d\n",soma);
    for(i=0;i<k;i++)
        printf("S[%d]= %2d | ",i,S[i]);
}
void iv()
{
    int m,n,i,j,k,soma=0,aux;
    scanf("%d%d",&m,&n);
    int A[m][n],S[n];
    k=n-1;
    if(n<m)
        aux=n;
        else
        aux=m;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            A[i][j]=rand()%100;
            printf("%2d ",A[i][j]);
        }
        if((n-1)-i>=0)
        {
            soma+=A[i][k];
            S[i]=A[i][k];
            k--;
        }
        printf("\n");
    }
    printf("Soma: %d\n",soma);
    for(i=0;i<aux;i++)
        printf("S[%d]: %d | ",i,S[i]);
}
void v()
{
    int n,m,i,j;
    scanf("%d%d",&m,&n);
    int A[m][n],B[m][n],C[m][n];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            A[i][j]=rand()%100;
            B[i][j]=rand()%100;
            C[i][j]=A[i][j]+B[i][j];
        }
    printf("Matriz A:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%2d ",A[i][j]);
        printf("\n");
    }
    printf("Matriz B:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%2d ",B[i][j]);
        printf("\n");
    }
    printf("Matriz C:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%3d ",C[i][j]);
        printf("\n");
    }
}
void vi()
{
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    int A[m][n],B[m][n],C[m][n];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            A[i][j]=rand()%100;
            B[i][j]=rand()%100;
            C[i][j]=A[i][j]*B[i][j];
        }
    printf("Matriz A\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%2d ",A[i][j]);
        printf("\n");
    }
    printf("Matriz B\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%2d ",B[i][j]);
        printf("\n");
    }
    printf("Matriz C\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%4d ",C[i][j]);
        printf("\n");
    }
}
void vii()
{
    int m,i,j;
    scanf("%d",&m);
    int A[m][m],T[m][m];
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            A[i][j]=rand()%100;
            T[j][i]=A[i][j];
        }
    printf("Matriz A:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            printf("%2d ",A[i][j]);
        printf("\n");
    }
    printf("Matriz T:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            printf("%2d ",T[i][j]);
        printf("\n");
    }
}
void viii()
{
    
}
void ix()
{
    
}
void x()
{
    
}
void xi()
{
    
}
void xii()
{
    
}
void xiii()
{
    
}
void xiv()
{
    
}
void xv()
{
    
}
void xvi()
{
   
}
void xvii()
{
    
}
void xviii()
{
    
}
void xix()
{
    
}
void xx()
{

}
void xxi()
{
    
}
void xxii()
{
    
}
void xxiii()
{
    
}
void xxiv()
{
    
}
void xxv()
{
    
}
void xxvi()
{
   
}
void xxvii()
{
    
}
void xxviii()
{
    
}
void xxix()
{
   
}
void xxx()
{

}
void xxxi()
{
    
}
void xxxii()
{
    
}
void xxxiii()
{
    
}
int main()
{
    int numq;
    srand(time(NULL));
    printf("Questão: ");
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
        default:
        printf("Opção inválida");
    }
    return 0;
}
//matriz transposta não quadrada

