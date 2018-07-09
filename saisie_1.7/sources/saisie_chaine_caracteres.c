/* saisie_chaine_caracteres.c from saisie_project
 * Author : Eric Bachard Mai 2005
 * This document is under GPL v2 License
 * See : http://www.gnu.org/licenses/gpl-2.0.html */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saisie_chaine.h"

void lit_entree (char *aString)
{
  short int anErr = (fgets(aString, sizeof(g_buf), stdin) == NULL);
  if ( anErr != 0 )
    fprintf(stdout, "Problème avec la valeur saisie \n");

  clean_string(aString, stdin);
}

void clean_string(const char *g_buf, FILE *aStream)
{
  char * aChar = strchr(g_buf,'\n');

  if (aChar != NULL)
    *aChar = 0;
  else
  {
    int aCharValue;
    while ((aCharValue = fgetc(aStream)) != '\n' && aCharValue != EOF);
  }
}

short int saisie_chaine_de_caracteres(BOOL bShow)
{
  initialize_string(g_buf);
  char * entree = g_buf;
  lit_entree (entree);

  if (TRUE == bShow)
    fprintf (stdout, "Vous avez saisi :  %s\n", entree);

  return EXIT_SUCCESS;
}

void initialize_string (char * aString)
{
  size_t aSize = sizeof(aString);

  /* to avoid security issue, 
     using -fno-builtin-memset gcc option at build time
   */
  memset(aString, '\0', aSize);
}
