#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void     usage(char *s);
int
main(int argc, char *argv[])
{
  if (argc != 4)
    usage(argv[0]);
  else
  {
    double          a = atof(argv[1]);
    double          b = atof(argv[2]);
    double          c = atof(argv[3]);
    double          delta = b * b - 4 * a * c;
    if (delta < 0)
      fprintf(stdout, "Pas de racine reelle\n");
    else if (delta == 0)
      fprintf(stdout, "Une racine double : %g\n", -b / (2 * a));
    else
    {
      double          racine_de_delta = sqrt(delta);
      fprintf(stdout, "Deux racines : %g et %g\n",
       (-b - racine_de_delta) / (2 * a),
       (-b + racine_de_delta) / (2 * a));
    }
  }
  return EXIT_SUCCESS;
}
static void
usage(char *s)
{
  fprintf(stderr, "Usage: %s \"a\" \"b\" \"c\" \n", s);
  exit(EXIT_FAILURE);
}
