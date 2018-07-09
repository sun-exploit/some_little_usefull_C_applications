/*
 * Header file saisie_chaine.h from saisie project
 * Author : Eric Bachard / dimanche 27 mars 2016, 13:24:52 (UTC+0200)
 * This document is under GPL v2 License. See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __SAISIE_CHAINE__H__
#define __SAISIE_CHAINE__H__

#include "boolean.h"

#define MAX_BUFFER_SIZE     512

char g_buf[MAX_BUFFER_SIZE];

void lit_entree(char *);

void clean_string(const char *, FILE *);

short int saisie_chaine_de_caracteres(BOOL);

void initialize_string(char *);

BOOL bString_Is_OK;

#endif /* __SAISIE_CHAINE__H__ */

