/* Couleur
 * Auteur :  Eric Bachard, novembre 2010
 * Licence LGPL
 */

#include <stdlib.h>
#include <stdio.h>
#include "couleur.h"

COULEUR aColor = JAUNE;

int main (void)
{
    fprintf( stdout, " Couleur JAUNE vaut %d \n", aColor);
    aColor = VERT;
    fprintf( stdout, " Couleur VERT vaut %d \n", aColor);
    aColor = ROUGE;
    fprintf( stdout, " Couleur ROUGE vaut %d \n", aColor);
    aColor = BLEU;
    fprintf( stdout, " Couleur BLEU vaut %d \n", aColor);
    return EXIT_SUCCESS;
}
