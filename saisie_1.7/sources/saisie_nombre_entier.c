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
#include "strlcpy.h"

void calcule_signe( char * saisie)
{

  BOOL b_nombre_avec_signe = ( (saisie[0] == '-') || (saisie[0] == '+' ));

  if ( b_nombre_avec_signe )
  {
    short int index = 0;
    short int plus_minus_count = 0;
    short int minus_count = 0;
    while ( ((saisie[index] == '+') || (saisie[index] == '-')) && (index < MAX_BUFFER_SIZE))
    {
      if((saisie[index] == '-') )
        minus_count++;

      plus_minus_count++;
      index++;
    }
   /* signe = -1 à la puissance (nombre de fois le signe -) qui peut aussi s'écrire (nombre de signes -) modulo 2 */
    if ( (minus_count % 2 == 1) )
      saisie[0] = '-';
    else
      saisie[0] = '0';

    for (index = 1; index < plus_minus_count; index++)
    {
      saisie[index] = '0';
    }
  }
}

short int saisie_nombre_entier_court(BOOL bAsk, short int hd_min, short int hd_max)
{
  if (hd_min > hd_max)
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
    fflush(stdin);
    /* we must empty temp at every iteration else, the risk to never go out the loop is real */
    initialize_string(temp);
    initialize_string(saisie);

    if (TRUE == bAsk)
      fprintf(stdout, "Saisir un nombre entier (compris entre %hd et %hd) : ", hd_min, hd_max);

    short int noErr = saisie_chaine_de_caracteres(FALSE);
    if ( noErr != 0 )
      fprintf(stdout, "Problème avec la valeur saisie \n");

    /* strlcpy( destination, source, sizeof(source) ) */
    strlcpy(saisie, g_buf, sizeof(g_buf));
    calcule_signe(saisie);

    if ( !(isdigit(saisie[0])) && (saisie[0] != '-') )
      bString_Is_OK = FALSE;

    short int compteur = 1;
    while ((saisie[compteur] != '\0') && (compteur < MAX_BUFFER_SIZE))
    {
      if ( !(isdigit(saisie[compteur])) )
         bString_Is_OK = FALSE;
#ifdef DEBUG
      fprintf(stderr, "saisie[%hd] == %c \n", compteur, saisie[compteur]);
#endif
      compteur++;
    }
    /* general case : sscanf (saisie, "%[-+0-9.,]s", temp); */
    if ( TRUE == bString_Is_OK )
      sscanf (saisie, "%[-+0-9^.,a-z]s", temp);
    else
      bString_Is_OK = FALSE;

  } while ( (( strtol(temp, '\0', 10) < hd_min ) || ( strtol(temp, '\0', 10) > hd_max)) || (bString_Is_OK == FALSE) );
  return (short int)strtol(temp, (char **)NULL, 10);
}


long long int saisie_nombre_entier_long(BOOL bAsk, long long int Ld_min, long long int Ld_max)
{
  if (Ld_min > Ld_max)
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
    fflush(stdin);
    initialize_string(temp);
    initialize_string(saisie);

    if (TRUE == bAsk)
        fprintf(stdout, "Saisir un nombre entier (compris entre %lld et %lld) : ", Ld_min, Ld_max);

    short int noErr = saisie_chaine_de_caracteres(FALSE);
    if ( noErr != 0 )
      fprintf(stdout, "Problème avec la valeur saisie \n");

    strlcpy(saisie, g_buf, sizeof(g_buf));
    calcule_signe(saisie);

    if ( !(isdigit(saisie[0])) && (saisie[0] != '-') )
      bString_Is_OK = FALSE;

    short int indice = 1;
    while ((saisie[indice] != '\0') && (indice < MAX_BUFFER_SIZE))
    {
      if ( !(isdigit(saisie[indice])) )
         bString_Is_OK = FALSE;
#ifdef DEBUG
      fprintf(stderr, "saisie[%hd] == %c \n", indice, saisie[indice]);
#endif
      indice++;
    }

    if ( TRUE == bString_Is_OK )
      sscanf (saisie, "%[-+0-9^.,a-zA-Z]s", temp);
    else
      bString_Is_OK = FALSE;

  } while ( (( strtoll(temp, '\0', 10) < Ld_min ) || ( strtoll(temp, '\0', 10) > Ld_max)) || (bString_Is_OK == FALSE) );

  return (long int)strtoll(temp, (char **)NULL, 10);
}

