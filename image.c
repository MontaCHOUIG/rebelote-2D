#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "image.h"





void initbackground(image* a) {
    a->img = IMG_Load("eljem.jpg");
    if (a->img == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->pos1.x = 0;
    a->pos1.y = 0;
    a->pos2.x = 0;
    a->pos2.y = 0;
    a->pos2.w = SCREEN_W;
    a->pos2.h = SCREEN_H;
}
void initbackgroundsettings(image* a) {
    a->img = IMG_Load("backsettings.jpg");
    if (a->img == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->pos1.x = 0;
    a->pos1.y = 0;
    a->pos2.x = 0;
    a->pos2.y = 0;
    a->pos2.w = SCREEN_W;
    a->pos2.h = SCREEN_H;
}

void initsettings(bouton * a) {
    a->boutonnonpressed = IMG_Load("setting_not_pressed.png");
    a->boutonpressed = IMG_Load("setting_pressed.png");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->posbouton.x = (SCREEN_W - a->boutonnonpressed->w) / 2 - 200;
    a->posbouton.y = (SCREEN_H - a->boutonnonpressed->h) / 2 + 130;
}

void initplay(bouton * a) {
    a->boutonnonpressed = IMG_Load("play_not_pressed.png");
    a->boutonpressed = IMG_Load("play_pressed.png");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->posbouton.x = (SCREEN_W - a->boutonnonpressed->w) / 2 - 200;
    a->posbouton.y = (SCREEN_H - a->boutonnonpressed->h) / 2 - 100;
}

void initcredits(bouton * a) {
    a->boutonnonpressed = IMG_Load("credits_not_pressed.png");
    a->boutonpressed = IMG_Load("credits_pressed.png");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->posbouton.x = (SCREEN_W - a->boutonnonpressed->w) / 2 - 200;
    a->posbouton.y = (SCREEN_H - a->boutonnonpressed->h) / 2 + 15;
}



void initquit(bouton * a) {
    a->boutonnonpressed = IMG_Load("quit_not_pressed.png");
    a->boutonpressed = IMG_Load("quit_pressed.png");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->posbouton.x = (SCREEN_W - a->boutonnonpressed->w) / 2 - 200;
    a->posbouton.y = (SCREEN_H - a->boutonnonpressed->h) / 2 + 245;
}

void liberermenu(image a , bouton b , bouton c , bouton d , bouton e ) {
    SDL_FreeSurface(a.img);
    SDL_FreeSurface(b.boutonpressed);
    SDL_FreeSurface(b.boutonnonpressed);
    SDL_FreeSurface(c.boutonpressed);
    SDL_FreeSurface(c.boutonnonpressed);
    SDL_FreeSurface(d.boutonpressed);
    SDL_FreeSurface(d.boutonnonpressed);
    SDL_FreeSurface(e.boutonpressed);
    SDL_FreeSurface(e.boutonnonpressed);  
    
    return;  
}


void afficher(image a, SDL_Surface* screen) {
    SDL_BlitSurface(a.img, &a.pos2, screen, &a.pos1);
}

void afficherbouton(bouton  * a , SDL_Surface *screen) {
    SDL_BlitSurface(a->boutonnonpressed, NULL , screen , &(a->posbouton));
}

void afficherboutonpressed(bouton * a , SDL_Surface * screen) {
    SDL_BlitSurface(a->boutonpressed , NULL , screen , &(a->posbouton));

}
void initcomingsoon(image* a){
	 a->img = IMG_Load("backplay.jpg");
    if (a->img == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->pos1.x = 0;
    a->pos1.y = 0;
    a->pos2.x = 0;
    a->pos2.y = 0;
    a->pos2.w = SCREEN_W;
    a->pos2.h = SCREEN_H;
	
}
void initring(image * a1 , image * a2 , image * a3)
{
	 a1->img = IMG_Load("pos1.png");
    if (a1->img == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a1->pos1.x = 850;
    a1->pos1.y = 60;
    a1->pos2.x = 0;
    a1->pos2.y = 0;
    a1->pos2.w = SCREEN_W;
    a1->pos2.h = SCREEN_H;
    
    
    	 a2->img = IMG_Load("pos2.png");
    if (a2->img == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a2->pos1.x = 850;
    a2->pos1.y = 60;
    a2->pos2.x = 0;
    a2->pos2.y = 0;
    a2->pos2.w = SCREEN_W;
    a2->pos2.h = SCREEN_H;
     
     
        a3->img = IMG_Load("pos3.png");
    if (a3->img == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a3->pos1.x = 850;
    a3->pos1.y = 60;
    a3->pos2.x = 0;
    a3->pos2.y = 0;
    a3->pos2.w = SCREEN_W;
    a3->pos2.h = SCREEN_H;
	
}
	

	





void initboutonssettings(bouton* a , bouton *b , bouton *c , bouton *d , bouton *e , bouton * f , bouton *g)
{
    a->boutonnonpressed = IMG_Load("pb_not_pressed.png");
    a->boutonpressed = IMG_Load("pb_pressed.png");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->posbouton.x = 600;
    a->posbouton.y = 200;
    
    b->boutonnonpressed = IMG_Load("mb_not_pressed.png");
    b->boutonpressed = IMG_Load("mb_pressed.png");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    b->posbouton.x = 800;
    b->posbouton.y = 240;
    
    
    c->boutonnonpressed = IMG_Load("mute_not_pressed.png");
    c->boutonpressed = IMG_Load("mute_pressed.png");
    if (a->boutonnonpressed == NULL || a->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    c->posbouton.x = 780;
    c->posbouton.y = 320;
    
    
    d->boutonnonpressed = IMG_Load("um_not_pressed.png");
    d->boutonpressed = IMG_Load("um_pressed.png");
    if (d->boutonnonpressed == NULL || d->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    d->posbouton.x = 580;
    d->posbouton.y = 320;
    
    e->boutonnonpressed = IMG_Load("hb_not_pressed.png");
    e->boutonpressed = IMG_Load("hb_pressed.png");
    if (d->boutonnonpressed == NULL || d->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    e->posbouton.x = 50;
    e->posbouton.y = 50;
    
    
    f->boutonnonpressed = IMG_Load("wd_not_pressed.png");
    f->boutonpressed = IMG_Load("wd_pressed.png");
    if (d->boutonnonpressed == NULL || d->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    f->posbouton.x = 380;
    f->posbouton.y = 500;
    
    g->boutonnonpressed = IMG_Load("fs_not_pressed.png");
    g->boutonpressed = IMG_Load("fs_pressed.png");
    if (d->boutonnonpressed == NULL || d->boutonpressed == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    g->posbouton.x = 680;
    g->posbouton.y = 500;
    




}

void initcreditsbackground(image * a , SDL_Surface * screen)
{
	



    a->img = IMG_Load("credits.jpg");
    if (a->img == NULL) {
        printf("Erreur : %s\n", SDL_GetError());
        return;
    }

    a->pos1.x = 0;
    a->pos1.y = 0;
    a->pos2.x = 0;
    a->pos2.y = 0;
    a->pos2.w = SCREEN_W;
    a->pos2.h = SCREEN_H;




}



void libererimage(image a )
{	SDL_FreeSurface(a.img);
}




void libererring(image a1 , image a2 , image a3){


	SDL_FreeSurface(a1.img);
	SDL_FreeSurface(a2.img);
	SDL_FreeSurface(a3.img);

}




