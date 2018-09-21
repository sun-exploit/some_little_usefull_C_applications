#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 

int main(int argc,char** argv)
{
    int tirage;
    time_t valeur_temps;
    (void)time(&valeur_temps);
    srand((long)valeur_temps);     /*intitialisation du random*/
    for(tirage = 0; tirage < 10; tirage++)
    fprintf(stdout, "%d\n",rand()%488);
    return EXIT_SUCCESS;
}

