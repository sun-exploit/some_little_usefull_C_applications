/* Programme d'essai qui consiste à ajouter des mots à la fin d'un fichier texte */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AjoutsMots.h"
#include "vider_tampon.h"

short int AjoutMotsVocabulaire(void)
{
  FILE *fichier = NULL;
  char MotFrancais[WORD_SIZE_MAX];
  char MotAnglais[WORD_SIZE_MAX];
  int NbreMots = 0;
  int i = 0;
  fichier = fopen("../ressources/VocabTest.txt", "a");
#ifdef DEBUG
  fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
  fprintf(stdout, "Nom du fichier ouvert en lecture / écriture :  %s \n", (char *)fichier );
#endif

  if (fichier != NULL)
  {
    fprintf(stdout, "Combien de mots souhaitez-vous ajouter ? ");
    fscanf(stdin, "%d", &NbreMots);
    vider_tampon();
    for (i = 0 ; i < NbreMots ; i++)
    {
      fprintf(stdout, "Nouveau Mot français : ");
      fgets(MotFrancais, WORD_SIZE_MAX, stdin);
      fprintf(stdout, "%s", MotFrancais);
      fprintf(stdout, "=> Sa traduction en anglais : ");
      fgets(MotAnglais, WORD_SIZE_MAX, stdin);
      fprintf(stdout, "%s", MotAnglais);
      char * p1 = strchr(MotFrancais , '\n');
      char * p2 = strchr(MotAnglais , '\n');
      *p1 = ' ';
      *p2 = ' ';
      fprintf(fichier, "%s,%s\n", MotFrancais, MotAnglais);
    }

    if( EOF != fclose(fichier) )
    {
#ifdef DEBUG
      fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
      fprintf(stderr, "Probleme de fermeture du fichier\n");
      return (EXIT_FAILURE);
    }
  }
  else
  {
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    fprintf(stderr, "Problème d'ouverture de fichier !\n");
    return (EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
