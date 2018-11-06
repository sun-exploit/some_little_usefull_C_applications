/* fichier ouverture_base_donnees.c (fait partie de test_strtok)
 * Auteur:  Eric Bachard  / vendredi 3 juin 2016, 11:00:20 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

#include "donnees.h"
#include "extraction.h"

static short int anErr = 0;

void create_data_filename(void)
{
  memset(nom_fichier_donnees, '\0', sizeof(nom_fichier_donnees));
  strcpy(nom_fichier_donnees, DATA_FULL_NAME);
}

/* noter le schéma pour l'appel utilisant argv[0] (mais aussi les autres paramètres argv[1], etc) */
/*
  Dans main.c  : 
  1. on utilise : int main ( int argc, char* argv[]) : argc = nombre d'arguments, 
                                               argv[] adresse des tableaux de caractères (=les arguments)
  2. on appelle initialisation(argv) avec un char ** comme argument (si argv[] est un char *, argv est un char **)

  dans donnees.h, on déclare ouverture_base avec l'argument de type char **
    short int ouverture_base(char **);

  dans initialisation.h, on déclare initialisation avec un argument de type char ** aussi
    short int initialisation(char **);

  But => main passe argv en argument à initialisation(), qui le repasse à ouverture_base() :

  1. dans main.c, on appelle initialisation avec l'argument argv :
    short int anErr = initialisation( argv );

  2. dans initialisation.c, on appelle ouverture_base avec l'argument argv
    short int anErr = ouverture_base(argv);

  => on peut ainsi utiliser les paramètres passés au programme lors du lancement, et ce,
     ailleurs que dans main dont ce n'est pas le rôle
*/

short int ouverture_base(char ** argv)
{
#ifdef DEBUG2
  /* essais pour le bootstrap*/
  /* normalement : se placer dans le répertoire 
   * cwd + build et cela fonctionnera
   * mais en production, on devra copier (la première fois)
   * puis lire la base de données dans : 
     $HOME/.local/share/OSS100baguette/ressources
   * (emplacement conseillé pour un utilisateur lambda)
   */
  char * prog = basename(argv[0]);
  fprintf(stdout, "Nom du programme = %s\n", prog);

  char * repertoire = dirname(argv[0]);
  fprintf(stdout, "Nom du répertoire de base = %s\n", repertoire);

  char my_cwd[1024];
  if ( (getcwd(my_cwd, 1024) != NULL) )
    fprintf(stdout, "Répertoire courant = %s\n", my_cwd);
  else
    fprintf(stdout, "pas trouvé le répertoire courant)\n");

  char * home_dir = getenv("HOME");
  fprintf(stdout, "Répertoire home = %s\n", home_dir);
#endif

  anErr = extraction_donnees();
  if ( anErr != 0 )
  {
    fprintf(stdout,"problème avec la base de données ... terminé");
    return EXIT_FAILURE;
  }
#ifdef DEBUG
  else
    fprintf(stdout, "Extraction de données OK\n");
#endif
  return EXIT_SUCCESS;
}

