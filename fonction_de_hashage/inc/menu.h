/* Auteur:  Eric Bachard  / 17 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */


#ifndef __MENU_H
#define __MENU_H

#include "hashage.h"

// TODO : improve this awfull menu

/* Directly using ascii value for the entered numbers. This way, menu entries won't depend on the content */
#define MENU_ENTRY_1                         49
#define MENU_ENTRY_2                         50
#define MENU_ENTRY_3                         51
#define MENU_ENTRY_4                         52
#define MENU_ENTRY_5                         53
#define MENU_ENTRY_6                         54
#define MENU_ENTRY_7                         55
#define MENU_ENTRY_8                         56
#define MENU_ENTRY_9                         57

/* what is currently proposed (some other choices could be proposed in the future) */

#define HASH_AFFECT_VALUE_FOR_GIVEN_KEY      MENU_ENTRY_1
#define HASH_RETURN_VALUE_FOR_GIVEN_KEY      MENU_ENTRY_2
#define HASH_SEARCH_A_KEY                    MENU_ENTRY_3
#define HASH_DELETE_ENTRY_FROM_GIVEN_KEY     MENU_ENTRY_4
#define HASH_DELETE_TABLE                    MENU_ENTRY_5
#define HASH_TABLE_QUIT                      MENU_ENTRY_6
#define HASH_TABLE_SIZE                      MENU_ENTRY_7
#define HASH_TABLE_DISPLAY                   MENU_ENTRY_8


// TODO : add : table size, max value and so on

void menu (bool);

#endif /* __MENU_H */

