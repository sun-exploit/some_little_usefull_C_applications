#include <stdio.h>
#include <stdlib.h>
#define NB_ELEMENT 10
int
main(void)
{
    int i;
    float vecteur[NB_ELEMENT];
    float moyenne = 0;
    float somme = 0;
    /* Initialisation du tableau + E/S */
    for (i = 0; i < NB_ELEMENT; i++)
    {
        vecteur[i] = i/10.0;
        fprintf(stdout, "vecteur[%d] = %.3f\n", i, vecteur[i]);
    }
    /* Calcul de la moyenne */
    for (i = 0; i < NB_ELEMENT; i++)
    {
        somme += vecteur[i];
        /* Accumulation */
    }
    moyenne = somme / NB_ELEMENT;
    /* Division */
    fprintf(stdout, "La moyenne est %.3f\n", moyenne);
    return EXIT_SUCCESS;
}
