/*
 * Fichier d'en tête donnees.h pour le projet OSS Sans baguette
 * Auteur : Eric Bachard  / vendredi 27 mai 2016, 18:52:55 (UTC+0200)
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __DONNEES__H__
#define __DONNEES__H__
#include "saisie.h"

#define LINE_SIZE_MAX      2048

#define ARRAY_SIZE           10
#define NUMBER_OF_LINES      ARRAY_SIZE
#define NUMBER_OF_COLUMNS    ARRAY_SIZE

#define DATA_FULL_NAME          "../ressources/donnees.txt"

#define DATA_FULL_NAME_LENGTH                        27

void create_data_filename(void);
short int ouverture_base(char **);

char nom_fichier_donnees[DATA_FULL_NAME_LENGTH];

typedef struct Case
{
  char case_description[LINE_SIZE_MAX];
  char case_instruction_NORD[LINE_SIZE_MAX];
  char case_instruction_SUD[LINE_SIZE_MAX];
  char case_instruction_EST[LINE_SIZE_MAX];
  char case_instruction_OUEST[LINE_SIZE_MAX];
  BOOL b_continuer_NORD_possible;
  BOOL b_continuer_SUD_possible;
  BOOL b_continuer_EST_possible;
  BOOL b_continuer_OUEST_possible;
} CASE;

/* jeu[coord_X, coord_Y] = tableau de cases */

//extern CASE jeu[NUMBER_OF_LINES][NUMBER_OF_COLUMNS];

void chercher_case( short int, short int);
void affichage_case( short int, short int);

#endif /* __DONNEES__H__ */

