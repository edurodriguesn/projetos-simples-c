#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int vetor[6], i;
    for(i=0;i<6;i++)
        vetor[i]=(rand()%10)-4;

    //vetores de u
    printf("u (%2d",vetor[0]);
    for(i=1;i<3;i++)
        printf(",%2d",vetor[i]);
    printf(")\n");

    //vetores de v
    printf("v (%2d",vetor[3]);
    for(i=4;i<6;i++)
        printf(",%2d",vetor[i]);
    printf(")");
    
    return 0;
}
