/* fichier .c (fait partie de test_strtok)
 * Auteur:  Eric Bachard  / vendredi 3 juin 2016, 11:00:20 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "initialisation.h"
#include "extraction.h"

static short int anErr = 0;

extern CASE jeu[ARRAY_SIZE][ARRAY_SIZE];

int main(int argc, char *argv[])
{
  anErr = initialisation(argv);
  if ( anErr != 0 )
  {
    fprintf(stdout,"problème d'initialisation ... terminé");
    return EXIT_FAILURE;
  }
#ifdef DEBUG
  else
    fprintf(stdout, "Initialisation OK\n");
#endif

  menujeu();

  return EXIT_SUCCESS;
}
