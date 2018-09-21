/* initialize_rand.c programme servant à initialiser
 * le générateur de nombres aléatoires
 * Auteur : Eric Bachard
 * Ce document est sous Licence GPL v2  Octobre 2014
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
initialize_rand( void )
{
    /* on declare une variable nommee t1 de type temps (time_t)*/
    time_t t1;

    /* time (&t1) ecrit la valeur du temps au moment de l'execution
       a l'adresse de t1
     */
    (void)srand(time(&t1));

    /*
       srand genere une suite de nombres aleatoires 
       a partir de la "graine" (valeur de t1)
       ecrite a l'adresse de t1
     */
    srand((long)t1);
}
