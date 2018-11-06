/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdlib.h>
#include <stdio.h>
#if defined( USE_SDL2 )
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#endif

#include "option.h"
#include "saisie.h"
#include "musique.h"

#define CHOIX_UNDERTALE      1
#define CHOIX_RUDE           2
#define CHOIX_PIXEL          3
#define CHOIX_INNOCENT       4
#define CHOIX_QUITTER        5

int option(void)
{
  BOOL b_Quitter = FALSE;
  do
  {
#ifndef DEBUG
    efface_ecran();
#endif
    fprintf(stdout, "\n\t\t=== Oss Sans Baguette ===\n\n");
    fprintf(stdout, "\n\t === SECRET OPTION ====\n");
    switch (menu_option())
    {
      case CHOIX_UNDERTALE:
      case CHOIX_INNOCENT:
      case CHOIX_RUDE:
      case CHOIX_PIXEL:
        sprintf(MP3_FULL_NAME, "../sound/undertale.mp3");
        music_init();
        break;
/*
      case CHOIX_RUDE:
        sprintf(MP3_FULL_NAME, "../sound/rude.mp3");
        music_init();
        break;

      case CHOIX_PIXEL:
        sprintf(MP3_FULL_NAME, "../sound/anthem.mp3");
        music_init();
        break;

      case CHOIX_INNOCENT:
        sprintf(MP3_FULL_NAME, "../sound/innocent.mp3");
        music_init();
        break;
*/
      case CHOIX_QUITTER: 
        b_Quitter = TRUE;
        break;

    }
  } while ( FALSE == b_Quitter );

  return EXIT_SUCCESS;
}
