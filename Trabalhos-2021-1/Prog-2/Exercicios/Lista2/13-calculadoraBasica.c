#include <stdio.h>
#include <string.h>
int
main ()
{
  char c[4];
  float a, b, r, y;
  scanf ("%f", &a);
  printf ("(+) (-) (x) (/)\n");
  scanf ("%s", c);
  scanf ("%f", &b);
  if (strcmp (c,"+")==0)
    {
      r = a + b;
      printf ("%f %s %f = %f\n", a, c, b, r);
    }
  else if (strcmp (c,"-")==0)
    {
      r = a - b;
      printf ("%f %s %f = %f\n", a, c, b, r);
    }
  else if (strcmp (c,"x")==0)
    {
      r = a * b;
      printf ("%f %s %f = %f\n", a, c, b, r);
    }
  else if (strcmp (c,"/")==0)
    {
      r = a / b;
      printf ("%f %s %f = %f\n", a, c, b, r);
    }
  else
    {
      y=0;
      printf ("Inválido");
    }
  if (y!=0)
    {
      do
	{
	  printf ("(+) (-) (x) (/) (fim)\n");
	  scanf ("%s", c);
	  if (strcmp (c,"fim")==0 || strcmp(c," ")!=0){
	      y=0;
	  }else{
	      scanf ("%f", &a);
	      if (strcmp (c,"+")==0)
		{
		  printf ("%f %s %f = %f\n", r, c, a, (r+a));
		  r=r+a;
		  y=1;
		}
	      else if (strcmp (c,"-")==0)
		{
		  printf ("%f %s %f = %f\n", r, c, a, (r-a));
		  r=r-a;
		  y=1;
		}
	      else if (strcmp (c,"x")==0)
		{
		  printf ("%f %s %f = %f\n", r, c, a, (r*a));
		  r=r*a;
		  y=1;
		}
	      else if (strcmp (c,"/")==0)
		{
		  printf ("%f %s %f = %f\n", r, c, a, (r/a));
		  r=r/a;
		  y=1;
		}
	      else
		{
		  y=0;
		  printf ("Inválido");
		}
	    }
	}
      while (y !=0 );
    }
      return 0;
    }

