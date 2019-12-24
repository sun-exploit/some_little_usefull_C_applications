/*  Copyright Eric Bachard  01 juin 2016 */

/* licence GPL V2 */


#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <linux/fd.h>
#include <stdbool.h>

/* D'après POSIX.1-2001 */

/* autres implémentations */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "getch.h"

#define CMIN 1
#define CMAX 255

#define CHAR_ESC 27

int main(void)
{
  bool bQuit = false;

  int c = 0;

  fprintf( stdout, "\nPour quitter, appuyer sur la touche échap (ESC) \n\n");

  while (false == bQuit)
  {
    do
    {
        c = 0;
        c = (int)getch();
    }
    while ((c < CMIN) || (c > CMAX));

    fprintf( stdout, "Caractère saisi : %c \n", c);
    fprintf( stdout, "Valeur hexadécimale : 0x%X \n", c);
    fprintf( stdout, "Valeur décimale : %d \n\n", c);

    switch (c)
    {
        case CHAR_ESC:
            bQuit = true;
        break;

        default:
        break;
    }
  }
  return EXIT_SUCCESS;
}
