/* Ce programme calcule une valeur approchée de 
 * la racine de l'équation 3*ln(x) -x = 0
 * Eric Bachard / mars 2016 / Licence GPL
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* Algo de Newton donne la relation de récurrence :
 * Xn+1 = Xn - (3*log(Xn) - Xn)/(1/Xn -1)
 */

long double
fonction_xlnx ( long double valeur )
{
 return ( valeur - (3.0*logl(valeur) - valeur)/(3.0/valeur -1) );
}


int
main(void)
{
  int compteur = 1 ;
  const long double epsilon = 1e-6 ;
  const long double valeur_depart = 1.2 ;
  long double Xn = valeur_depart ;

  while ( fabs( Xn - (3.0*logl(Xn))) > epsilon )
  {
    Xn = fonction_xlnx( Xn );
    compteur++;
  }
  fprintf(stdout , "Soit à résoudre l'équation : 3*ln(x) -x = 0 \n") ;
  fprintf(stdout , "L'algorithme de Newton donne la relation de récurrence, à savoir : \n") ;
  fprintf(stdout , "Xn+1 = Xn - (3*log(Xn) - Xn)/(1/Xn -1)\n");
  fprintf(stdout , "... après calculs, ");
  fprintf(stdout , "la racine vaut: %Lf, obtenue en %d iterations \n" , Xn , compteur) ;
  return EXIT_SUCCESS ;
}
