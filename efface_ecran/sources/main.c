#include <stdio.h>
#include <stdlib.h>
#include "efface_ecran.h"

int main (void)
{
    efface_ecran();
    fprintf(stdout, "Appuyer sur la touche entrée pour continuer ...\n");
    getchar();
    efface_ecran();
    fprintf(stdout, "Écran effacé une seconde fois\n");

    return EXIT_SUCCESS;
}
