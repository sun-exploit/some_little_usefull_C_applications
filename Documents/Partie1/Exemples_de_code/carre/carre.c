#include <stdio.h>
#include <stdlib.h>
#define VALEUR_X 10
#define CARRE(x)  (x)*(x)

int
main (void)
{
    /* int x = 3;*/
    fprintf (stdout,"le carré de %d + 1 vaut : %d\n", VALEUR_X, CARRE (VALEUR_X + 1));
    return EXIT_SUCCESS;
}
