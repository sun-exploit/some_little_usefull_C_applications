/* main.c from saisie_project
 * Author: Eric Bachard / Ven 29 mai 2015 13:59:01 CEST
 * This document is under GPL v2 License
 * See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "saisie.h"
#include "test_saisies_nombres.h"
#include "test_saisie_chaine.h"


int
main (void)
{
  efface_ecran();

  char MotSaisi[MAX_BUFFER_SIZE];

  fprintf(stdout, "Entrez ou mot, ou une chaîne de caractères (taille maxi : 512 caractères) :  \n");
  saisie_chaine_de_caracteres();
  strncpy(MotSaisi, g_buf, strlen(g_buf)); /* destination, source */
  fprintf(stdout, "Vous avez saisi le mot : %s \n", MotSaisi);

  /* simple example, to illustrate how things work */
  test_saisies_nombres();
  test_saisie_chaine();
  /* WRITE YOUR CODE HERE :-) */
  fprintf(stdout, "\nFin des tests...\n");
  return EXIT_SUCCESS;
}

