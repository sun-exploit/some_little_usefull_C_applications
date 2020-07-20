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

#define DEBUG_LEVEL 3

/* singleton */
extern HASH * my_hash_table;

static void print_refcount(void)
{
#if (DEBUG_LEVEL > 1)
    fprintf(stdout, "refcount = %d \n", refcount);
#endif
}


HASH * initHash (void)
{
    // Declaration d'un pointeur vers une structure de type HASH
    // ATTENTION : le pointeur est initialisé a NULL dans main, pas ici !

    // malloc => heap allocation
    my_hash_table = (HASH *)malloc(sizeof(HASH));

    //refcount++;
    print_refcount();
    if(my_hash_table == NULL)
        exit(EXIT_FAILURE);

    // On initialise le pointeur next du premier element a NULL
    my_hash_table->next = NULL;

    // par défaut, le premier élément créé est aussi le dernier
    my_hash_table->b_isLast = true;

    // On retourne le pointeur vers le premier element
    return my_hash_table;
}


void eraseTable (HASH * p_hash_table)
{
    HASH * my_hash_table_next;

    my_hash_table_next = p_hash_table->next;

    /* delete the element  H is pointing to */
    if ((p_hash_table != NULL ) && (refcount > 1))
    {
      free(p_hash_table);
      refcount--;
    }

    // On rappelle la fonction avec pour argument le pointeur vers l'element suivant
    if(my_hash_table_next != NULL)
        eraseTable (my_hash_table_next);

    print_refcount();
}


void push (HASH * p_hash_table, char key[20], int value)
{
    unsigned int i;

    // on parcourt la pile, jusqu'au dernier élément
    while((p_hash_table->next != NULL))
    {
        // si on ajoute un élément, celui-ci n'est pas le dernier
        p_hash_table->b_isLast = false;

        // le suivant n'est pas null
        p_hash_table = p_hash_table->next;

        // cet élément est le dernier
        p_hash_table->b_isLast = true;
    }

    /* attention piège : strcmp compare 2 chaines de caractères et renvoie 0 ssi les 2 chaines sont identiques */

    if( strcmp (p_hash_table->key, key) == 0 )
    {
        // la clé existe (mais on ne sait pas où on est dans la pile)
        // on écrase la valeur qui existe.
        // Pas d'augmentation de refcount
        // car le nombre d'éléments de la pile n'augmente pas
        p_hash_table->value = value;
    }
    else
    {
        // On n'a pas trouvé d'élément ayant la même clé
        // on ajoute un élément dans la pile
        // => refcount++ dans ce cas

        p_hash_table->next = (HASH *)malloc(sizeof(HASH));

        if(p_hash_table->next == NULL)
            exit(EXIT_FAILURE);

        p_hash_table = p_hash_table->next;

        for (i=0; i<=strlen(key); i++)
        {
            p_hash_table->key[i]=key[i];
        }

        refcount++;

        p_hash_table->value = value;
        p_hash_table->next = NULL;
    }
}


int getHashValue (HASH * p_hash_table, char key[20])
{
    while(strcmp( p_hash_table->key , key) != 0)
    {
        p_hash_table = p_hash_table->next;
    }

    return p_hash_table->value;
}

bool b_IsHashKey (HASH * p_hash_table, char key[20])
{
    bool toReturn = false;

    while ((p_hash_table != NULL) && (strcmp(p_hash_table->key, key) != 0))
    {
        p_hash_table = p_hash_table->next;
    }

    if ((p_hash_table != NULL) && (strcmp(p_hash_table->key, key) == 0))
        return true;
    else
      toReturn =false;

    return toReturn;
}

void pop (HASH * p_hash_table, char key[20] )
{
    HASH *hash_to_delete;

    while (strcmp (p_hash_table->next->key, key ) != 0)
    {
        p_hash_table = p_hash_table->next;
    }

    /*
        Le pointeur hash_to_delete va pointer vers l'element a supprimer. Il ne faut pas oublier
        de lier l'element precedent de N avec l'element suivant de N pour ne pas casser la liste chainée.
    */

    hash_to_delete = p_hash_table->next;

    if (p_hash_table->next->next != NULL)
        p_hash_table->next = p_hash_table->next->next;

    if (( hash_to_delete != NULL ) && (refcount > 0))
        free(hash_to_delete);
}

