#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  int i;
  time_t t1;
  (void)time(&t1);
  srand((long)t1);   /*  initialisation du random*/

  for(i=0;i<10;i++)
    fprintf(stdout, "%d\n",rand()%488);

  return 0;
}


