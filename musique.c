#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "musique.h"

void musiquebackground(Mix_Music * musique) {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
        printf("Erreur lors de l'initialisation de SDL Mixer : %s\n", Mix_GetError());
        return;
    }

    musique = Mix_LoadMUS("rebelote.mp3");
    if (musique == NULL) {
        printf("Erreur lors du chargement du fichier audio : %s\n", Mix_GetError());
        Mix_CloseAudio();
        return;
    }

    Mix_PlayMusic(musique, -1); // boucle infinie
}


