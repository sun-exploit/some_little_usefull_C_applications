/* saisie.c (inclus dans le programme de calcul des dimensions
 * d'une boite de conserve circulaire)
 * écrit dans le but de minimiser la surface de métal utilisée.
 * partie saisie d'un nombre
 * Auteur:  Eric Bachard  / 3 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "saisie.h"
#include "initialization.h"
#include "boolean.h"

/* on suppose que la chaine saisie est correcte par defaut */
BOOL bString_Is_OK = TRUE;

/* saisie du volume de la boite */
long double saisie_volume()
{
  char saisie[TAILLE_BUFFER];
  char temp[TAILLE_BUFFER];

  /* au moins une fois */
  do
  {
    /*
      il faut vider le contenu de temp a chaque iteration car si on entre une
      chaine de caracteres quelconque on ne sort pas de la boucle 
      (le contenu n'est plus un nombre) 
     */

    int i = 0;
    for (i = 0; i < 10 ; i++) 
    {
      temp[i]=0;
      saisie[i]='0';
    } 

    /* on saisit la chaine */
    char * aChar = fgets( saisie, sizeof saisie, stdin);

    if (aChar == NULL)
        fprintf(stdout, "Pb with fgets");

    /* initialization du nombre de non-chiffres */
    short int count = 0;

    /* initialisation du nombre de points ou de virgules dans la chaine entree */
    short int dots_count = 0;

    for (i = 0; i < TAILLE_BUFFER ; i++)
    {
      if ( ( saisie[i] == '.') ||
           ( saisie[i] == ',')
         )
      {
        /* on force le point decimal
           (cosmetique, mais transparent pour l'utilisateur
           qui peut utiliser l'un ou l'autre sans se poser de questions
         */
        saisie[i] = '.';
        dots_count += 1;
      }

      if ( !isdigit(saisie[i]) && ( saisie[i] == '.' ) )
        count += 1;

#ifdef DEBUG
      fprintf( stdout, "Fonction en cours d'execution : %s \n", __func__ );
      fprintf( stdout, "Valeur de saisie[%d] : %d \n", i, saisie[i]);
      fprintf( stdout, "Valeur de dots_count: %d \n", dots_count);
      fprintf( stdout, "Valeur de count: %d \n", count);
#endif
    }

    if (dots_count > 1 )
    {
      bString_Is_OK = FALSE;
      count += 1; /* means bad string entered, because we accept only one */
    }

    /* si que des chiffres, count = 0 (non chifres) + 2 characteres de fin de chaine */
    if (count < 3)
      sscanf (saisie, "%[0-9,.,-,+]s", temp);
    else
      bString_Is_OK = FALSE;

#ifdef DEBUG
    fprintf( stdout, "Valeur de temp : %d \n", *temp);
#endif
  }
  /* while ( ( atoi(temp) < VALEUR_MIN ) || ( atoi(temp) > VALEUR_MAX) );*/
  while ( ( strtol(temp, (char **)NULL, 10) < VALEUR_MIN ) || ( strtol(temp, (char **)NULL, 10) > VALEUR_MAX) );

  /* IMPORTANT : ancienne methode (obsolete) : */
  /*  return atof(temp);  */
  return strtod(temp, (char **)NULL);
}

