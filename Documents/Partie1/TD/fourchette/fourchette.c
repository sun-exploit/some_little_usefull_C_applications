/* Programme de la fourchette Examen A06 LO20 Eric Bachard */

/*  Auteur : Eric Bachard
 *  Licence de ce document : Creative Commons pas d'utilisation commerciale 
 *  pas de modification. Voir http://creativecommons.org/licenses/by-nc-nd/2.5/
 */ 

/* Author : Eric Bachard
 * This document is licensed under Creative Commons License : no commercial
 * use, no modification. See : http://creativecommons.org/licenses/by-nc-nd/2.5/
 */


#include <stdio.h>
#include <stdlib.h>

/* constantes */ 

#define NOMBRE_CACHE 52
#define VAL_MAX 100
#define VAL_MIN 1

int main(void) 
{
    int continuer;
    int essais = 1 ;
    int nombre_cache;
    int nombre_saisi;
    int min = VAL_MIN;
    int max = VAL_MAX;
    
    fprintf(stdout, "Saisir 1 pour jouer, sinon 0 pour quitter\n");
    fscanf(stdin, "%d", &continuer);
    
    while ( (continuer != 0) )
     {
        nombre_cache = NOMBRE_CACHE;
        fprintf(stdout, "Choisir x entier compris entre %d et %d\n", min, max);
        fscanf(stdin, "%d", &nombre_saisi);
         
        if (nombre_saisi < nombre_cache)
        {
            min = nombre_saisi;
            essais += 1;
        }
        else if (nombre_saisi > nombre_cache )
        {
            max = nombre_saisi;
            essais += 1;
        }    
        else  /* nombre_saisi == nombre_cache */
        {
            fprintf(stdout, "Nombre cache decouvert en %d essais\n", essais);
            essais = 1;
            min = VAL_MIN; 
            max = VAL_MAX;
            fprintf(stdout, "Saisir 1 pour jouer, sinon 0 pour quitter\n");
            fscanf(stdin, "%d", &continuer);
            
        }
        if ( essais > max )
            continuer = 0;
    }
        
   return EXIT_SUCCESS ;
}

