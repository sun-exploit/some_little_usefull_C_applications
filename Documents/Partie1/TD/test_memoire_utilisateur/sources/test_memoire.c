#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 

#include "initialize_time.h"
#include "saisie.h"
#include "constants.h"

/* Ce programme est un BROUILLON : ne marche pas tres bien  */
/* merci de  le noter */


/* ---------initialisation------------ */

short initialisation(int *tableau_initial)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        tableau_initial[i] = 0;
    }
    return EXIT_SUCCESS;
}
/* --------------------------------- */



/* ----------tirage_tableau_initial----------- */

short tirage_tableau_initial(int *tableau_initial)
{
    int indice;
    int alea = 0;
    BOOL sortie;
    initialize_time();
    for ( indice = 0; indice < ARRAY_SIZE ; indice++) 
    {
        do {
            sortie = TRUE;

            do {
                /* generate a value between VAL_MIN and VAL_MAX */
                alea = rand()%VAL_MAX + 1;
            } while (alea < VAL_MIN);
            
            /* we must be sure the value does not exist already */
            int valeur;
            for (valeur = 0; valeur < indice ; valeur++)
            {
                if ( tableau_initial[valeur] == alea )
                    sortie = FALSE;
            }
        }
        while (FALSE == sortie);

        /* fill the array */
        tableau_initial[indice] = alea;
    }
    return EXIT_SUCCESS;

}

/* --------------------------------- */


/* ----------generer_numero_element_tableau----------- */

short generer_numero_element_tableau(int tableau_initial[])
{
    initialize_time();
    short alea2;
    do {
        /* generate a value between 0 and 9 */
        alea2 = rand()%ARRAY_SIZE;
    } while(0 == tableau_initial[alea2]);

    return alea2;
}

/* --------------------------------- */



/* ----------afficher_question----------- */

short afficher_question(int value)
{
    char *suffixe;
    switch (value)
    {
    
    /* the first array element has index 0*/
    case (0):
        suffixe = "er";
        break;
    default:
        suffixe = "eme";
        break;
    }
    fprintf( stdout, "Donner le %d%s element du tableau \n\n",value + 1, suffixe);
    return EXIT_SUCCESS;
}

/* --------------------------------- */

/* ---------lire_reponse------------ */

short lire_reponse(void)
{
    short number;
    fprintf(stdout, "Entrer votre reponse et appuyer sur entree \n");
    number = saisie_nombre_entier_court(VAL_MIN, VAL_MAX);
    efface_ecran();
    return number;
}

/* --------------------------------- */



/* ----------affichage resultat_question----------- */

short affichage_resultat_question(int tableau_initial[], int rang, int number, int *p_nombre_de_points)
{
    /*hack*/
    fprintf(stdout, "vrai = %d ",tableau_initial[rang]);
    fprintf(stdout,"entre = %d \n",number); 
    if( number == tableau_initial[rang] )
    {
        fprintf(stdout, "C'est juste \n");
        *p_nombre_de_points += 2;
	/*hack*/
	printf("Nombre de points local %d \n", *p_nombre_de_points);
    }
    else
        fprintf(stdout,"C'est faux \n");

/*	getchar();
    efface_ecran();*/
    return EXIT_SUCCESS;
}

/* --------------------------------- */



/* ----------effacer_element_tableau----------- */

void effacer_element_tableau(int rang, int tableau_initial[])
{
    /* every checked value is replaced by a zero */
    tableau_initial[rang] = 0;
}

/* --------------------------------- */


/* ----------affichage_resultat_final----------- */

void affichage_resultat_final(int points)
{
        fprintf(stdout, "Nombre de points final =  %d \n", points); 
}

/* --------------------------------- */


/* ----------affichage_tableau_initial----------- */

void affichage_tableau_initial(int tableau_initial[])
{
    int i;
    for( i = 0 ; i < ARRAY_SIZE; i++)
    fprintf(stdout,"Tirage %2d : %d   \n",i + 1, tableau_initial[i]);
    fprintf(stdout,"\n");
}

/* --------------------------------- */



/* ---------- main ----------- */

int main(void)
{        
    int nombre_de_points = 0;
    int *p_nombre_de_points;
    p_nombre_de_points = &nombre_de_points; 
    int tableau_initial[ARRAY_SIZE];
    initialisation(tableau_initial);
    tirage_tableau_initial(tableau_initial);
    affichage_tableau_initial(tableau_initial);
    fprintf(stdout," appuyer sur Entree pour continuer");
    getchar();
    efface_ecran();
    int k;
    for(k = 0; k < ARRAY_SIZE; k++)
    {
        short rang = generer_numero_element_tableau(tableau_initial);
        afficher_question(rang);
        short reponse = lire_reponse();
        affichage_resultat_question(tableau_initial, rang, reponse, p_nombre_de_points);
        effacer_element_tableau(rang,tableau_initial);
    
    }
    affichage_resultat_final(nombre_de_points);
  	return EXIT_SUCCESS; 
}

/* --------------------------------- */