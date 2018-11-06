/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "saisie.h"

int choix_menujeu()
{
  int action = 0;
  BOOL define = FALSE;

  while ((action < 1 || action > 4) && (action != 666))
  {
    if (define == FALSE)
    {
      fprintf(stdout, "\n\t1 - Jouer\n");
      fprintf(stdout, "\t2 - Règles\n");
      fprintf(stdout, "\t3 - Fiche personnage\n");
      fprintf(stdout, "\t4 - Quitter\n");
      fprintf(stdout, "\n");
      define = TRUE;
    }
      action = saisie_nombre_entier_court(1, 666);
  }
#ifndef DEBUG
  efface_ecran();
#endif
  return action;
}
