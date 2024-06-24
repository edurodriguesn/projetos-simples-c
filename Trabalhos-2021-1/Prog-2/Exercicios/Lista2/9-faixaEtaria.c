#include <stdio.h>
int
main ()
{
  int q, y, i;
  int s = 0;
  float s1 = 0;
  float s2 = 0;
  float s3 = 0;
  float s4 = 0;
  float s5 = 0;
  printf ("Quantas idades voce quer digitar?: ");
  scanf ("%d", &q);
  for (i = 1; i <= q; i++)
    {
      printf ("Digite a %do idade: ", i);
      scanf ("%d", &y);
      if (y <= 17)
	{
	  s1++;
	}
      else if (y >= 18 && y <= 35)
	{
	  s2++;
	}
      else if (y > 35 && y <= 50)
	{
	  s3++;
	}
      else if (y > 50 && y <= 65)
	{
	  s4++;
	}
      else
	{
	  s5++;
	}
    }
  s1 = (s1 * 100) / q;
  s2 = (s2 * 100) / q;
  s3 = (s3 * 100) / q;
  s4 = (s4 * 100) / q;
  s5 = (s5 * 100) / q;
  printf ("0-17: %f%%\n", s1);
  printf ("18-35: %f%%\n", s2);
  printf ("35-50: %f%%\n", s3);
  printf ("50-65: %f%%\n", s4);
  printf ("Maior que 60: %f%%\n", s5);
  return 0;
}

