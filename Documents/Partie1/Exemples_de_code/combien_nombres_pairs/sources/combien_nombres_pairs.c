#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compteur = 0;
const int min = 10;
const int max = 13;

int main (void)
{
  int indice = 0; 
  for ( indice = min ; indice <= max; indice++ )
  {
      if ( indice % 2 == 0)
           compteur++;
  }
  fprintf( stdout,
           "Il y a %d nombres pairs entre %d et %d \n",
           compteur,
           min,
           max
         );

  return EXIT_SUCCESS;
}

