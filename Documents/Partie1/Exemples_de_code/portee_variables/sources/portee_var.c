/* portee_var.txt */

#include <stdio.h>
#include <stdlib.h>

int x = 0;

int main(void)
{
  int i,j,k;
  j = 0;
  k = 0;
  x = 0;
  for (i = 0; i < 3; i = i + 1)
  {
    int x;		/* ce x cache le x global */
    int j;		/* ce j cache le j local  */
    j = k + i;
    x = 3 * j;
    k = x;
    fprintf( stdout,"i=%d, j=%d , k=%d , x=%d\n", i,j,k,x);
  }
  fprintf( stdout,"\n");
  fprintf( stdout,"i=%d, j=%d , k=%d , x=%d\n", i,j,k,x);
  return EXIT_SUCCESS;
}
