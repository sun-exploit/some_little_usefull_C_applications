/* Auteur:  Eric Bachard  / 17 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "saisie.h"
#include "utils.h"


// global, for visibility reason  FIXME : hide me !
extern HASH * my_hash_table;// = NULL;

static char key[20];
static short int val = 0;

static void saisie_cle(void)
{
    saisie_chaine_de_caracteres();
    strlcpy(key, g_buf, sizeof(g_buf)); /* destination, source, taille chaine */
}


static void saisie_valeur(void)
{
    val = saisie_nombre_entier_court(SHRT_MIN, SHRT_MAX);
    push(my_hash_table, key, val);
}


void menu(bool b_Quit)
{
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    //char choice = 'a';
    short int choice = 0;

    while (false == b_Quit)
    {
        display();
        choice = saisie_nombre_entier_court(MENU_ENTRY_1, MENU_ENTRY_8);

        switch (choice)
        {
            case HASH_AFFECT_VALUE_FOR_GIVEN_KEY:
            {
                fprintf(stdout, "Entrez la clé de l'élément à modifier/crée (maxi 18 caractères)\n");
                saisie_cle();

                fprintf(stdout, "Entrer un nombre compris entre %hd et %hd, associé à la clé : \n", SHRT_MIN, SHRT_MAX);
                saisie_valeur();

                break;
            }

            case HASH_RETURN_VALUE_FOR_GIVEN_KEY:
            {
                fprintf(stdout, "Entrez la clé de l'élément\n");
                saisie_cle();

                if( true == b_IsHashKey(my_hash_table,key))
                    fprintf(stdout, "La valeur de l'élément est %d",getHashValue(my_hash_table,key));
                else
                    fprintf(stdout, "Aucun élément de la table ne contient cette clé\n");

            break;
            }

            case HASH_SEARCH_A_KEY:
            {
                fprintf(stdout, "Entrez la clé de l'élément\n");
                saisie_cle();

                fprintf(stderr, "clé testée : %s \n", key );

                if (b_IsHashKey(my_hash_table,key) == true)
                    fprintf(stdout, "Cette clé existe dans la table\n");
                else
                    fprintf(stdout, "Cette clé n'existe pas\n");

            break;
            }

            case HASH_DELETE_ENTRY_FROM_GIVEN_KEY:
            {
                fprintf(stdout, "Entrez la clé de l'élément\n");
                saisie_cle();

                if (false == b_IsHashKey(my_hash_table,key))
                    fprintf(stdout, "Cette clé n'existe pas dans la table !\n");
                else
                    deleteKey(my_hash_table,key);
            }
            break;

            case HASH_DELETE_TABLE:
            {
                if (my_hash_table != NULL)
                    eraseTable();
            }
            break;

            case HASH_TABLE_QUIT:
            {
                b_Quit = true;

                // cleanup
                if(my_hash_table != NULL)
                    eraseTable();
            }
            break;

            default:
                fprintf(stdout, "Mauvaise saisie\n");

            break;
        }
    }
}

