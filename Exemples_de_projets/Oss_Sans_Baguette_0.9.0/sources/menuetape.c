/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "saisie.h"
#include "donnees.h"

extern CASE jeu[ARRAY_SIZE][ARRAY_SIZE];

int menu_etape( short int coord_Y, short int coord_X)
{
  int action = 0;

  while (action < 1 || action > 5)
  {
#ifndef DEBUG
    fprintf(stdout, "\n\t\t1 - Nord\n");
    fprintf(stdout, "\t\t2 - Sud\n");
    fprintf(stdout, "\t\t3 - Est\n");
    fprintf(stdout, "\t\t4 - Ouest\n");
#else
    fprintf(stdout, "\n\t\t1 - Nord  : %s\n", jeu[coord_Y][coord_X].case_instruction_NORD);
    fprintf(stdout, "\t\t2 - Sud   : %s\n", jeu[coord_Y][coord_X].case_instruction_SUD);
    fprintf(stdout, "\t\t3 - Est   : %s\n", jeu[coord_Y][coord_X].case_instruction_EST);
    fprintf(stdout, "\t\t4 - Ouest : %s\n", jeu[coord_Y][coord_X].case_instruction_OUEST);
#endif
    fprintf(stdout, "\n\t\t5 - Fin du jeu\n");
    fprintf(stdout, "\n\t\tVotre action : ? ");

    action = saisie_nombre_entier_court(1,5);
    fprintf(stdout, "\n");
  }
#ifndef DEBUG
  efface_ecran();
#endif
  return action;
}
