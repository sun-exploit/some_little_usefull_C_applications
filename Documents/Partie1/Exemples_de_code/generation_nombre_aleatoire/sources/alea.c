#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "saisie.h"
#include "initialize_rand.h"

int
main (void)
{
    initialize_rand();

    short int tirage = 0;
    short int valeur = 0;
    efface_ecran();


    for (tirage = 1 ; tirage < 5 ; tirage ++)
    {
       fprintf( stdout, "Tirage numéro :  %hd\n", tirage);
       for (valeur = 1 ; valeur < 7 ; valeur++ )
       {
             fprintf(stdout, " %u ", (unsigned  int) rand() % 49 + 1);
       }
             fprintf(stdout, "\n");
    }
    return EXIT_SUCCESS;
}


