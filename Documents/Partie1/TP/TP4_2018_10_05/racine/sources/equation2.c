#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "saisie.h"

int main(void)
{
	long double a=0.0;
	long double b=0.0;
	long double c=0.0;
	long double delta=-1.0;
	long double x1=0.0, x2=0.0;

	fprintf(stdout, "Ce programme vous donnera les ou la racine(s) d'un polynome du second degrè \n");

	fprintf(stdout, "Entrer a :  \n");
        a = saisie_nombre_reel(-REEL_MAX, REEL_MAX);

	fprintf(stdout, "Entrer b :  \n");
        b = saisie_nombre_reel(-REEL_MAX, REEL_MAX);

	fprintf(stdout, "Entrer c :  \n");
        c = saisie_nombre_reel(-REEL_MAX, REEL_MAX);

	delta= b*b-4*a*c;

        fprintf (stdout, "delta vaut : %Lf \n", delta);

        if (a == 0)
	{
            fprintf(stdout, "la premiere racine est unique et vaut: %Lf \n", -c/b);
	}
        else
	{
	   if (delta>0)
	   {
	   	   x1= (-b+sqrt(delta))/2*a;
		   fprintf(stdout, "la premiere racine est: %Lf \n", x1);
	
		   x2= (-b-sqrt(delta))/2*a;
		   fprintf(stdout, "la deuxième racine est: %Lf \n", x2);
	   }
	   else if (delta == 0)
	   {
		   x1= -b/2*a;
		   fprintf(stdout, "Cette équation possède une racine double: x1 = x2 = %Lf \n", x1);
	   }
	   else
	   {
		   fprintf(stdout, "Cette équation ne possède pas de racine réelle\n");
	   }
        }
	return EXIT_SUCCESS;
}
