/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdlib.h>
#include <stdio.h>

#include "menujeu.h"
#include "saisie.h"

#define CHOIX_JEU            1
#define CHOIX_REGLE          2
#define CHOIX_FICHE_PERSO    3
#define SECRET_OPTION        666
#define CHOIX_QUITTER        4

int menujeu(void)
{
  BOOL b_Quitter = FALSE;
  do
  {
#ifndef DEBUG
    efface_ecran();
#endif
    fprintf(stdout, "\n\t\t=== Oss Sans Baguette ===\n\n");
    switch (choix_menujeu())
    {
      case CHOIX_JEU:
        bouclejeu();
        break;

      case CHOIX_REGLE:
        regle();
        break;

      case CHOIX_FICHE_PERSO:
        ficheperso();
        break;

      case CHOIX_QUITTER: 
        b_Quitter = TRUE;
        break;

      case SECRET_OPTION:
        option();
        break;

    }
  } while ( FALSE == b_Quitter );
  credits();
  return EXIT_SUCCESS;
}
