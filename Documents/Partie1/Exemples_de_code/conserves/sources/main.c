/* programme de calcul des dimensions d'une boite de conserve circulaire
 * dans le but de minimiser la surface de métal utilisée.
 * Auteur:  Eric Bachard  / 3 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "initialization.h"
#include "calcul_rayon.h"
#include "affichage.h"
#include "saisie.h"

/* initialisation du volume */
long double volume = 0.0;

int main (void)
{
  initialisation();
  long double volume = saisie_volume();
#ifdef DEBUG
    fprintf( stdout, "Valeur de volume dans %s : %Lf \n", __func__ , volume );
#endif
   affichage (volume);
}
