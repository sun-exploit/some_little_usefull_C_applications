/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdlib.h>
#include <stdio.h>

#include "fonction_jeu.h"
#include "saisie.h"

int bouclejeu(void)
{
#ifndef DEBUG
  efface_ecran();
#endif
  tableau();
  return EXIT_SUCCESS;
}
