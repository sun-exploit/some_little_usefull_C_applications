/*  programme permettant de calculer la racine comprise entre
 *  3 et 4 de la fonction x^2 + x -16 = 0
 *  Pour commencer, on prendra epsilon = 1e-3
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double
fonction_f ( double valeur)
{
  return ( valeur * valeur + valeur - 16.0 );
}

int
main(void)
{
    int compteur = 0;
    double epsilon = 1e-3;
    double b_inf = 3.0;
    double b_sup = 4.0;
    double milieu = (b_inf + b_sup ) /2.0;

    while ( fabs ( fonction_f (milieu ))> epsilon)
    {
        if ( (fonction_f(b_inf)*fonction_f(milieu))>0 )
            b_inf = milieu;
        else
            b_sup = milieu;

        compteur++;
        milieu = (b_inf + b_sup ) /2.0;
    }
    fprintf( stdout, "La racine vaut : %lf, en %d iterations \n", milieu, compteur);
    return EXIT_SUCCESS;
}
