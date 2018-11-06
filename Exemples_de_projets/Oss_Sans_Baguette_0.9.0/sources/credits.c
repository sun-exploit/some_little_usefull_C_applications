/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include "saisie.h"

int credits()
{
#ifndef DEBUG
  efface_ecran();
#endif
  fprintf(stdout, "Ce jeu vous a été offert par l’équipe BLARP.\n");
  fprintf(stdout, "Baloute, Lag, Anium, Raton et Péri, vous remercient d'avoir joué dans la joie et la bonne humeur.\n");
  fprintf(stdout, "Merci également à M.Bachard pour son aide et ses conseils nous donnant ainsi la possibilité de créer ce jeu !\n");
  fprintf(stdout, "See U Soon, Maybe ! Si vous aimez ces petites bestioles, n'hésitez pas à faire un tour sur leur page Facebook !\n");
  fprintf(stdout, "(https://www.facebook.com/Jungilos/)\n");

  return EXIT_SUCCESS;
}
