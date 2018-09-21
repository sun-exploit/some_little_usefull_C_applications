/* saisie.c from saisie project
 * Author: Eric Bachard / Ven 29 mai 2015 13:59:01 CEST
 * This document is under GPL v2 License. See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "saisie_nombre.h"
#include "saisie_chaine.h"
#include "boolean.h"


long double saisie_nombre_reel(BOOL bAsk, long double Lfmin, long double Lfmax)
{
  if (Lfmin > Lfmax)
  {
    fprintf(stderr, "Problème avec les limites");
    exit(EXIT_FAILURE);
  }
  bString_Is_OK = TRUE;
  char saisie[MAX_BUFFER_SIZE];
  char temp[MAX_BUFFER_SIZE];

  do
  {
    bString_Is_OK = TRUE;
    initialize_string(temp);
    initialize_string(saisie);

    if ( (TRUE == bAsk) )
        fprintf(stdout, "Saisir un nombre réel : ");

    short int noErr = saisie_chaine_de_caracteres(FALSE);
    if ( noErr != 0 )
      fprintf(stdout, "Problème avec la valeur saisie \n");

    strcpy(saisie, g_buf);
    calcule_signe(saisie);
    short int dots_count = 0;

    if ( !(isdigit(saisie[0])) && (saisie[0] != '-') && (saisie[0] != '.') )
      bString_Is_OK = FALSE;

    short int indice2 = 1;
    while ( (saisie[indice2] != '\0') && ( indice2 < MAX_BUFFER_SIZE ) )
    {
#ifdef DEBUG
      fprintf(stderr, "saisie[%hd] == %c \n", indice2, saisie[indice2]);
#endif
      if ( ( saisie[indice2] == '.') || ( saisie[indice2] == ',') )
      {
        saisie[indice2] = '.'; /* We force decimal point (cosmetic, but transparent for the user) */
        dots_count += 1;
      }
      if ( !isdigit(saisie[indice2]) && (saisie[indice2] != '.' )
                               && (saisie[indice2] != '-' )
                               && (saisie[indice2] != '+' )
                               && (saisie[indice2] != 'E' )
                               && (saisie[indice2] != 'e' )
         )
         bString_Is_OK = FALSE;

      indice2++;
    }

    if ( (dots_count > 1) )
      bString_Is_OK = FALSE;

    if ( TRUE == bString_Is_OK ) /* If only digits, count = 0 (not digits) + 1 character ending the string */
    {
      /* IMPORTANT : the character type order seems to count  when checking the string !*/
      short int aRealErr = sscanf (saisie, "%[-,+,0-9,e,.]s", temp);
#ifdef DEBUG
      fprintf(stderr,"aRealErr : %d \n", aRealErr);
#endif
      (void)aRealErr; // makes the compiler happy
    }
#ifdef DEBUG
  fprintf( stderr, "temp = %s \n", temp);
  fprintf( stderr, "strtod(temp, (char **)NULL) = %f \n", strtod(temp, (char **)NULL));
#endif
  } while ( (( strtod(temp, (char **)NULL) < Lfmin ) || (strtod(temp, (char **)NULL) > Lfmax)) || (bString_Is_OK == FALSE) );

  return strtod(temp, (char **)NULL);
}

// Work in progress

long double saisie_nombre_scientifique(BOOL bAsk, long double Lfmin, long double Lfmax)
{
  if (Lfmin > Lfmax)
  {
    fprintf(stderr, "Problème avec les limites");
    exit(EXIT_FAILURE);
  }

  bString_Is_OK = TRUE;
  char saisie[MAX_BUFFER_SIZE];
  char temp[MAX_BUFFER_SIZE];

  do
  {
    bString_Is_OK = TRUE;
    initialize_string(temp);
    initialize_string(saisie);

    if (TRUE == bAsk)
        fprintf(stdout, "Saisir un nombre réel en notation scientifique : ");

    short int noErr = saisie_chaine_de_caracteres(FALSE);
    if ( noErr != 0 )
      fprintf(stdout, "Problème avec la valeur saisie \n");

    strcpy(saisie, g_buf); /* destination, source */
    calcule_signe( saisie);

    if ( !(isdigit(saisie[0])) && (saisie[0] != '-') && (saisie[0] != '.') )
      bString_Is_OK = FALSE;

    short int dots_count = 0;
    short int indice3 = 1;
    while ( (saisie[indice3] != '\0') && ( indice3 < MAX_BUFFER_SIZE ) )
    {
#ifdef DEBUG
      fprintf(stderr, "saisie[%hd] == %c \n", indice3, saisie[indice3]);
#endif
      if ( ( saisie[indice3] == '.') || ( saisie[indice3] == ',') )
      {
        saisie[indice3] = '.'; /* We force decimal point (cosmetic, but transparent for the user) */
        dots_count += 1;
      }
      if (  !isdigit(saisie[indice3]) && (saisie[indice3] != '.' )
                                      && (saisie[indice3] != '-' )
                                      && (saisie[indice3] != '+' )
                                      && (saisie[indice3] != 'E' )
                                      && (saisie[indice3] != 'e' )
         )
         bString_Is_OK = FALSE;

      indice3++;
    }

    if (dots_count > 1 )
      bString_Is_OK = FALSE;

    if ( TRUE == bString_Is_OK ) /* If only digits, count = 0 (not digits) + 1 character ending the string */
    {
      /* IMPORTANT : the character type order seems to count  when checking the string !*/
      short int anErr = sscanf (saisie, "%[-,+,0-9,E,e,.]LLg", temp);
//      short int anErr = sscanf (saisie, "%[-,+,0-9,E,e,.]s", temp);
      (void)anErr; // makes the compiler happy
    }

  } while ( (( strtod(temp, (char **)NULL) < Lfmin ) || (strtod(temp, (char **)NULL)> Lfmax)) || (bString_Is_OK == FALSE));

  return strtod(temp, (char **)NULL);
}
