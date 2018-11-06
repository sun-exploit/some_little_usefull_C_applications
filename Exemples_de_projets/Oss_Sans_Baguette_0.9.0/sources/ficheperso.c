/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdlib.h>
#include <stdio.h>

#include "saisie.h"

int ficheperso(void)
{
  int choix = 0;
  BOOL b_Quitter = FALSE;

  do
  {
#ifndef DEBUG
    efface_ecran();
#endif
    fprintf(stdout, "\n\t\t=== Oss Sans Baguette ===\n\n");
    fprintf(stdout, "\t\t     Fiche Personnage\n\n");
    fprintf(stdout, "\t   Héros : Mépo\n");

    fprintf(stdout, "\tMépo est un étrange animal du clan des Jungilos. Les Jungilos sont de mignonnes petites créatures oursoïde vivant dans la jungle.\n\tMépo a la faculté étonnante d'être constamment et perpétuellement paumé. Son aspect de légume ne trompe personne.\n\tEn effet, cet être exeptionnel ne sais ni lire ni écrire et ajoute toujours 1 à chacune de ses aditions.\n\tToujours à l'arrière de la meute, il n'est jamais conscient du monde réel\n\tcela doit être à cause de la cuillère plantée dans sa tête...\n\tLa légende raconte que Mépo était, un jour, un grand guerrier capable de pourfendre des monstres démoniaques !\n\n");

    fprintf(stdout, "\t\t1 - Quitter\n");
    fprintf(stdout, "\n");

    choix = saisie_nombre_entier_court(1, 1);

    if (choix == 1)
      b_Quitter = TRUE;
  }  while ( FALSE == b_Quitter );

  return EXIT_SUCCESS;
}
