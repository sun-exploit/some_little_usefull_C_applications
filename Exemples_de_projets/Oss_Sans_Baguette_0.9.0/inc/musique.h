/*
 * Fichier d'en tête musique.h pour le projet SDL_mp3
 * Auteur : Eric Bachard  / vendredi 27 mai 2016, 18:52:55 (UTC+0200)
 * Ce document est sous Licence GPL v2
 * voir : http://www.gnu.org/licenses/gpl-2.0.html
 */
#ifndef __MUSIQUE_H__
#define __MUSIQUE_H__

/*musique*/
Mix_Music* myMusic;
char MP3_FULL_NAME[23];
int music_init(void);

#endif /* __MUSIQUE_H__ */
