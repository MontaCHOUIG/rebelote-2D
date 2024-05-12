#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "perso.h"

typedef struct {
    SDL_Surface* mini_image;
    SDL_Rect mini_position;
    SDL_Surface* player_image;
    SDL_Rect player_position;
    SDL_Rect minimap_player_position; 
} Minimap;

typedef struct {
    TTF_Font* font;
    SDL_Surface* text_surface;
    SDL_Rect rect;
} Button;

void init_minimap(Minimap* m, personne p );
void MAJMinimap(SDL_Rect posJoueur,  Minimap * m, SDL_Rect camera, int redimensionnement);
void afficher_minimap(Minimap m, SDL_Surface* screen);
void liberer_minimap(Minimap* m);
SDL_Color GetPixel(SDL_Surface* pSurface, int x, int y);
int collisionPP(SDL_Rect player_pos, SDL_Surface* background);
void affichertemps(int temps);
void affichertempsen(Uint32 startTime);
void animerMinimap(Minimap* m);
void animerMinimape(Minimap* m);

void init_button(Button* btn, const char* text, int x, int y);
void draw_button(Button btn, SDL_Surface* screen);
int is_button_pressed(int x, int y, Button btn);
void destroy_button(Button* btn);

#endif

