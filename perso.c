#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include "image.h"
#include "perso.h"

void init(bouton  *a , bouton  * b , image * c , image * d )
{
    a->boutonnonpressed = IMG_Load("boutonperso1.jpg");
    a->boutonpressed = IMG_Load("boutonperso1.jpg");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->posbouton.x = 100;
    a->posbouton.y = 500;

    b->boutonnonpressed = IMG_Load("boutonperso2.jpg");
    b->boutonpressed = IMG_Load("boutonperso2.jpg");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    b->posbouton.x = 1200;
    b->posbouton.y = 500;

    c->img = IMG_Load("spritepersoNORMALMENU.png");
    d->img = IMG_Load("spritepersoTOUNSIMENU.png");
    if (c->img == NULL || d->img == NULL) {
        printf("Erreur image MENU game : %s\n", SDL_GetError());
        return;
    }

    c->pos1.x = 200;
    c->pos1.y = 300;

    d->pos1.x = 1300;
    d->pos1.y = 300;


}

void initperso(personne * p1 , personne * p2 )
{
		
	
	p1->spritesheet = IMG_Load("spriteperso.png");
    if (p1->spritesheet== NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    p1->pos1.x = 0;
    p1->pos1.y = 700;
    p1->pos2.x = 0;
    p1->pos2.y = 200;
    p1->pos2.w = 150;
    p1->pos2.h = 195; 

    p1->acceleration = 0.001;
    p1->vitesse = 0;
    p1->vitesse_saut = 0.1;

    p1->up = 0;
    p2->up = 0;

	p2->spritesheet = IMG_Load("spritepersoTOUNSI.png");
    if (p2->spritesheet == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

   p2->pos1.x = 0;
    p2->pos1.y = 600;
    p2->pos2.x = 0;
    p2->pos2.y = 200;
    p2->pos2.w = 150;
    p2->pos2.h = 195;
    
   
    p2->acceleration = 0;
    p2->vitesse = 0;

    p1->vitesse_x = 0;
    p1->vitesse_y = 0;

    p1->ID = 1 ;
    p2->ID = 2;

}

void afficherperso(personne * p , SDL_Surface *screen)
{
	SDL_BlitSurface(p->spritesheet,&(p->pos2),screen,&(p->pos1)); // pos2 IDLE 
	
	

}
void movePerso(personne *p, Uint32 dt) {
    
    double maxAcceleration = 1; 
    if (p->acceleration > maxAcceleration) {
        p->acceleration = maxAcceleration;
    } else if (p->acceleration < -maxAcceleration) {
        p->acceleration = -maxAcceleration;
    }

    p->vitesse += p->acceleration * dt;

    double VitesseMax = 0.5;
    if (p->vitesse > VitesseMax) {
        p->vitesse = VitesseMax;
    } else if (p->vitesse < -VitesseMax) {
        p->vitesse = -VitesseMax;
    }
    
    p->pos1.x += p->vitesse * dt + 0.5 * p->acceleration * dt * dt;

    double frott = 0.001; 
    if (p->direction == 0) {
        if (p->vitesse > 0) {
            p->vitesse -= frott * dt;
            if (p->vitesse < 0) p->vitesse = 0; 
        } else if (p->vitesse < 0) {
            p->vitesse += frott * dt;
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
     double jumpHeight = 2.0; 
     double gravity = 0.01;   

    if (*posinit == 1 && p->up == 1) {
        p->vitesse_y = jumpHeight;
        p->up = 1;
        *posinit = 0;
    }

    if (p->up == 1) {
        p->pos1.y -= p->vitesse_y * dt; 
        p->vitesse_y -= gravity * dt;    
    }

    if (p->pos1.y >= 500) { 
        p->pos1.y = 500;
        p->vitesse_y = 0;
        p->up = 0; 
        *posinit = 1; 
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