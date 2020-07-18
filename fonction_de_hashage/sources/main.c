/* Auteur:  Eric Bachard  / 17 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashage.h"
#include "menu.h"


HASH *my_hash_table = NULL;

int main (void)
{
#ifdef DEBUG
  fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
  my_hash_table = initHash();
  menu(false);
  return EXIT_SUCCESS;
}
