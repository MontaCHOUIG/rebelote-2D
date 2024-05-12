#ifndef ES_H_INCLUDED
#define ES_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"
#include "background.h"
typedef struct 
{
	SDL_Rect pos;
	SDL_Surface* enem[17];
	int d,num;
	
}Ennemi;

typedef struct {
    float x;
    float y;
    float radius;
} Circle;


typedef struct Coeur
{
    SDL_Surface *image;
    SDL_Rect position;
    int visible;
} Coeur;

typedef struct {
    float x;
    float y;
    float width;
    float height;
} Rectangle;
 


void initEnnemi(Ennemi*e );
void afficherEnnemi(Ennemi e, SDL_Surface *screen);
void animerEnnemi( Ennemi * e,SDL_Surface *screen);
void deplacer( Ennemi * e);
int collisionBB(personne p,Ennemi e);
void initCoeurs(Coeur coeurs[]);
void afficherCoeurs(Coeur coeurs[], SDL_Surface *screen);
int collisionTri(personne p, Coeur coeur);
void deplacerIA(Ennemi *e,personne p );








#endif // ES_H_INCLUDED

