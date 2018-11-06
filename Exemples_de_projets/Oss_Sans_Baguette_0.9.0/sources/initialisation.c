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
#include "initialisation.h"
#include "initialize_rand.h"
#include "musique.h"
#include "donnees.h"

static short int anErr = 0;

short int initialisation(char ** argv)
{
  anErr = ouverture_base(argv);
  if ( anErr != 0 )
  {
    fprintf(stdout,"problème d'ouverture de la base de données ... terminé");
    return EXIT_FAILURE;
  }

  initialize_rand();

  /* musique de fond */
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
  myMusic = Mix_LoadMUS("../sound/undertale.mp3");
  Mix_PlayMusic(myMusic, -1);
  return EXIT_SUCCESS;
}

