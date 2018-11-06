#include <stdio.h>
#include <stdlib.h>
#include "variablesglobal.h"

int initialisation_MASK_FORMAT(void)
{
    tableau_MASK_FORMAT [0] = 1;
    tableau_MASK_FORMAT [1] = 0;
    tableau_MASK_FORMAT [2] = 1;
    tableau_MASK_FORMAT [3] = 0;
    tableau_MASK_FORMAT [4] = 1;
    tableau_MASK_FORMAT [5] = 0;
    tableau_MASK_FORMAT [6] = 0;
    tableau_MASK_FORMAT [7] = 0;
    tableau_MASK_FORMAT [8] = 0;
    tableau_MASK_FORMAT [9] = 0;
    tableau_MASK_FORMAT [10] = 1;
    tableau_MASK_FORMAT [11] = 0;
    tableau_MASK_FORMAT [12] = 0;
    tableau_MASK_FORMAT [13] = 1;
    tableau_MASK_FORMAT [14] = 0;

     for (m=0; m<15; m++)
    {
        fprintf(stdout, "%d \n", tableau_MASK_FORMAT [m]);
    }

    return EXIT_SUCCESS;
}

int recuperation_FORMAT(void)
{
    tableau_FORMAT [0] = tableau_QR [8][0];
    tableau_FORMAT [1] = tableau_QR [8][1];
    tableau_FORMAT [2] = tableau_QR [8][2];
    tableau_FORMAT [3] = tableau_QR [8][3];
    tableau_FORMAT [4] = tableau_QR [8][4];
    tableau_FORMAT [5] = tableau_QR [8][5];
    tableau_FORMAT [6] = tableau_QR [8][7];
    tableau_FORMAT [7] = tableau_QR [8][8];
    tableau_FORMAT [8] = tableau_QR [7][8];
    tableau_FORMAT [9] = tableau_QR [5][8];
    tableau_FORMAT [10] = tableau_QR [4][8];
    tableau_FORMAT [11] = tableau_QR [3][8];
    tableau_FORMAT [12] = tableau_QR [2][8];
    tableau_FORMAT [13] = tableau_QR [1][8];
    tableau_FORMAT [14] = tableau_QR [0][8];

    for (m=0; m<15; m++)
    {
        fprintf(stdout, "%d \n", tableau_FORMAT [m]);
    }

    return EXIT_SUCCESS;
}

int application_MASK_FORMAT(void)
{
    for (m=0; m<15; m++)
    {
        tableau_FORMAT [m] = tableau_FORMAT [m]^tableau_MASK_FORMAT [m];
        fprintf(stdout, "%d \n", tableau_FORMAT [m]);
    }

    return EXIT_SUCCESS;
}
