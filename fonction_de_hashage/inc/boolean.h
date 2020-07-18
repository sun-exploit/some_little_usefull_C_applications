/* Auteur:  Eric Bachard  / 17 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __BOOLEAN_H
#define __BOOLEAN_H

typedef enum Boolean {
  FALSE,
  TRUE
} BOOL ;

BOOL b_Quit;
void menu ( BOOL ); 

#endif /* __BOOLEAN_H */


