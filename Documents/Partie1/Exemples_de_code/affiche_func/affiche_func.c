#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    fprintf( stdout, "Je suis dans : %s \n", __func__);
    return EXIT_SUCCESS;
}
