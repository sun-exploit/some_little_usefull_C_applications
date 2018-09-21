/* buggy.c Version corrigée Eric Bachard Mai 2005 */
#include <stdio.h>
#include <stdlib.h>

static char buf[256];
void lit_entree (char *s);

int
main (void)
{
  /* on écrit explicitement que entree ne contient rien */
  char * entree = NULL;

  /* Le crash était causé par le fait que l'endroit ou l'on écrivait 
   * la chaîne entrée n'était pas défini 
   * (Par défaut le compilateur attribue l'adresse 0x0 == adresse indéfinie
   * où il est interdit d'écrire, ce qui cause un crash immédiat.
   * En ajoutant entree = buf; on définit explicitement que l'on va stocker
   * les caractères saisis dans le tableau buf
   */
  entree = buf;

  lit_entree (entree);
  fprintf (stdout, "Vous avez tape :  %s\n", entree);
  return EXIT_SUCCESS;
}

void lit_entree (char *s)
{
  fprintf (stdout, "Commande : ");
  fgets (s, sizeof(buf), stdin );
}
