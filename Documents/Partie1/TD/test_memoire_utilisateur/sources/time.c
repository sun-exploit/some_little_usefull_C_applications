/*                                                   *
 * Auteur : Eric Bachard  version originale : 2004   *
 * Ce document est sous Licence GPL v2               *
 * voir : http://www.gnu.org/licenses/gpl-2.0.html   */

/* ---------initialize_time------------ */

#include <stdlib.h>
#include <time.h>
#include "initialize_time.h"

void initialize_time(void)
{
    time_t t1;
    (void)time(&t1);
    srand((long)t1); /* random initialization */
}

/* --------------------------------- */
