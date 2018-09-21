/* calcul_rayon.c (inclus dans le programme de calcul 
 * des dimensions d'une boite de conserve circulaire)
 * écrit dans le but de minimiser la surface de métal utilisée.
 * Auteur:  Eric Bachard  / 3 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "calcul_rayon.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

long double calcul_rayon( long double volume )
{
#ifdef DEBUG
  fprintf( stdout, "Fonction en cours d'execution : %s \n", __func__ );
  fprintf( stdout, "Valeur de volume (dans calcul rayon) : %Lf \n", volume);
#endif
  return ( powl ( ( (0.001 * volume) / (2 * M_PI) ) , 1.0/3.0));
}

