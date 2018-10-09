#include <stdio.h>
#include <stdlib.h>

int tab2[5]={0,1,2,34,5};

int
main (void)
{
    int i;

    for (i=0;i<20;i++)
    {
        fprintf(stdout, "Element %d : %d \n", i+1 , tab2[i]);
    }
    return EXIT_SUCCESS;
}
