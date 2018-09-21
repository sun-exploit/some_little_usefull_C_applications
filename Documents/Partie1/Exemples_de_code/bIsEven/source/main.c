/* bIsEven.c programme servant à etudier la parité d'un nombre
 * Auteur : Eric Bachard
 * Ce document est sous Licence GPL v2  Octobre 2014
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bIsEven.h"

int main (void)
{
  initialize_rand();

  int i=0;
  for (i = 0 ; i< 11 ; i++)
  {
    test_parity( (rand() % 2000 + 1) );
  }

  return EXIT_SUCCESS;
}
