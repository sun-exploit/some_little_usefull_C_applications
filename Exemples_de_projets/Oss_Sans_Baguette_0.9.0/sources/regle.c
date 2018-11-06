/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdlib.h>
#include <stdio.h>

#include "saisie.h"

int regle(void)
{
  int choix = 0;
  BOOL b_Quitter = FALSE;

  do
  {
#ifndef DEBUG
    efface_ecran();
#endif
    fprintf(stdout, "\n\t\t=== Oss Sans Baguette ===\n\n");
    fprintf(stdout, "\t\tRègles du jeu\n\n");

    fprintf(stdout, "\t   Bonjour et bienvenue dans OSS Sans Baguette !\n\n\tC'est un jeu RP (jeu de rôle) dans lequel vous incarnez Mépo, un Jungilos,\n\tchargé d'aller chercher du pain à la boulangerie.\n\n\tVous vous déplacerez à l'aveugle dans un labyrinthe à l'aide de la console et\n\tdes chiffres de 1 à 4.\n\n\tVos déplacements et vos actions seront narrées pour une immersion totale.\n\n\tNous vous conseillons alors de dessiner une carte sur papier pour ne pas vous\n\tperdre, car vous serez amené à trouver de l'argent avant d'aller acheter du pain.\n\n\tL'équipe BLARP vous souhaite une expérience de jeu agréable\n\tet vous remercie de jouer !\n\n");

      fprintf(stdout, "\t\t1 - Quitter\n");
      fprintf(stdout, "\n");

      choix = saisie_nombre_entier_court(1, 1);

      if (choix == 1)
        b_Quitter = TRUE;

    }  while ( FALSE == b_Quitter );

  return EXIT_SUCCESS;
}
