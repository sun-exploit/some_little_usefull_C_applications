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

    //refcount++;

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


void eraseTable (HASH * p_hash_table)
{
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    HASH * my_hash_table_next;

    my_hash_table_next = p_hash_table->next;

    /* delete the element  H is pointing to */
    if ((p_hash_table != NULL ) && (refcount > 1))
    {
      free(p_hash_table);
      refcount--;
#ifdef DEBUG
      fprintf(stderr, "Décrémentation de refcount. Nouvelle valeur =  %d \n", refcount );
#endif
    }

    // On rappelle la fonction avec pour argument le pointeur vers l'element suivant

    if(my_hash_table_next != NULL)
        eraseTable (my_hash_table_next);
}


void push (HASH * p_hash_table, char key[20], int value)
{
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    unsigned int i;

    /*
        Tant que l'on est pas arrive au bout de la table de hashage
        et que la cle entree est differente de la cle des elements
        de la table de hashage, on passe a l'element suivant
    */


    while((p_hash_table->next != NULL) && (strcmp (p_hash_table->key , key) != 0))
    {
        p_hash_table = p_hash_table->next;
    }

    /* attention piège : strcmp compare 2 chaines de caractères et renvoie 0 ssi les 2 chaines sont identiques */

    if( strcmp (p_hash_table->key, key) == 0 )
        p_hash_table->value = value;
    else
    {
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

#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif

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
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
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

