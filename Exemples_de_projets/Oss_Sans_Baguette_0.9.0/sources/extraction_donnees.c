/* fichier main.c (fait partie de test_strtok)
 * Auteur:  Eric Bachard  / vendredi 3 juin 2016, 11:00:20 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "donnees.h"
#include "extraction.h"

CASE jeu[NUMBER_OF_LINES][NUMBER_OF_COLUMNS];

short int extraction_donnees(void)
{
  char * a_coordinates = 0;
  char * a_Case_description = 0;
  char * Nord_description = 0;
  char * Sud_description = 0;
  char * Est_description = 0;
  char * Ouest_description = 0;
  char   ligne[LINE_SIZE_MAX];
  FILE * fichier;

  create_data_filename();
#ifdef DEBUG
  fprintf(stdout, "Nom du fichier à ouvrir : %s \n", nom_fichier_donnees);
#endif
  /* on ouvre le nom du fichier donnees.txt s'il existe dans le répertoire ../ressources/ */
  fichier = fopen(nom_fichier_donnees, "r");
  if (fichier != NULL)
  {
#ifdef DEBUG
    fprintf(stdout, "fichier correctement créé (%p) \n",(void*) fichier);
#endif
    while ( (fgets(ligne, sizeof(ligne), fichier) != NULL && !feof(fichier)) ) /* Lire une ligne */
    {
      BOOL   b_Nord_possible  = TRUE;
      BOOL   b_Sud_possible   = TRUE;
      BOOL   b_Est_possible   = TRUE;
      BOOL   b_Ouest_possible = TRUE;

      a_coordinates = strtok(ligne, "#"); /* coord_X , coord_Y, suivi du premier # */
      a_Case_description = strtok(NULL, "#");

      if (strcmp( "N", strtok(NULL, "#")) != 0 )
        b_Nord_possible = FALSE;

      Nord_description = strtok(NULL, "#");

      if (strcmp( "S", strtok(NULL, "#")) != 0 )
        b_Sud_possible = FALSE;

      Sud_description = strtok(NULL, "#");

      if (strcmp( "E", strtok(NULL, "#")) != 0 )
        b_Est_possible = FALSE;

      Est_description = strtok(NULL, "#");

      if (strcmp( "O", strtok(NULL, "#")) != 0 )
        b_Ouest_possible = FALSE;

      Ouest_description = strtok(NULL, "#");

      /* remove the '\n' char present in Ouest_description */
      if (Ouest_description)
      {
        char * aChar = strchr(Ouest_description,'\n');
        if (aChar != NULL)
          *aChar = '\0';
      }
      /* extraction des coordonnées */
      short int aCoord_X = (short int)strtol(strtok(a_coordinates, ","), (char **)NULL, 10);
      short int aCoord_Y = (short int)strtol(strtok(NULL, ","), (char **)NULL, 10);

      remplissage_tableau( aCoord_X, aCoord_Y,
                           a_Case_description,
                           Nord_description, Sud_description, Est_description, Ouest_description,
                           b_Nord_possible, b_Sud_possible, b_Est_possible, b_Ouest_possible);
#ifdef DEBUG
      affichage_case(aCoord_X, aCoord_Y);
#endif
    }
  }
  else
    fprintf(stdout, "Problème à l'ouverture ... \n");

  if (fichier)
    fclose(fichier);

  return EXIT_SUCCESS;
}

