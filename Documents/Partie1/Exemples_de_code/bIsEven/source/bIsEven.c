/* bIsEven.c programme servant à etudier la parité d'un nombre
 * Auteur : Eric Bachard
 * Ce document est sous Licence GPL v2  Octobre 2014
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bIsEven.h"

#define PAIR   "pair"
#define IMPAIR "impair"
//char * even = "pair";
//char * odd = "impair";
char * result = "\0";

BOOL bIsOdd ( int value )
{
  return ( value % 2 );
}

void display_result( int aValue )
{
  fprintf( stdout, " %d est : %s \n", aValue, result );
}

void test_parity( int aValue )
{
  result = PAIR;
  if ( bIsOdd (aValue ))
    result = IMPAIR;

  display_result( aValue );
}

