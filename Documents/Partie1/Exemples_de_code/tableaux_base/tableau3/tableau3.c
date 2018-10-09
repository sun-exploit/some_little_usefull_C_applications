#include <stdio.h>
#include <stdlib.h>
int tab2[5]={0,1,2,34,5};
int tab[5];
int
main (void)
{
    int i;
    for (i=0;i<5;i++)
    {
        printf(" element %d : %d \n", i+1 , tab2[i]);
    }

    for (i=0;i<5;i++)
    {;
        tab[i]=tab2[i];
        printf(" element %d du second tableau est %d \n", i+1, tab[i]);
    }

    int val;
    for (i=0;i<5;i++)
    {
        val=tab2[i];
        tab[i]=val;
        printf(" element %d du second tableau est %d \n", i+1, tab[i]*2);
    }


    return EXIT_SUCCESS;
}