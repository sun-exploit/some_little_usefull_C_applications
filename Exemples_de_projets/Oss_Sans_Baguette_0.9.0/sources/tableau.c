#include <stdio.h>
#include <stdlib.h>

#include "saisie.h"
#include "donnees.h"
#include "fonction_jeu.h"
#include "menujeu.h"
#include "directions.h"

static void perdu(void)
{
  fprintf(stdout, "\n\t\tImpossible : Mépo se sent faible et n'ose pas continuer ...\n");
}

int compteur_x = 0;
int compteur_y = 0;
char *Tableau [ARRAY_SIZE][ARRAY_SIZE];
extern CASE jeu[ARRAY_SIZE][ARRAY_SIZE];

void affichage_case( short int coord_X, short int coord_Y)
{
  fprintf(stdout, "\nContenu de la case de coordonnées (%hd,%hd) :\n \
Description      : %s\n \
Instruction NORD : %s , Aller vers le nord possible : %hd \n \
Instruction SUD  : %s , Aller vers le sud possible  : %hd \n \
Instruction EST  : %s , Aller vers l'est possible   : %hd \n \
Instruction OUEST: %s , Aller vers l'ouest possible : %hd \n",
          coord_X,
          coord_Y,
          jeu[coord_X][coord_Y].case_description,
          jeu[coord_X][coord_Y].case_instruction_NORD , jeu[coord_X][coord_Y].b_continuer_NORD_possible,
          jeu[coord_X][coord_Y].case_instruction_SUD  , jeu[coord_X][coord_Y].b_continuer_SUD_possible,
          jeu[coord_X][coord_Y].case_instruction_EST  , jeu[coord_X][coord_Y].b_continuer_EST_possible,
          jeu[coord_X][coord_Y].case_instruction_OUEST, jeu[coord_X][coord_Y].b_continuer_OUEST_possible);
}

int tableau(void)
{
  int Tabl_x = rand() % ARRAY_SIZE;
  int Tabl_y = rand() % ARRAY_SIZE;
  int retour = 0;

  while (retour != 1)
  {
#ifdef DEBUG
    affichage_case( Tabl_y, Tabl_x);
#endif
    fprintf(stdout, "\n\t\tDescription  : %s\n", jeu[Tabl_y][Tabl_x].case_description);
    switch (menu_etape(Tabl_y, Tabl_x))
    {
      case DIRECTION_NORD:
      {
        if ( (Tabl_y < 9) && (jeu[Tabl_y][Tabl_x].b_continuer_NORD_possible) )
        {
#ifdef DEBUG
          fprintf(stdout, "\n\t\tDescription  : %s\n", jeu[Tabl_y][Tabl_x].case_description);
#endif
          fprintf(stdout, "\n\t\tNord  : %s\n\n", jeu[Tabl_y][Tabl_x].case_instruction_NORD);
          Tabl_y++;
        }
        else
          perdu();
      }
      break;

      case DIRECTION_SUD:
      {
        if ( (Tabl_y > 0) && (jeu[Tabl_y][Tabl_x].b_continuer_SUD_possible) )
        {
#ifdef DEBUG
          fprintf(stdout, "\n\t\tDescription  : %s\n", jeu[Tabl_y][Tabl_x].case_description);
#endif
          fprintf(stdout, "\n\t\tSUD  : %s\n\n", jeu[Tabl_y][Tabl_x].case_instruction_SUD);
          Tabl_y--;
        }
        else
          perdu();
      }
      break;

      case DIRECTION_EST:
      {
        if ( (Tabl_x < 9) && (jeu[Tabl_y][Tabl_x].b_continuer_EST_possible) )
        {
#ifdef DEBUG
          fprintf(stdout, "\n\t\tDescription  : %s\n", jeu[Tabl_y][Tabl_x].case_description);
#endif
          fprintf(stdout, "\n\t\tEST  : %s\n\n", jeu[Tabl_y][Tabl_x].case_instruction_EST);
          Tabl_x++;
        }
        else
          perdu();
      }
      break;

      case DIRECTION_OUEST:
      {
        if ( (Tabl_x > 0) && (jeu[Tabl_y][Tabl_x].b_continuer_OUEST_possible) )
        {
#ifdef DEBUG
          fprintf(stdout, ":\n\t\tDescription  : %s\n", jeu[Tabl_y][Tabl_x].case_description);
#endif
          fprintf(stdout, "\n\t\tOUEST  : %s\n\n", jeu[Tabl_y][Tabl_x].case_instruction_OUEST);
          Tabl_x--;
        }
        else
          perdu();
      }
      break;

      case QUITTER:
      {
        fprintf(stdout, "\n\t\tFin du jeu ...\n");
        retour = 1;
      }
      break;

      default:
      break;
    }
  }
  return EXIT_SUCCESS;
}
