/* main.c from saisie_project
 * Author: Eric Bachard / Ven 29 mai 2015 13:59:01 CEST
 * This document is under GPL v2 License
 * See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "saisie_nombre.h"
#include "test_saisies_nombres.h"
#include "test_saisie_chaine.h"

int
main (void)
{
  int ret = system( "clear");
  if (ret != 0 )
   fprintf(stderr, "problème avec system");
  test_saisies_nombres();
  test_saisie_chaine();
  /* WRITE YOUR CODE HERE :-) */
  fprintf(stdout, "\nFin des tests...\n");
  return EXIT_SUCCESS;
}

