/* fichier .c (fait partie de test_strtok)
 * Auteur:  Eric Bachard  / vendredi 3 juin 2016, 11:00:20 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "saisie.h"
#include "donnees.h"
#include "initialisation.h"

CASE jeu[NUMBER_OF_LINES][NUMBER_OF_COLUMNS];

short int remplissage_tableau(short int aCoord_X, short int aCoord_Y, char * descr, char * nord, char * sud, char * est, char * ouest, BOOL b_Nord, BOOL b_Sud, BOOL b_Est, BOOL b_Ouest)
{
  if (descr != NULL )
    strcpy( jeu[aCoord_X][aCoord_Y].case_description, descr);

  if (nord != NULL )
    strcpy( jeu[aCoord_X][aCoord_Y].case_instruction_NORD, nord);

  if (sud != NULL )
    strcpy( jeu[aCoord_X][aCoord_Y].case_instruction_SUD, sud);

  if (est != NULL )
    strcpy( jeu[aCoord_X][aCoord_Y].case_instruction_EST, est);

  if (ouest != NULL )
    strcpy( jeu[aCoord_X][aCoord_Y].case_instruction_OUEST, ouest);

  jeu[aCoord_X][aCoord_Y].b_continuer_NORD_possible  = b_Nord;
  jeu[aCoord_X][aCoord_Y].b_continuer_SUD_possible   = b_Sud;
  jeu[aCoord_X][aCoord_Y].b_continuer_EST_possible   = b_Est;
  jeu[aCoord_X][aCoord_Y].b_continuer_OUEST_possible = b_Ouest;

  return EXIT_SUCCESS;
}


