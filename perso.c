#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include "image.h"
#include "perso.h"
#define MAX_HORIZONTAL_JUMP_DISTANCE 200 // Adjust this value as needed

void init(bouton  *a , bouton  * b )
{
    a->boutonnonpressed = IMG_Load("boutonperso1.jpg");
    a->boutonpressed = IMG_Load("boutonperso1.jpg");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->posbouton.x = 100;
    a->posbouton.y = 400;

    b->boutonnonpressed = IMG_Load("boutonperso2.jpg");
    b->boutonpressed = IMG_Load("boutonperso2.jpg");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    b->posbouton.x = 800;
    b->posbouton.y = 400;




}

void initperso(personne * p1 , personne * p2 )
{
		
	
	p1->spritesheet = IMG_Load("spriteperso.png");
    if (p1->spritesheet== NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    p1->pos1.x = 0;
    p1->pos1.y = 500;
    p1->pos2.x = 0;
    p1->pos2.y = 200;
    p1->pos2.w = 150;
    p1->pos2.h = 190; 

    p1->acceleration = 0;
    p1->vitesse = 0;
    p1->vitesse_saut = 0.1;

    p1->up = 0;
    p2->up = 0;

	p2->spritesheet = IMG_Load("spritetest.jpg");
    if (p2->spritesheet == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    p2->pos1.x = 0;
    p2->pos1.y = 500;
    p2->pos2.x = 0;
    p2->pos2.y = 0;
    p2->pos2.w = 112.5;
    p2->pos2.h = 200; 
    
   // p->health = 100 ;  //
    //p->score = 0;  // A developper
    p2->acceleration = 0;
    p2->vitesse = 0;

    p1->vitesse_x = 0;
    p1->vitesse_y = 0;


}

void afficherperso(personne * p , SDL_Surface *screen)
{
	SDL_BlitSurface(p->spritesheet,&(p->pos2),screen,&(p->pos1)); // pos2 IDLE 
	//SDL_BlitSurface(p->healthbar,&(p->pos2),screen,&(p->pos1)); // pos2 IDLE 	
	//SDL_BlitSurface(p->cadrehealthbar,&(p->pos2),screen,&(p->pos1)); // pos2 IDLE 

	

}

void movePerso(personne *p, Uint32 dt) {
    
    double maxAcceleration = 0.05; 
    if (p->acceleration > maxAcceleration) {
        p->acceleration = maxAcceleration;
    } else if (p->acceleration < -maxAcceleration) {
        p->acceleration = -maxAcceleration;
    }

    p->vitesse += p->acceleration * dt;

    double maxVelocity = 0.5;
    if (p->vitesse > maxVelocity) {
        p->vitesse = maxVelocity;
    } else if (p->vitesse < -maxVelocity) {
        p->vitesse = -maxVelocity;
    }

    p->pos1.x += p->vitesse * dt + 0.5 * p->acceleration * dt * dt;

    double friction = 0.001; 
    if (p->direction == 0) {
        if (p->vitesse > 0) {
            p->vitesse -= friction * dt;
            if (p->vitesse < 0) p->vitesse = 0; 
        } else if (p->vitesse < 0) {
            p->vitesse += friction * dt;
            if (p->vitesse > 0) p->vitesse = 0; 
        }
    }
}

void animerPerso(personne *p)
{

    if (p->direction == 0)
    {
        return ;
    }
    p->pos2.y = p->direction * p->pos2.h;

     

    if (p->pos2.x >= 450 - p->pos2.w) {
        p->pos2.x = 0;
    } else {
        p->pos2.x += p->pos2.w;
    }
    
}

void saut(personne *p, Uint32 dt, int *posinit) {
    static double jumpHeight = 2.0; // Adjust jump height as needed
    static double gravity = 0.01;   // Adjust gravity for desired jump behavior

    if (*posinit == 1 && p->up == 1) {
        p->vitesse_y = jumpHeight;
        p->up = 1;
        *posinit = 0;
    }

    if (p->up == 1) {
        p->pos1.y -= p->vitesse_y * dt; // Move character up
        p->vitesse_y -= gravity * dt;    // Apply gravity
    }

    if (p->pos1.y >= 500) { // Reached ground level
        p->pos1.y = 500;
        p->vitesse_y = 0;
        p->up = 0; // Reset jump flag
        *posinit = 1; // Update posinit to indicate character landed on the ground
    }
}







void freeperso(personne  p , personne  p1 , bouton a , bouton b )
{
    SDL_FreeSurface(p.spritesheet);
    SDL_FreeSurface(p1.spritesheet);
    SDL_FreeSurface(a.boutonnonpressed);
    SDL_FreeSurface(a.boutonnonpressed);
    SDL_FreeSurface(b.boutonnonpressed);
    SDL_FreeSurface(b.boutonpressed);

}