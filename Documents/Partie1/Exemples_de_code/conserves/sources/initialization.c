/* initialization.c (inclus dans le programme de calcul
 * des dimensions d'une boite de conserve circulaire)
 * écrit dans le but de minimiser la surface de métal utilisée.
 * Auteur:  Eric Bachard  / 3 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include "initialization.h"

void initialisation()
{
    fprintf ( stdout,
              "\nDonnez, en L, le volume de la boite de conserve. Cette valeur doit etre comprise entre %d et %d \n \nVolume entré : ",
              VALEUR_MIN , VALEUR_MAX
            );
}

