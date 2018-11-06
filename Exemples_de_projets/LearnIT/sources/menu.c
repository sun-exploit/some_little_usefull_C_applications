#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

void menu (void)
{
  BOOL b_Quit = FALSE;
  int choix = PROGRAM_QUIT; /* default */
  do
  {
    fprintf(stdout, "1. Vocabulaire Anglais-Français\n");
    fprintf(stdout, "2. Vocabulaire Français-Anglais\n");
    fprintf(stdout, "3. Ajouter des mots dans la bibliothèque Francais-Anglais\n"); /* Programme d'essai, n'intéragit pas dans le 1. et 2. */
    fprintf(stdout, "4. Quitter \n");
    fscanf(stdin, "%d",&choix);

#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif

    switch (choix)
    {
      case ENGLISH_TO_FRENCH:
      {
        VocabulaireAnglaisFrancais();
        break;
      }
      case FRENCH_TO_ENGLISH:
      {
        VocabulaireFrancaisAnglais();
        break;
      }
      case ADD_NEW_WORDS:
      {
        AjoutMotsVocabulaire();
        break;
      }
      case PROGRAM_QUIT:
      {
        b_Quit = TRUE;
        break;
      }
      default:
      break;
    }
  } while ( FALSE == b_Quit);
}
