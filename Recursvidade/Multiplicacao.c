#include <stdio.h>
int multiplicador(int a, int b)
{
    if(b==0) {
        return 0;
    } else if(b==1) {
        return a;
    } else {
        return a+multiplicador(a,b-1);
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",multiplicador(a,b));
    return 0;
}
