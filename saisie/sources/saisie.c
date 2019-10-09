/* saisie.c from saisie_project
 * Author : Eric Bachard Mai 2005 13:59:01 CEST
 * This document is under GPL v2 License. See : http://www.gnu.org/licenses/gpl-2.0.html */

#define _GNU_SOURCE
#include "saisie.h"
#include "utils.h"

#ifndef _ISOC99_SOURCE
#define _ISOC99_SOURCE
#endif

static bool bString_Is_OK = false;

/* ---------efface_ecran------------ */

static void clean_string(const char *g_buf, FILE *aStream)
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

static void lit_entree (char *aString)
{
  short int anErr = (fgets(aString, sizeof(g_buf), stdin) == NULL);
  if ( anErr != 0 )
    fprintf(stdout, "Probleme avec la valeur saisie \n");

  clean_string(aString, stdin);
}


static void initialize_string (char * aString)
{
  /* to avoid security issue, 
     using -fno-builtin-memset gcc option at build time
   */
  memset(aString, '\0', MAX_BUFFER_SIZE);
}

short int saisie_chaine_de_caracteres()
{
  initialize_string(g_buf);
  char * entree = g_buf;
  lit_entree (entree);

  return EXIT_SUCCESS;
}


void calcule_signe( char * saisie)
{

  bool b_nombre_avec_signe = ( (saisie[0] == '-') || (saisie[0] == '+' ));

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

short int saisie_nombre_entier_court(short int hd_min, short int hd_max)
{
  if (hd_min > hd_max)
  {
    fprintf(stderr, "Probleme avec les limites");
    exit(EXIT_FAILURE);
  }
  bString_Is_OK = true;
  char saisie[MAX_BUFFER_SIZE];
  char temp[MAX_BUFFER_SIZE];

  do
  {
    bString_Is_OK = true;
    fflush(stdin);
    /* we must empty temp at every iteration else, the risk to never go out the loop is real */
    initialize_string(temp);
    initialize_string(saisie);

    short int noErr = saisie_chaine_de_caracteres();

    if ( noErr != 0 )
      fprintf(stdout, "Probleme avec la valeur saisie \n");

    /* strlcpy( destination, source, sizeof(source) ) */
#ifndef Darwin
    strlcpy(saisie, g_buf, sizeof(g_buf));
#else
    /* FIXME : test on Mac OS  machines */
    strlcpy(saisie, g_buf, sizeof(g_buf));
#endif

    calcule_signe(saisie);

    if ( !(isdigit(saisie[0])) && (saisie[0] != '-') )
      bString_Is_OK = false;

    short int compteur = 1;
    while ((saisie[compteur] != '\0') && (compteur < MAX_BUFFER_SIZE))
    {
      if ( !(isdigit(saisie[compteur])) )
         bString_Is_OK = false;
#ifdef DEBUG
      fprintf(stderr, "saisie[%hd] == %c \n", compteur, saisie[compteur]);
#endif
      compteur++;
    }
    /* general case : sscanf (saisie, "%[-+0-9.,]s", temp); */
    if ( true == bString_Is_OK )
      sscanf (saisie, "%[-+0-9^.,a-z]s", temp);
    else
      bString_Is_OK = false;

  } while ( (( strtol(temp, (char **)NULL, 10) < hd_min ) || ( strtol(temp, (char **)NULL, 10) > hd_max)) || (bString_Is_OK == false) );
  return (short int)strtol(temp, (char **)NULL, 10);
}


long long int saisie_nombre_entier_long(long long int Ld_min, long long int Ld_max)
{
  if (Ld_min > Ld_max)
  {
    fprintf(stderr, "Probleme avec les limites");
    exit(EXIT_FAILURE);
  }
  bString_Is_OK = true;
  char saisie[MAX_BUFFER_SIZE];
  char temp[MAX_BUFFER_SIZE];

  do
  {
    bString_Is_OK = true;
    fflush(stdin);
    initialize_string(temp);
    initialize_string(saisie);

    short int noErr = saisie_chaine_de_caracteres();
    if ( noErr != 0 )
      fprintf(stdout, "Probleme avec la valeur saisie \n");

    strlcpy(saisie, g_buf, sizeof(g_buf));
    calcule_signe(saisie);

    if ( !(isdigit(saisie[0])) && (saisie[0] != '-') )
      bString_Is_OK = false;

    short int indice = 1;
    while ((saisie[indice] != '\0') && (indice < MAX_BUFFER_SIZE))
    {
      if ( !(isdigit(saisie[indice])) )
         bString_Is_OK = false;
#ifdef DEBUG
      fprintf(stderr, "saisie[%hd] == %c \n", indice, saisie[indice]);
#endif
      indice++;
    }

    if ( true == bString_Is_OK )
      sscanf (saisie, "%[-+0-9^.,a-zA-Z]s", temp);
    else
      bString_Is_OK = false;

  } while ( (( strtoll(temp, (char **)NULL, 10) < Ld_min ) || ( strtoll(temp, (char **)NULL, 10) > Ld_max)) || (bString_Is_OK == false) );

  return (long int)strtoll(temp, (char **)NULL, 10);
}

long double saisie_nombre_reel(long double Lfmin, long double Lfmax)
{
  if (Lfmin > Lfmax)
  {
    fprintf(stderr, "Probleme avec les limites");
    exit(EXIT_FAILURE);
  }
  bString_Is_OK = true;
  char saisie[MAX_BUFFER_SIZE];
  char temp[MAX_BUFFER_SIZE];

  do
  {
    bString_Is_OK = true;
    initialize_string(temp);
    initialize_string(saisie);

    short int noErr = saisie_chaine_de_caracteres();
    if ( noErr != 0 )
      fprintf(stdout, "Probleme avec la valeur saisie \n");

    strlcpy(saisie, g_buf, sizeof(g_buf));
    calcule_signe(saisie);
    short int dots_count = 0;

    if ( !(isdigit(saisie[0])) && (saisie[0] != '-') && (saisie[0] != '.') )
      bString_Is_OK = false;

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
         bString_Is_OK = false;

      indice2++;
    }

    if ( (dots_count > 1) )
      bString_Is_OK = false;

    if ( true == bString_Is_OK ) /* If only digits, count = 0 (not digits) + 1 character ending the string */
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
  } while ( (( strtod(temp, (char **)NULL) < Lfmin ) || (strtod(temp, (char **)NULL) > Lfmax)) || (bString_Is_OK == false) );

  return strtod(temp, (char **)NULL);
}

// Work in progress

long double saisie_nombre_scientifique(long double Lfmin, long double Lfmax)
{
  if (Lfmin > Lfmax)
  {
    fprintf(stderr, "Probleme avec les limites");
    exit(EXIT_FAILURE);
  }

  bString_Is_OK = true;
  char saisie[MAX_BUFFER_SIZE];
  char temp[MAX_BUFFER_SIZE];

  do
  {
    bString_Is_OK = true;
    initialize_string(temp);
    initialize_string(saisie);

    short int noErr = saisie_chaine_de_caracteres();
    if ( noErr != 0 )
      fprintf(stdout, "Probleme avec la valeur saisie \n");

    /* strlcpy(destination, source, sizeof(source)) */
    strlcpy(saisie, g_buf, sizeof(g_buf));
    calcule_signe( saisie);

    if ( !(isdigit(saisie[0])) && (saisie[0] != '-') && (saisie[0] != '.') )
      bString_Is_OK = false;

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
         bString_Is_OK = false;

      indice3++;
    }

    if (dots_count > 1 )
      bString_Is_OK = false;

    if ( true == bString_Is_OK ) /* If only digits, count = 0 (not digits) + 1 character ending the string */
    {
      /* IMPORTANT : the character type order seems to count  when checking the string !*/
      short int anErr = sscanf (saisie, "%[-,+,0-9,E,e,.]LLg", temp);
//      short int anErr = sscanf (saisie, "%[-,+,0-9,E,e,.]s", temp);
      (void)anErr; // makes the compiler happy
    }

  } while ( (( strtod(temp, (char **)NULL) < Lfmin ) || (strtod(temp, (char **)NULL)> Lfmax)) || (bString_Is_OK == false));

  return strtod(temp, (char **)NULL);
}

