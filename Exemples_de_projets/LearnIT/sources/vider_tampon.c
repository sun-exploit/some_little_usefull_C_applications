#include <stdio.h>

void vider_tampon(void)
{
  int c = 0;
  while (c != '\n' && c != EOF)
  {
    c = getchar();
  }
}
