/* Auteur:  Eric Bachard  / 17 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __HASHAGE_H
#define __HASHAGE_H

#include <stdbool.h>

typedef struct item {

  /* on stocke une chaîne de caractère */
  char key[20];
  /*On suppose la valeur contenue est entiere*/
  int value;
  /* pointeur sur l'element suivant */
  struct item *next;
} HASH;

int getHashValue (HASH *, char []);

HASH * initHash (void);

void deleteHashKey (HASH * , char [] );
void setHashValue  (HASH *, char [], int);
void destroyHash   (HASH *);

void display(void);

bool b_IsHashKey (HASH *, char [] );

#endif /* __HASHAGE_H */


