/* header file saisie_nombre.h
 * Interface purpose is to enter a number, with or without decimal point.
 * Author: Eric Bachard / 26 mars 2016
 * This document is under GPL v2 License. See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __SAISIE_NOMBRE__H__
#define __SAISIE_NOMBRE__H__

#include <boolean.h>
#include <limits.h>

#define ENTIER_COURT_MIN          SHRT_MIN
#define ENTIER_COURT_MAX          SHRT_MAX
#define ENTIER_LONG_MIN          LLONG_MIN
#define ENTIER_LONG_MAX         ULLONG_MAX

#define REEL_MIN                 1.7e-300
#define REEL_MAX                  1.7e300

#define inconnu                nan("0/0")

/**************************************************************************************
 *  SYNOPSIS : type function_name(                                                    *
 *                                 BOOL b_ask_to_enter_something_?                    *
 *                                 type  minimal value                                *
 *                                 type  maximal value                                *
 *                               )                                                    *
 *  every function returns the value, else 0 (or 0.0) if nan                          *
 **************************************************************************************/

short int saisie_nombre_entier_court(BOOL, short int, short int);

long long int saisie_nombre_entier_long(BOOL, long long int, long long int);

long double saisie_nombre_reel(BOOL, long double, long double);

long double saisie_nombre_scientifique(BOOL, long double, long double);

void calcule_signe(char *);

#endif /* __SAISIE_NOMBRE__H__ */
