#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main ()
{
    float a;
    int i;
    char b[10];
    printf ("Digite sua altura em metros: ");
    scanf ("%f", &a);
    printf ("Digite seu sexo: ");
    scanf ("%s",b);
    for(i=0;i<strlen(b);i++)
    {
        b[i]=tolower(b[i]);
    }
    if (strcmp(b,"f")==0 || strcmp(b,"feminino")==0 || strcmp(b,"mulher")==0)
    { 
      printf ("O seu peso ideal é: %.2f", (62.1 * a) - 58);
    }
    else if (strcmp(b,"m")==0 || strcmp(b,"masculino")==0 || strcmp(b,"homem")==0)
    {
      printf ("O seu peso ideal é: %.2f", (72.7 * a) - 44.7);
    }
    else
    {
      printf ("Sexo invalido");
    }
    return 0;
}



