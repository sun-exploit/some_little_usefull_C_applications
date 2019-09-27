/* test_saisies_nombres.c from saisie project
 * Author: Eric Bachard / Ven 29 mai 2015 13:59:01 CEST
 * This document is under GPL v2 License
 * See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "saisie.h"
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

  fprintf(  stdout, "Saisir un nombre entier court compris entre %hd et %hd : ", SHRT_MIN, SHRT_MAX);
  short int valeur_short_int = saisie_nombre_entier_court(SHRT_MIN, SHRT_MAX);

  fprintf(  stdout, "Nombre entier court saisi %hd \n", valeur_short_int );
  fprintf(  stdout,
            "Verification : le nombre saisi eleve au carre vaut %d \n",
            (int) valeur_short_int * valeur_short_int
         );
  return EXIT_SUCCESS;
}

short int
test_saisie_entier_long(void)
{

  fprintf(  stdout, "Saisir un nombre entier court compris entre %lld et %lld : ", LLONG_MIN, LLONG_MAX);

  long long int valeur_long_int = saisie_nombre_entier_long(LLONG_MIN, LLONG_MAX);

  fprintf(  stdout, "Nombre entier long saisi %lld \n", valeur_long_int );
  fprintf(  stdout,
            "Verification : le nombre saisi eleve au carre vaut %Lg \n",
            (long double)valeur_long_int * (long double)valeur_long_int);
  return EXIT_SUCCESS;
}

short int
test_saisie_reel(void)
{

  fprintf(  stdout, "Entrer un nombre reel compris entre %g et %g : ", -REEL_MAX, REEL_MAX);
  long double  valeur_double_float = saisie_nombre_reel(-REEL_MAX, REEL_MAX );

  fprintf(  stdout, "Nombre reel saisi %Lg \n", valeur_double_float);
  fprintf(  stdout,
            "Verification : le nombre saisi eleve au carre vaut %Lg \n",
            (long double)valeur_double_float * (long double)valeur_double_float);

  return EXIT_SUCCESS;
}

short int
test_saisie_reel_notation_scientifique(void)
{

  fprintf(  stdout, "Saisir un nombre reel en notation scientifique, et compris entre %g et %g : ", -REEL_MAX, REEL_MAX);

  long double  valeur_double_float = saisie_nombre_scientifique(-REEL_MAX, REEL_MAX);

  fprintf(  stdout, "Nombre reel saisi %Lg \n", valeur_double_float);

  return EXIT_SUCCESS;
}
