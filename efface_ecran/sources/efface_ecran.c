/* efface_ecran.c                                                   *
 * Auteur : Eric Bachard  version originale : 2004   *
 * Ce document est sous Licence GPL v2               *
 * voir : http://www.gnu.org/licenses/gpl-2.0.html   */

#define _GNU_SOURCE
#include <stdio.h> 
#include <stdlib.h> 
#include "efface_ecran.h"

/* ---------efface_ecran------------ */

void efface_ecran(void)
{
    // ce qui suit remplace :
    // system("clear");

    FILE * stdout = popen("clear", "w");
    int anErr = pclose( stdout) ;

    if (anErr != 0 ) 
       fprintf(stderr,"problem with clear\n");
}

