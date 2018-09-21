/* algorithme de Newton, appliqué au calcul d'une racine carrée */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <saisie_nombre.h>

#define RACINE_A_CALCULER  20.0
#define VALEUR_DEPART 10.0
#define EPSILON 1e-9

int main(void)
{
  int compteur = 1;
  long double erreur = 0.0;
  long double xn = saisie_nombre_reel(TRUE, 0.0, 50.0 );

  while ( fabs( RACINE_A_CALCULER - (xn * xn)) > EPSILON)
  {
    erreur = fabs( RACINE_A_CALCULER - (xn * xn));
    xn = 0.50*( xn + (RACINE_A_CALCULER / xn));
    fprintf( stderr, "compteur vaut : %d ; erreur : %3.12Lf \n", compteur, erreur);
    compteur++;
  }
  fprintf (stdout, "Racine carrée de 20 = %3.10Lf, en %d iterations (erreur %3.12f)  \n", xn, compteur, fabs( RACINE_A_CALCULER - (xn * xn)));
  return EXIT_SUCCESS;
}

