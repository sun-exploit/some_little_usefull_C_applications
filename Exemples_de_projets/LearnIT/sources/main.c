#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

int main(void)
{
  fprintf(stdout, "Bonjour et bienvenue dans ce programme d'apprentissage. Choisissez entre :\n");
  menu();
  fprintf(stdout, "Merci et au revoir\n");
  return EXIT_SUCCESS;
}

