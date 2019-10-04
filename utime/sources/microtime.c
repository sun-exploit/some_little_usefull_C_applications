#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/time.h>  /* gettimeofday() */
#include <unistd.h>    /* CLOCK_REALTIME */
#include <time.h>      /*    timespec    */

/*
  Reference pour en savoir plus : https://www.systutorials.com/5086/measuring-time-accurately-in-programs/
*/

/* une seule fois */
static bool b_once = true;

/* C structure containing a given time in microsecond, and more */
struct timeval tv;

struct timespec tspec;

int main (void)
{
  int i = 0;
  int j = 0;
  long int utime1 = 0;
  long int utime2 = 0;
  for (i=0 ; i <4 ; i++)
  {
      clock_gettime(CLOCK_REALTIME, &tspec);
      fprintf(stdout, "Time with tspec : %ld \n", tspec.tv_nsec);

      gettimeofday(&tv, NULL);
      utime2 = tv.tv_usec;
      srand(utime2);
      fprintf(stdout, "Date du tirage (en usec): %ld \n", tv.tv_usec);

      int count = 1;
      for (j=0; j <4 ;j++)
      {
        fprintf (stdout, "Tirage %d : %d \n",count, (rand()%10 +1));
        count++;
      }

      if (b_once == false)
        fprintf (stdout, "Durée entre 2 tirages : %ld micro secondes \n",utime2 -utime1 );

      utime1 = utime2;

      // pattern type singleton
      b_once = false;

  }
  return EXIT_SUCCESS;
}
