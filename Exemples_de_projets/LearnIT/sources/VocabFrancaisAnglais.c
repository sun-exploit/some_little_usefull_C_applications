/* Certaines parties sont inspirées des ressources de Eric Bachard */
/* Programme d'apprentissage de Vocabulaire Francais -> Anglais */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vider_tampon.h"
#include "Vocab_limits.h"

short int VocabulaireFrancaisAnglais(void)
{
#ifdef DEBUG
  fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
  vider_tampon();
  FILE *fichier = NULL; /* fichier est le nom local du fichier */
/* Initialisation du fichier qui représentera le fichier data.txt ouvert */
/*    fichier = fopen("../ressources/VocabFrancaisAnglais.csv" , "r");*/
  fichier = fopen("../ressources/VocabTest.txt" , "r");

  if ( fichier != NULL )
  {
    char MotFrancais[WORD_SIZE_MAX];
    char MotAnglais[WORD_SIZE_MAX];
    char ligne[WORD_SIZE_MAX];

    char* motTemp;
    char saisie[WORD_SIZE_MAX]; /* Déclaration d'une variable "saisie" de type chaîne de caractères pour la suite */
    int resultat = 0;

    while ( fgets( ligne, sizeof(ligne), fichier ) != NULL && !feof(fichier)) /* Lire une ligne */
    {
      /* memset (saisie, 0, sizeof (saisie)); */

      motTemp=strtok(ligne, ","); /* APPEL jusqu'à la virgule => (EN GROS) LE PREMIER MOT (Francais) */
      strncpy(MotFrancais, motTemp, WORD_SIZE_MAX); /* Fonction qui copie le contenu de motTemp dans MotFrancais */
      motTemp=strtok(NULL, ""); /* APPEL après la virgule => DEUXIEME MOT (Anglais) */
      strncpy(MotAnglais, motTemp, WORD_SIZE_MAX);
      fprintf(stdout, "Traduction en anglais de : %s ? (Puis taper sur entrée)\n", MotFrancais);
#ifdef DEBUG
      fprintf(stdout, "%s", saisie);
#endif
      fgets(saisie, sizeof saisie, stdin); /* Saisie sécurisée : fonction équivalente à fscanf */

     /* La fonction strcmp renvoie une valeur (0 si c'est juste) que l'on affecte à une variable "resultat" */
      int size = strlen(MotAnglais);
      // Matches only if we do not consider the \r and \n in MotAnglais
      resultat = strncmp(saisie, MotAnglais, size - 2); 

#ifdef DEBUG
      fprintf(stdout, "resultat de la comparaison : %d \n", resultat);
#endif
      if (resultat == 0) /* Correction */
        fprintf(stdout, "Bravo. C'était la bonne réponse :-)\n\n");
      else
        fprintf(stdout, "Faux. La réponse était %s \n", MotAnglais);

      motTemp = '\0';
    }

    if(fclose(fichier) != EOF)
    {
      fprintf(stdout, "Probleme de fermeture du fichier \n");
      return EXIT_FAILURE;
    }
  }
  else /*( fichier == NULL)*/
  {
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    fprintf(stdout, "Problème d'ouverture du fichier \n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
