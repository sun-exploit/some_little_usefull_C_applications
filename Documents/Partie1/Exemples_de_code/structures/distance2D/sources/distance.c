/* Calcul distance entre 2 points 
 * Auteur :  Eric Bachard, novembre 2010
 * Licence LGPL
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include <math.h>

/* declaration */

POINT2D  P1;
POINT2D  P2;

int main( void )
{
    /* initialisation */

    P1.x = 0.0;
    P1.y = 0.0;
    P2.x = 1.0;
    P2.y = 1.0;

    float distance = sqrt ( ( P1.x - P2.x ) * ( P1.x - P2.x ) +  ( P1.y - P2.y ) * ( P1.y - P2.y ) );
    fprintf( stdout, "distance = %f \n", distance);
    return EXIT_SUCCESS;
}
