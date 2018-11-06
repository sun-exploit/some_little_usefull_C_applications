/* fichier .c (fait partie de OSS_Sans_Baguette)
 * Auteur:  BLARP  / mercredi 11 mai 2016, 07:14:11 (UTC+0200)
 * Ce document est sous Licence : GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */

#include <stdio.h>
#include <stdlib.h>
#if defined( USE_SDL2 )
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#endif
#include "musique.h"

int music_init(void)
{
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
  myMusic = Mix_LoadMUS(MP3_FULL_NAME);
  Mix_PlayMusic(myMusic, -1);
  return EXIT_SUCCESS;
}
