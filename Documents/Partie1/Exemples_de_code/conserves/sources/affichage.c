/* affichage.c (inclus dans le programme de calcul 
 * des dimensions d'une boite de conserve circulaire)
 * écrit dans le but de minimiser la surface de métal utilisée.
 * Auteur:  Eric Bachard  / 3 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "calcul_rayon.h"
#include "affichage.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

BOOL bString_Is_OK;

void affichage( long double volume )
{
  if ( TRUE == bString_Is_OK )
  {
    long double rayon_optimal = calcul_rayon( volume );
#ifdef DEBUG
    fprintf( stdout, "Valeur de volume dans %s : %Lf \n", __func__ , volume );
    fprintf( stdout, "Valeur du rayon optimal : %Lf \n", rayon_optimal);
#endif
    fprintf( stdout, "\nResultat : ");
    fprintf (stdout, "le rayon qui donne S minimal pour V = %2.4Lf L, est R = %2.4Lf m \n", volume, rayon_optimal );
    fprintf (stdout, "\nla hauteur h nécessaire est %2.4Lf m \n\n", 2 * rayon_optimal);
  }
  else
    fprintf (stdout, "La valeur entree pour le volume est incorrecte. \n");
}
