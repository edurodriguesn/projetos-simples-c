#include <stdio.h>
int fatorial(int fat)
{
    if(fat==0||fat==1) {
        return 1;
    } else {
        return fat*fatorial(fat-1);
    }
}
int main()
{
    int fat;
    scanf("%d",&fat);
    printf("%d",fatorial(fat));
    return 0;
}

