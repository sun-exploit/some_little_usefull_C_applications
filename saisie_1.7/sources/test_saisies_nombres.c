/* test_saisies_nombres.c from saisie project
 * Author: Eric Bachard / Ven 29 mai 2015 13:59:01 CEST
 * This document is under GPL v2 License
 * See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "saisie_nombre.h"
#include "test_saisies_nombres.h"

short int
test_saisies_nombres(void)
{
  test_saisie_entier_court();
  test_saisie_entier_long();
  test_saisie_reel();
  test_saisie_reel_notation_scientifique();

  return EXIT_SUCCESS;
}

short int
test_saisie_entier_court(void)
{
  short int valeur_short_int = saisie_nombre_entier_court(TRUE, SHRT_MIN, SHRT_MAX);

  fprintf(  stdout, "Nombre entier court saisi %hd \n", valeur_short_int );
  fprintf(  stdout,
            "Vérification : le nombre saisi élevé au carré vaut %d \n",
            (int) valeur_short_int * valeur_short_int
         );
  return EXIT_SUCCESS;
}

short int
test_saisie_entier_long(void)
{
  long long int valeur_long_int = saisie_nombre_entier_long(TRUE, LLONG_MIN, LLONG_MAX);

  fprintf(  stdout, "Nombre entier long saisi %lld \n", valeur_long_int );
  fprintf(  stdout,
            "Vérification : le nombre saisi élevé au carré vaut %Lg \n",
            (long double)valeur_long_int * (long double)valeur_long_int
         );
  return EXIT_SUCCESS;
}

short int
test_saisie_reel(void)
{
  long double  valeur_double_float = saisie_nombre_reel(TRUE, -REEL_MAX, REEL_MAX );
  fprintf(  stdout, "Nombre réel saisi %Lg \n", valeur_double_float);

  return EXIT_SUCCESS;
}

short int
test_saisie_reel_notation_scientifique(void)
{
  long double  valeur_double_float = saisie_nombre_scientifique(TRUE, -REEL_MAX, REEL_MAX);
  fprintf(  stdout, "Nombre réel saisi %Lg \n", valeur_double_float);

  return EXIT_SUCCESS;
}
