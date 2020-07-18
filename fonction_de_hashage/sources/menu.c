/* Auteur:  Eric Bachard  / 17 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdbool.h>
#include "menu.h"

// FIXME : awfull implementation. test inside switch is bad design :-/


void menu(bool b_Quit)
{
#ifdef DEBUG
  fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
  char choice = 'a';
  char key[20];
  int val;
  extern HASH * my_hash_table;// = NULL;

  while (false == b_Quit)
  {
    display();

    // TODO : use saisie_nombre_entier_court()
    scanf ("%c", &choice);

    while (getchar() != '\n');

    switch (choice)
    {
      case HASH_AFFECT_VALUE_FOR_GIVEN_KEY:
      {
        fprintf(stdout, "Entrez la clé de l'élément à modifier/crée\n");

        // TODO : utiliser saisie_chaine_de_caracteres
        scanf("%s",key);

        while (getchar() != '\n');
#ifdef DEBUG
        fprintf(stderr, "key vaut : %s \n", key );
#endif
        fprintf(stdout, "Entrez la valeur de l'élément\n");


        // TODO : utiliser saisie_nombre_reel()
        scanf("%d",&val);
        while (getchar() != '\n');

        push( my_hash_table, key, val);

        break;
      }

      case HASH_RETURN_VALUE_FOR_GIVEN_KEY:
      {
        fprintf(stdout, "Entrez la clé de l'élément\n");

        // TODO : utiliser saisie_chaine_de_caracteres
        scanf("%s",key);
        while (getchar() != '\n');

        if( true == b_IsHashKey(my_hash_table,key))
          fprintf(stdout, "La valeur de l'élément est %d",getHashValue(my_hash_table,key));
        else
          fprintf(stdout, "Aucun élément de la table ne contient cette clé\n");

        break;
      }

      case HASH_SEARCH_A_KEY:
      {
        fprintf(stdout, "Entrez la clé de l'élément\n");

        // TODO : utiliser saisie_chaine_de_caracteres
        scanf("%s",key);
#ifdef DEBUG
        fprintf(stderr, "key vaut : %s \n", key );
#endif
        while (getchar() != '\n');

        if (b_IsHashKey(my_hash_table,key) == 1)
          fprintf(stdout, "L'élément existe\n");
        else
          fprintf(stdout, "L'élément n'existe pas\n");

        break;
      }

      case HASH_DELETE_ENTRY_FROM_GIVEN_KEY:
      {
        fprintf(stdout, "Entrez la clé de l'élément\n");

        // TODO : utiliser saisie_chaine_de_caracteres
        scanf("%s",key);
        while (getchar() != '\n');

#ifdef DEBUG
        fprintf(stderr, "key vaut : %s \n", key );
#endif
        if (false == b_IsHashKey(my_hash_table,key))
          fprintf(stdout, "L'élément n'existe pas!\n");
        else
          pop(my_hash_table,key);

        break;
      }

      case HASH_DELETE_TABLE:
      {
        if (my_hash_table != NULL)
            eraseTable(my_hash_table);

        break;
      }
      case HASH_TABLE_QUIT:
      {
#ifdef DEBUG
        fprintf(stderr, "Sortie du programme. key vaut : %s \n", key );
#endif
        b_Quit = true;

        if(my_hash_table != NULL)
          eraseTable(my_hash_table);

        break;
      }
        default:
          fprintf(stdout, "Mauvaise saisie\n");
    }
  }
}

