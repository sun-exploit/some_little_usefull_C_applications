/* Eric Bachard Avril 2004 */ 


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) 
{
	/* FILE pointe sur le nom de fichier "fichier" */
        FILE * fichier;
	/* tampon comporte 101 valeurs = 100 caracteres + EOF */
	char tampon[101];
	int nblus;

	/* si on a oublié de donner un nom de fichier, on arrete */
	if (argc < 2)
	{
		fprintf(stderr,"Il faut donner un nom de fichier\n");
		
		/* 	pour information 
		 *	fprintf(stdout, "La valeur de sizeof(char) vaut %d \n", sizeof(char)); */
		return (-1);
	}
	
	/* le fichier spécifié n'existe pas, ou n'est pas autorisé en lecture */
	fprintf (stdout, "Nom du fichier ouvert : %s\n",argv[1]);
	fichier=fopen(argv[1],"r");
	
	if ( fichier == NULL ) {
		fprintf(stderr,"Impossible d'ouvrir %s\n",argv[1]);
		return (-2) ;
	}
	
	/* on lit... */
	while ( !feof( fichier ))
	{
		
		nblus = fread( tampon, sizeof(char), 100, fichier ) ;
		
		/* d'apres la page de man de fread, fread lit EOF comme une erreur, et l'appel 
		 * a feof est rendu obligatoire */
	 
		if ( ferror (fichier) ) 
		{
   			fprintf(stderr,"Erreur lors de la lecture\n") ;
   			return (-3) ;
		}

		tampon[nblus] = '\0';

		if ( fprintf(stdout,"%s\n",tampon ) < nblus ) 
		{
			fprintf(stderr, "Erreur lors de l'ecriture\n");
			return (-4) ;

		}
	}
	
	/* signale un probleme lors de la fermeture du fichier */
	if ( fclose( fichier ) == EOF ) 
	{
		fprintf(stderr,"Erreur de fermeture de %s\n",argv[1]) ;
	        return (-5) ;
	}	
	
	return EXIT_SUCCESS;
}
