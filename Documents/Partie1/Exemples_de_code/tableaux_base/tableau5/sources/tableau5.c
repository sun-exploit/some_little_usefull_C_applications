#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define NB_ELEMENT 6

int
main(void)
{
    int vecteur_initial[] = {3,6,1,9,2,5};
    int vecteur_trie[NB_ELEMENT];
    int min_index, i, j;

    for (i = 0; i < NB_ELEMENT; i++)
    {

        fprintf(stdout, "vecteur_initial[%d] = %d\n", i, vecteur_initial[i]);

    }

    for (i = 0; i < NB_ELEMENT; i++)
    {
        min_index = 0;

        for (j = 1; j < NB_ELEMENT; j++)
        {
            if (vecteur_initial[j] < vecteur_initial[min_index])
            {
                 /*     un element plus petit a ete trouve on note donc son indice

                        dans min_index

                  */
                min_index = j;
            }
        }
        vecteur_trie[i] = vecteur_initial[min_index];
        vecteur_initial[min_index] = INT_MAX;
    }

    for (i = 0; i < NB_ELEMENT; i++)
    {
        fprintf(stdout, "vecteur_trie[%d] = %d\n", i, vecteur_trie[i]);
    }

    return EXIT_SUCCESS;
}