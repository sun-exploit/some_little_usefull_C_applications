/* 
 * Bubble sort implementation.
 * Copyright : Eric Bachard  01/2010
 * License : CC by-sa
 *
 */
#include <stdio.h>
#include <stdlib.h>

int arrayElement[7] = {9,5,2,12,34,6,23};
int arraySize = sizeof( arrayElement ) / sizeof( arrayElement[0] ) ;

void bubbleSort( void )
{
    int i,
	k,
	temp = 0;
#ifdef DEBUG
    fprintf( stdout, "arraySize        vaut : %d \n\n", arraySize);
#endif
    for ( k=arraySize-1 ; k>0 ; k-- )
    {
        for ( i = 1; i < k+1 ; i++ )
        {
#ifdef DEBUG
            fprintf( stdout, "k           vaut : %d \n\n", k);
            fprintf( stdout, "i           vaut : %d \n\n", i);
            fprintf( stdout, "element i   vaut : %d \n\n", arrayElement[i]);
            fprintf( stdout, "element i-1 vaut : %d \n\n", arrayElement[i-1]);
            fprintf( stdout, "temp        vaut : %d \n\n", temp);
#endif
#if defined CROISSANT
            if ( arrayElement[i] < arrayElement[i-1] )
#else
            if ( arrayElement[i] > arrayElement[i-1] )
#endif
            {
		/* swap the elements */
                temp = arrayElement[i];
                arrayElement[i] = arrayElement[i-1];
                arrayElement[i-1] = temp;
            }
        }
    }
}

void displayArray( void )
{
    int i;
    for ( i = 0 ; i < arraySize ; i++ )
    {
	fprintf( stdout, "Valeur element %d : %d \n", i+1 , arrayElement[i]);
    }
}

int main ( void )
{
#ifdef DEBUG
    fprintf( stdout, "Taille du tableau : %d \n\n", arraySize);
#endif
    bubbleSort();
    displayArray();
    return EXIT_SUCCESS;
}
