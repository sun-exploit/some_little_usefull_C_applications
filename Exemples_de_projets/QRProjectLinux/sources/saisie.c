/* saisie.c from saisie_project
 * Author : Eric Bachard Mai 2005 13:59:01 CEST
 * This document is under GPL v2 License
 * This document is under GPL v2 License. See : http://www.gnu.org/licenses/gpl-2.0.html */

#define _GNU_SOURCE
#include "saisie.h"

/* ---------efface_ecran------------ */

void efface_ecran(void)
{
    FILE * stdout = popen("clear", "w");
    int anErr = pclose( stdout) ;

    if (anErr != 0 ) 
       fprintf(stderr,"problem with clear\n");
}


/* strlcpy based on OpenBSDs strlcpy */

/* Apple implented its own strlcpy, and a clash occurs if not protected */
#ifndef Darwin

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
size_t
strlcpy(char *dst, const char *src, size_t siz)
{
        char *d = dst;
        const char *s = src;
        size_t n = siz;

        /* Copy as many bytes as will fit */
        if (n != 0 && --n != 0) {
                do {
                        if ((*d++ = *s++) == 0)
                                break;
                } while (--n != 0);
        }

        /* Not enough room in dst, add NUL and traverse rest of src */
        if (n == 0) {
                if (siz != 0)
                        *d = '\0';                /* NUL-terminate dst */
                while (*s++)
                        ;
        }

        return(s - src - 1);        /* count does not include NUL */
}

#endif


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

short int saisie_chaine_de_caracteres()
{
  initialize_string(g_buf);
  char * entree = g_buf;
  lit_entree (entree);

#ifdef DEBUG
  fprintf (stdout, "Vous avez saisi :  %s\n", entree);
#endif

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

short int saisie_nombre_entier_court(short int hd_min, short int hd_max)
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

    short int noErr = saisie_chaine_de_caracteres();

    if ( noErr != 0 )
      fprintf(stdout, "Problème avec la valeur saisie \n");

    /* strlcpy( destination, source, sizeof(source) ) */
#ifndef Darwin
    strlcpy(saisie, g_buf, sizeof(g_buf));
#else
    /* FIXME : test on Mac OS  machines */
    strlcpy(saisie, g_buf, sizeof(g_buf));
#endif

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

  } while ( (( strtol(temp, (char **)NULL, 10) < hd_min ) || ( strtol(temp, (char **)NULL, 10) > hd_max)) || (bString_Is_OK == FALSE) );
  return (short int)strtol(temp, (char **)NULL, 10);
}


long long int saisie_nombre_entier_long(long long int Ld_min, long long int Ld_max)
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

    short int noErr = saisie_chaine_de_caracteres();
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

  } while ( (( strtoll(temp, (char **)NULL, 10) < Ld_min ) || ( strtoll(temp, (char **)NULL, 10) > Ld_max)) || (bString_Is_OK == FALSE) );

  return (long int)strtoll(temp, (char **)NULL, 10);
}



long double saisie_nombre_reel(long double Lfmin, long double Lfmax)
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

    short int noErr = saisie_chaine_de_caracteres();
    if ( noErr != 0 )
      fprintf(stdout, "Problème avec la valeur saisie \n");

    strlcpy(saisie, g_buf, sizeof(g_buf));
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

long double saisie_nombre_scientifique(long double Lfmin, long double Lfmax)
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

    short int noErr = saisie_chaine_de_caracteres();
    if ( noErr != 0 )
      fprintf(stdout, "Problème avec la valeur saisie \n");

    /* strlcpy(destination, source, sizeof(source)) */
    strlcpy(saisie, g_buf, sizeof(g_buf));
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

