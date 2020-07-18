/* Auteur:  Eric Bachard  / 17 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashage.h"

/*
    HASH          :    LIFO type
    initHash      :    init
    setHashValue  :    push
    getHashValue  :    get
    deleteHashKey :    pop
    destroyHash   :    delete
*/

// ask yourself why C++ wins ... 
static int refcount = 0;

/* singleton */
extern HASH * my_hash_table;


HASH *initHash (void)
{
#ifdef DEBUG
  fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif

    // Declaration d'un pointeur vers une structure de type HASH
    // ATTENTION : le pointeur est initialisé a NULL dans main, pas ici !

    /* malloc => heap allocation */
    my_hash_table = (HASH *)malloc(sizeof(HASH));

    refcount++;

#ifdef DEBUG
    fprintf(stderr, "Incrémentation de refcount. Nouvelle valeur =  %d \n", refcount );
#endif

    if(my_hash_table == NULL)
        exit(EXIT_FAILURE);

    /* On initialise le pointeur next du premier element a NULL */
    my_hash_table->next = NULL;

    /* On retourne le pointeur vers le premier element */
    return my_hash_table;
}



void destroyHash (HASH * my_hash_table)
{
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    HASH * my_hash_table_next;

    my_hash_table_next = my_hash_table->next;

    /* delete the element  H is pointing to */
    if ((my_hash_table != NULL ) && (refcount > 0))
    {
      free(my_hash_table);
      refcount--;
#ifdef DEBUG
      fprintf(stderr, "Décrémentation de refcount. Nouvelle valeur =  %d \n", refcount );
#endif
    }

    // On rappelle la fonction avec pour argument le pointeur vers l'element suivant

    if(my_hash_table_next != NULL)
        destroyHash (my_hash_table_next);
}


void setHashValue (HASH * my_hash_table, char key[20], int value)
{
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    int i;

    /*
        Tant que l'on est pas arrive au bout de la table de hashage
        et que la cle entree est differente de la cle des elements
        de la table de hashage, on passe a l'element suivant
    */


    while((my_hash_table->next != NULL) && (strcmp (my_hash_table->key , key) != 0))
    {
        my_hash_table = my_hash_table->next;
    }

    /* attention piège : strcmp compare 2 chaines de caractères et renvoie 0 ssi les 2 chaines sont identiques */

    if( strcmp (my_hash_table->key, key) == 0 )
        my_hash_table->value = value;
    else
    {
        my_hash_table->next = (HASH *)malloc(sizeof(HASH));

        if(my_hash_table->next == NULL)
            exit(EXIT_FAILURE);

        my_hash_table = my_hash_table->next;

        for ( i=0; i<=strlen(key); i=i+1 )
        {
            my_hash_table->key[i]=key[i];
        }

        my_hash_table->value = value;
        my_hash_table->next = NULL;
    }
}


int getHashValue (HASH * my_hash_table, char key[20])
{

#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif

    while(strcmp( my_hash_table->key , key) != 0)
    {
        my_hash_table = my_hash_table->next;
    }

    return my_hash_table->value;
}

bool b_IsHashKey (HASH * my_hash_table, char key[20])
{
    bool toReturn = false;

    while ( (my_hash_table != NULL) && ( strcmp ( my_hash_table->key , key ) != 0 ) )
    {
        my_hash_table = my_hash_table->next;
    }

    if ( (my_hash_table != NULL) && (strcmp(my_hash_table->key , key) == 0 ) )
        return true;
    else
      toReturn =false;

    return toReturn;
}

void deleteHashKey (HASH * my_hash_table, char key[20] )
{
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    HASH *hash_to_delete;

    while (strcmp ( my_hash_table->next->key , key ) != 0  )
    {
        my_hash_table = my_hash_table->next;
    }

    /*
        Le pointeur hash_to_delete va pointer vers l'element a supprimer.
        Il ne faut pas oublier de lier l'element precedent de N avec l'element suivant de N 
        pour ne pas casser la liste chainée.
    */

    hash_to_delete = my_hash_table->next;

    if (my_hash_table->next->next != NULL)
        my_hash_table->next = my_hash_table->next->next;

    if (( hash_to_delete != NULL ) && ( refcount > 0 ))
        free(hash_to_delete);
}

