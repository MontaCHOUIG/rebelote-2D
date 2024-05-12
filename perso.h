#ifndef PERSO_H
#define PERSO_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"


typedef struct {

	SDL_Rect pos1;      // Position de l'image sur l'écran
	SDL_Rect pos2;      // Partie de l'image à afficher
    SDL_Surface* spritesheet;
	int direction;
	double acceleration;
	double vitesse;
	double vitesse_saut;
	int scoreperso;
	int up;
	double vitesse_x;
	double vitesse_y;
	int ID ;


}personne;








 	void init(bouton  *a , bouton  * b , image * c , image * d );

	void initperso(personne * p1 , personne * p2 );
	void afficherperso(personne * p , SDL_Surface *screen);
	void movePerso(personne *p, Uint32 dt);

    void animerPerso(personne *p);
 	void saut(personne *p, Uint32 dt, int * posinit);
    void freeperso(personne  p , personne  p1 , bouton a , bouton b );



	
#endif 