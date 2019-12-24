/*  Copyright Eric Bachard  01 juin 2016 */

/* licence GPL V2 */


#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <linux/fd.h>
#include <stdbool.h>

/* D'après POSIX.1-2001 */

/* autres implémentations */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "getch.h"
#include "efface_ecran.h"
#include "saisie.h"
#include "utils.h"
#include "strings_utils.h"
#include "constants.h"


static char chaine_a_chiffrer[STRING_SIZE_MAX] = "";
static char chaine_chiffree[STRING_SIZE_MAX] = "";
static int length = STRING_SIZE_MAX;
static int * p_length = &length;
static int offset = 0;
static int * p_offset = &offset;


int main(void)
{
    bool bQuit = false;
    efface_ecran();

    for (int i = 0 ; i < STRING_SIZE_MAX ; i++)
    {
        chaine_a_chiffrer[i] = 0;
    }

    new_string(chaine_a_chiffrer, chaine_chiffree, p_length, p_offset);

    int c = 0;

    fprintf( stdout, "\nAppuyer sur une touche, ou appuyer sur la touche échap (ESC) pour quitter.");
    fprintf( stdout, "\nPour saisir une nouvelle chaîne à chiffrer ou déchiffrer, appuyer sur la touche \" # \"\n\n");

    do 
    {
        do
        {
            c = 0;
            c = (int)getch();
        }
        while ((c < CMIN) || (c > CMAX));

        switch (c)
        {
            case CHAR_ESC:
                bQuit = true;
            break;

            case CHAR_SHARP:
                new_string(chaine_a_chiffrer, chaine_chiffree, p_length, p_offset);
            break;

            case CHAR_PLUS:
                offset++;
                offset %= 26;
                refresh_screen(chaine_a_chiffrer, chaine_chiffree, p_length, p_offset);
            break;

            case CHAR_MINUS:
                offset--;
                offset %= 26;
                refresh_screen(chaine_a_chiffrer, chaine_chiffree, p_length, p_offset);
            break;

            default:
            break;
        }
    } while (false == bQuit);


    return EXIT_SUCCESS;
}
