/*                                                   *
 * Auteur : Eric Bachard  version originale : 2004   *
 * Ce document est sous Licence GPL v2               *
 * voir : http://www.gnu.org/licenses/gpl-2.0.html   */

/* ---------initialize_rand------------ */

#include <stdlib.h>
#include <time.h>
#include "initialize_rand.h"

void initialize_rand(void)
{
  time_t t1;
  (void)time(&t1);
  srand((long)t1); /* random initialization */
}

/* --------------------------------- */
