/* boolean.h header file. This program allows to create a boolean variable,
 * as a structure type, allowing only TRUE or FALSE cases.
 * Author: Eric Bachard / 3 novembre 2010
 * This document is under GPL v2 license. See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __BOOLEAN_H
#define __BOOLEAN_H

/* definition of a boolean
 * usage :  BOOL bAnswerToQuestion = TRUE or FALSE;
 */
typedef enum Bool
{
  FALSE = 0,
  TRUE = 1
} BOOL;

#endif /* __BOOLEAN_H */
