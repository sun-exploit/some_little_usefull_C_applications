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

#define CHAR_PLUS  0x2B
#define CHAR_MINUS 0x2D
#define CHAR_Q  0x51
#define CHAR_q  0x71


int main(void)
{
  bool bQuit = false;

  int c = 0;

  fprintf( stdout, "Appuyer sur q ou Q pour quitter \n");

  while (false == bQuit)
  {
    do
    {
        c = 0;
        c = (int)getch();
    }
    while ((c < CMIN) || (c > CMAX));

    fprintf( stdout, "Caractère saisi : %c \n", c);
    fprintf( stdout, "Valeur hexadécimale du caractère entré : %X \n", c);
    fprintf( stdout, "Valeur décimale du caractère entré : %d \n\n", c);

    switch (c)
    {
        case CHAR_Q:
        case CHAR_q:
            bQuit = true;
          break;

        default:
          break;
    }
  }
  return EXIT_SUCCESS;
}
