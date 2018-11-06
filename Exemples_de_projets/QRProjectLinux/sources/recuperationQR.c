#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variablesglobal.h"

#include "recuperationQR.h"
#include "saisie.h"


/*Partie Qr code*/

int init_tableau_QR(void)
{
    for (i=0; i<21; i++)
    {
        for (j=0; j<21; j++)
        {
            tableau_QR [i][j] = '\0';
            /*fprintf(stdout,"i=%d  j=%d  value=%d\n",i,j,tableau_QR [i][j]);*/
        }
    }

    return EXIT_SUCCESS;
}

int recuperation_QR(void)
{
  FILE* fichier = NULL;
  int c;
  short int i=0;
  short int j=0;

    /* on remplit chemin de 0 */
    memset(chemin, '\0', sizeof(chemin));

    /* ensuite on écrit ../ressources/ dans chemin */
    strcpy(chemin, RESSOURCES_PATH);

#ifdef DEBUG
    /* vérification */
    fprintf( stdout, "chemin contient %s : \n", chemin);
#endif
    /* on saisit le nom du fichier */
    saisie_chaine_de_caracteres();
    strlcpy(nom_fichier, g_buf, sizeof(g_buf));

  /* char *strcat(char *dest, const char *src);
     La fonction strcat() ajoute la chaîne src à la fin de la chaîne dest 
     en écrasant l'octet nul (« \0 »)
     final à la fin de dest, puis en ajoutant un nouvel octet nul final
   */

    strcat( chemin, nom_fichier);
#ifdef DEBUG
    fprintf( stdout, "chemin contient maintenant %s : \n", chemin);
#endif

    /* on ouvre le nom du fichier complet monfichier.txt existe dans le répertoire ../ressources/ */
    fichier = fopen(chemin, "r");

#ifdef DEBUG
    if (fichier != NULL)
      fprintf(stdout, "fichier correctement ouvert en lecture (%p) \n",(void*) fichier);
#endif
  /* FIXME : ajouter un test, pour voir si le fichier existe, et contient quelque chose, etc */

    if (fichier != NULL)
  {
    while ((c = fgetc(fichier)) != EOF)
    {
      switch(c)
      {
        case '0':
            tableau_QR [i][j] = 0;
            j++;
            break;

                case '1':
                    tableau_QR [i][j] = 1;
                    j++;
                    break;

                case '\n':
                    i++;
                    j=0;
                    break;


                default:
                    fprintf(stdout, "erreur de lecture d'un caractère.\n");
                    break;
            }
        }
    }
    else
    {
        fprintf(stdout, "impossible d'ouvrir le fichier \n");
    }

    fclose(fichier);

    return EXIT_SUCCESS;
}

int affich_tableau_QR(void)
{
    for (i=0; i<21; i++)
    {
        for (j=0; j<21; j++)
        {
            fprintf(stdout,"%d ",tableau_QR [i][j]);
        }

        fprintf(stdout,"\n");
    }

    return EXIT_SUCCESS;
}

/*Partie masque*/

int init_tableau_MASK_QR(void)
{
    for (i=0; i<21; i++)
    {
        for (j=0; j<21; j++)
        {
            tableau_MASK_QR [i][j] = '\0';
            /*fprintf(stdout,"i=%d  j=%d  value=%d\n",i,j,tableau_QR [i][j]);*/
        }
    }

    return EXIT_SUCCESS;
}

int recuperation_MASK_QR(void)
{
    FILE* fichier = NULL;
    int c;

    switch(valeur_masque)
    {
        case 0:
            fichier = fopen("../masks/000.txt","r");
            break;

        case 1:
            fichier = fopen("../masks/001.txt","r");
            break;

        case 2:
            fichier = fopen("../masks/010.txt","r");
            break;

        case 3:
            fichier = fopen("../masks/011.txt","r");
            break;

        case 4:
            fichier = fopen("../masks/100.txt","r");
            break;

        case 5:
            fichier = fopen("../masks/101.txt","r");
            break;

        case 6:
            fichier = fopen("../masks/110.txt","r");
            break;

        case 7:
            fichier = fopen("../masks/111.txt","r");
            break;

        default:
            fprintf(stdout, "erreur de lecture du type de masque./n");
            break;
    }

    if (fichier != NULL)
    {

        while ((c = fgetc(fichier)) != EOF)
        {

            switch(c)
            {
                case 48:
                    tableau_MASK_QR [i][j] = 0;
                    j++;
                    break;

                case 49:
                    tableau_MASK_QR [i][j] = 1;
                    j++;
                    break;

                case 50:
                    tableau_MASK_QR [i][j] = 2;
                    j++;
                    break;

                case 10:
                    i++;
                    j=0;
                    break;

                default:
                    fprintf(stdout, "erreur de lecture d'un caractère./n");
                    break;
            }
        }
    }
    else
    {
        fprintf(stdout, "impossible d'ouvrir le fichier \n");
    }

    fclose(fichier);

    return EXIT_SUCCESS;
}

int application_MASK_QR(void)
{
    for (i=0; i<15; i++)
    {
        for (j=0; j<15; j++)
        {
            tableau_QR [i][j] = tableau_QR [i][j]^tableau_MASK_QR [i][j];
            /*fprintf(stdout, "%d", tableau_QR [i][j]);*/
        }
    }
    return EXIT_SUCCESS;
}
