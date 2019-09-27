/* Header file saisie.h from saisie project
 * Author : Eric Bachard / dimanche 27 mars 2016, 13:24:52 (UTC+0200)
 * This document is under GPL v2 License. See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __SAISIE__H__
#define __SAISIE__H__

#define MAX_BUFFER_SIZE     512

#define ENTIER_COURT_MIN          SHRT_MIN >> 1
#define ENTIER_COURT_MAX          SHRT_MAX >> 1
#define ENTIER_LONG_MIN          LLONG_MIN >> 1
#define ENTIER_LONG_MAX         ULLONG_MAX >> 1

#define REEL_MIN                 1.7e-300
#define REEL_MAX                  1.7e300

#define inconnu                nan("0/0")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

/* strings */

char g_buf[MAX_BUFFER_SIZE];

void lit_entree(char *);

void clean_string(const char *, FILE *);

short int saisie_chaine_de_caracteres(void);

void initialize_string(char *);

bool bString_Is_OK;

#ifndef Darwin
size_t strlcpy(char *dst, const char *src, size_t siz);
#endif

/* utils */

void efface_ecran(void);


/* numbers */

/**************************************************************************************
 *  SYNOPSIS : type function_name(                                                    *
 *                                 type  minimal value                                *
 *                                 type  maximal value                                *
 *                               )                                                    *
 *  every function returns the value, else 0 (or 0.0) if nan                          *
 **************************************************************************************/

short int saisie_nombre_entier_court(short int, short int);

long long int saisie_nombre_entier_long(long long int, long long int);

long double saisie_nombre_reel(long double, long double);

long double saisie_nombre_scientifique(long double, long double);

void calcule_signe(char *);

#endif /* __SAISIE__H__ */
