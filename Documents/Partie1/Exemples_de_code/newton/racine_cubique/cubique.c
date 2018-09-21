/* algorithme de Newton, appliqué au calcul d'une racine carrée */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RACINE_A_CALCULER  27.0
#define VALEUR_DEPART 10.0
#define EPSILON 1e-9

int main(void)
{
  double erreur = 0.0;
  int compteur = 0;
  double xn = VALEUR_DEPART;
  while ( fabs( RACINE_A_CALCULER - (xn * xn * xn)) > EPSILON)
  {
    erreur = fabs( RACINE_A_CALCULER - (xn * xn * xn));
    xn = (1.0/3.0)*( 2*xn + (RACINE_A_CALCULER / (xn * xn) ));
    compteur++;
    fprintf( stderr, "compteur vaut : %d ; erreur : %lf \n", compteur, erreur);
  }
  fprintf (stdout, "Racine cubique de %.3lf = %.3lf, obtenue en %d iterations \n",RACINE_A_CALCULER  , xn, compteur);
  return EXIT_SUCCESS;
}

