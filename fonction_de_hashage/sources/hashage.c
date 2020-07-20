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
    deleteHashKey :    deleteKey
    pop           :    remove one element from the top
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


void eraseTable()
{
    HASH * last = my_hash_table;

    while ((last->next != NULL) /*&& (refcount > 0)*/)
    {
        last = last->next;
        pop(last);
    }
}


void push (HASH * p_hash_table, char key[20], int value)
{
    unsigned int i;

    /* attention piège : strcmp compare 2 chaines de caractères et renvoie 0 ssi les 2 chaines sont identiques */

    while((p_hash_table->next != NULL) && (strcmp (p_hash_table->key , key) != 0))
    {
        p_hash_table = p_hash_table->next;
    }

    if( strcmp (p_hash_table->key, key) == 0 )
    {
        fprintf(stdout, "Élément déjà créé\n");
        print_refcount();
        // On ne sait pas où on est dans la pile, mais la clé existe
        //
        // on écrase la valeur qui existe.
        // Pas d'augmentation de refcount
        // car le nombre d'éléments de la pile n'augmente pas
        p_hash_table->value = value;
    }
    else
    {
        print_refcount();
        fprintf(stdout, "Ajout d'un nouvel élément\n");
        // On n'a pas trouvé d'élément ayant la même clé
        // on ajoute un élément dans la pile
        // => refcount++ dans ce cas

        p_hash_table->next = (HASH *)malloc(sizeof(HASH));

        if(p_hash_table->next == NULL)
        {
            // on ne devrait jamais passer ici
            exit(EXIT_FAILURE);
        }

        // on a créé une instance du dernier 
        // élément de la pile en mémoire
        p_hash_table = p_hash_table->next;

        // on peut recopier la clé saisie dans le nouvel élément
        for (i=0; i<=strlen(key); i++)
        {
            p_hash_table->key[i]=key[i];
        }

        // on recopie la valeur associée à la clé (car appartenant au même élément)
        p_hash_table->value = value;

        // le nouvel élément créé est le dernier
        p_hash_table->b_isLast = true;

        // on initialise le pointeur sur l'élément suivant à NULL (0)
        p_hash_table->next = NULL;

        // la pile contient maintenant 1 élément supplémentaire
        refcount++;
        print_refcount();
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


void deleteKey (HASH * p_hash_table, char key[20] )
{
   HASH *hash_to_delete;

    while (strcmp (p_hash_table->next->key, key ) != 0)
    {
        p_hash_table = p_hash_table->next;
    }

    // c'est l'élément suivant qu'il faut supprimer
    // car c'est celui qui contient la clé
    hash_to_delete = p_hash_table->next;

    if (p_hash_table->next->next != NULL)
        p_hash_table->next = p_hash_table->next->next;

    if (( hash_to_delete != NULL ) && (refcount > 0))
    {
        free(hash_to_delete);
        refcount--;
        print_refcount();
    }
}


void pop (HASH * p_hash_table)
{
    if (( p_hash_table != NULL ) && (refcount > 0))
    {
        free(p_hash_table);
        refcount--;
        print_refcount();
    }
}

