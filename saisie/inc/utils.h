/* Header file saisie.h from saisie project
 * Author : Eric Bachard / dimanche 27 mars 2016, 13:24:52 (UTC+0200)
 * This document is under GPL v2 License. See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __UTILS__H__
#define __UTILS__H__

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* strings */

void efface_ecran(void);

#ifndef Darwin
size_t strlcpy(char *, const char *, size_t);
#endif

#endif /* __UTTILS__H__ */
