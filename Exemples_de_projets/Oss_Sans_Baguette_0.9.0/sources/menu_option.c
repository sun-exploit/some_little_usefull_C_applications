/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "saisie.h"

int menu_option()
{
  int action = 0;

  while (action < 1 || action > 5)
  {
      fprintf(stdout, "\n\t1 - Classique\n");
      fprintf(stdout, "\t2 - Calme\n");
      fprintf(stdout, "\t3 - Pixel\n");
      fprintf(stdout, "\t4 - Innocent\n");
      fprintf(stdout, "\t5 - Retour\n");
      fprintf(stdout, "\n");
      action = saisie_nombre_entier_court(1, 5);
  }
#ifndef DEBUG
  efface_ecran();
#endif
  return action;
}
