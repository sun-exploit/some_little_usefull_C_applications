/* Auteur:  Eric Bachard  / 17 novembre 2014
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>

void display (void)
{
#ifdef DEBUG
  fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif 
  fprintf(stdout, " \nQue souhaitez-vous faire ?\n");
  fprintf(stdout, " ___________________________________________");
  fprintf(stdout, " \n1 -> Affecter une valeur à une clé donnée");
  fprintf(stdout, " \n2 -> Retourner la valeur associée à une clé donnée");
  fprintf(stdout, " \n3 -> Rechercher si une clé existe dans la table");
  fprintf(stdout, " \n4 -> Détruire un élément à partir de sa clé");
  fprintf(stdout, " \n5 -> Détruire toute la table de hashage");
  fprintf(stdout, " \n6 -> Quitter le programme\n");
}


