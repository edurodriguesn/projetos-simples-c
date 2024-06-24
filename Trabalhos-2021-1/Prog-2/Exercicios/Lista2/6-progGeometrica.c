#include <stdio.h>
#include <math.h>
int
main ()
{
  int a, n, r, i;
  printf ("Digite o primeiro termo: ");
  scanf ("%d", &a);
  printf ("Digite o numero de termos: ");
  scanf ("%d", &n);
  printf ("Digite a razao da PG: ");
  scanf ("%d", &r);
  for (i = 1; i <= n; i++)
    {
      printf ("%d\n", a);
      a = a * r;
    }
  return 0;
}

