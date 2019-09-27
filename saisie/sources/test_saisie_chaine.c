/* test_saisie_chaine.c from saisie project
 * Author: Eric Bachard / Ven 29 mai 2015 13:59:01 CEST
 * This document is under GPL v2 License
 * See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "saisie.h"

short int
test_saisie_chaine(void)
{
  char chaine_saisie[MAX_BUFFER_SIZE];
  fprintf (stdout, "saisissez une chaine de caracteres (et appuyez sur la touche Entree) : ");
  saisie_chaine_de_caracteres();
  strlcpy(chaine_saisie, g_buf, sizeof(g_buf));

  fprintf(stdout, "vous avez tape la chaine de caracteres : %s \n", chaine_saisie);
  return EXIT_SUCCESS;
}
