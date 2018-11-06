#ifndef __MAIN_H
#define __MAIN_H

/**************************
 * current menu entries   *
 **************************/

#define MENU_ITEM_1       1
#define MENU_ITEM_2       2
#define MENU_ITEM_3       3
#define MENU_ITEM_4       4
/* currently unused => in the future */

#define MENU_ITEM_5       5
#define MENU_ITEM_6       6
/* end new menu entries below ...    */


/**************************
 * available translations *
 **************************/

#define ENGLISH_TO_FRENCH       MENU_ITEM_1
#define FRENCH_TO_ENGLISH       MENU_ITEM_2


/* in the future */
#define SPANISH_TO_FRENCH       MENU_ITEM_5
#define FRENCH_TO_SPANISH       MENU_ITEM_6

/* different role */
#define ADD_NEW_WORDS           MENU_ITEM_3

/* finaly quit ... */
#define PROGRAM_QUIT            MENU_ITEM_4


/* various fonctions */
void menu(void);

int choix;
short int VocabulaireFrancaisAnglais(void);
short int AjoutMotsVocabulaire(void);
short int  VocabulaireAnglaisFrancais(void);

typedef enum Boolean
{
 FALSE,
 TRUE
} BOOL;

#endif /* __MAIN_H */
