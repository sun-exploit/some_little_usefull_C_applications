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

char getch()
{
    fd_set set;
    struct timeval timeout;
    int rv;
    char buff = 0;
    int len = 1;
    int filedesc = 0;
    FD_ZERO(&set);
    FD_SET(filedesc, &set);

    timeout.tv_sec = 0;
    timeout.tv_usec = 1000;
    rv = select(filedesc + 1, &set, NULL, NULL, &timeout);
    struct termios old = {0};
    tcgetattr(filedesc, &old);
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;

    tcsetattr(filedesc, TCSANOW, &old);

    if(rv != -1)
    {
      int anErr = read(filedesc, &buff, len );

      if (anErr < 0)
        fprintf(stdout, "read issue");
    }

    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;

    tcsetattr(filedesc, TCSADRAIN, &old);

    return (buff);
}

