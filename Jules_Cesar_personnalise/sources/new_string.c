/*
    file strings_utils.c

    Copyright Eric Bachard  01 juin 2016

    licence GPL V2

 */

#include <stdio.h>
#include <stdlib.h>

#include "efface_ecran.h"
#include "constants.h"
#include "saisie.h"
#include "utils.h"
#include "strings_utils.h"


int clear_string(char aString[])
{
    for (int i = 0 ; i < STRING_SIZE_MAX ; i++)
    {
        aString[i] = '\0';
    }
    return EXIT_SUCCESS;
}

int new_string(char * sString, char * sNewString, int * p_length, int * p_offset)
{
    fprintf(stdout, "\nSaisir une nouvelle chaîne de caractère (taille max = 512) : ");

    clear_string(sString);
    clear_string(sNewString);

    saisie_chaine_de_caracteres();
    strlcpy(sString, g_buf, sizeof(g_buf));

    int count = 0;

    while ((sString[count] != '\0') && (count< STRING_SIZE_MAX))
    {
        count++;
    }

    *p_length = count;
#ifdef DEBUG
    fprintf(stdout, "length = %d \n", *p_length);
    getchar();
#endif
    refresh_screen(sString, sNewString, p_length, p_offset);

    return EXIT_SUCCESS;
}


int create_modified_string(char * chaine_a_chiffrer, char * chaine_chiffree, int * p_length, int * p_offset)
{
    int i = 0;

#ifdef DEBUG
    fprintf(stdout, "*p_length contient : %d \n", *p_length);
#endif
    for (i = 0 ; i < *p_length ; i++)
    {
        if (((chaine_a_chiffrer[i] > 0x60) && (chaine_a_chiffrer[i] < 0x7B)) || ((chaine_a_chiffrer[i] > 0x40) && (chaine_a_chiffrer[i] < 0x5B)) )
        {
            // lettre majuscule : comprise entre 0x41 et 0x5A
            if ((chaine_a_chiffrer[i] > 0x40) && (chaine_a_chiffrer[i] < 0x5B))
            {
                chaine_chiffree[i] = chaine_a_chiffrer[i] + *p_offset;

                if (chaine_chiffree[i] > 0x5A)
                    chaine_chiffree[i] = chaine_chiffree[i] - 26;

                if (chaine_chiffree[i] < 0x41)
                    chaine_chiffree[i] = chaine_chiffree[i] + 26;
            }

            // lettre minuscule : comprise entre 0x61 et 0x7A
            if ((chaine_a_chiffrer[i] > 0x60) && (chaine_a_chiffrer[i] < 0x7B))
            {
                chaine_chiffree[i] = chaine_a_chiffrer[i] + *p_offset;

                if (chaine_chiffree[i] > 0x7A)
                    chaine_chiffree[i] = chaine_chiffree[i] - 26;

                if (chaine_chiffree[i] < 0x61)
                    chaine_chiffree[i] = chaine_chiffree[i] + 26;
            }
        }
        else
            chaine_chiffree[i] = chaine_a_chiffrer[i];
#ifdef DEBUG
        fprintf(stdout, "chaine_a_chiffrer[%d] = %c\n" , i, chaine_a_chiffrer[i]);
        fprintf(stdout, "chaine_chiffree[%d] = %c\n" , i, chaine_chiffree[i]);
        fprintf(stdout, "Valeur décimale de chaine_chiffree[%d] = %d\n" , i, chaine_chiffree[i]);
        fprintf(stdout, "Valeur hexadécimale de chaine_chiffree[%d] = %X\n" , i, chaine_chiffree[i]);
#endif
    }
    return EXIT_SUCCESS;
}


int refresh_screen(char chaine_a_chiffrer[], char chaine_chiffree[], int * p_length, int * p_offset)
{
#ifndef DEBUG
    efface_ecran();
#endif
    fprintf(stdout, "\nChaine de caractère saisie :  %s \n", chaine_a_chiffrer);
    fprintf(stdout, "\nValeur du décalage :  %hd \n\n", *p_offset);

    int anErr =  create_modified_string(chaine_a_chiffrer, chaine_chiffree, p_length, p_offset);

    if (anErr != 0)
        fprintf(stdout, "Problème avec la saisie\n");

    fprintf(stdout, "Chaine chiffree :  %s \n", chaine_chiffree);

    return EXIT_SUCCESS;
}

