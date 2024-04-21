#ifndef IMAGE_H
#define IMAGE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define SCREEN_W 1600
#define SCREEN_H 800

typedef struct {
    SDL_Rect pos1;      // Position de l'image sur l'écran
    SDL_Rect pos2;      // Partie de l'image à afficher
    SDL_Surface* img;
}image;

typedef struct {

	SDL_Surface * text ;
	SDL_Rect postext;

}texte;

typedef struct {

SDL_Surface * boutonpressed;
SDL_Surface * boutonnonpressed;
SDL_Rect posbouton ;

}bouton;



void initbackground(image* a);
void initbackgroundsettings(image* a);
void afficher(image a, SDL_Surface* screen);
void initplay(bouton * a );
void initcredits(bouton * a);
void initsettings(bouton * a);
void initquit(bouton * a);
void initcomingsoon(image* a);
void liberermenu(image a , bouton b , bouton c , bouton d , bouton e );
void afficherbouton(bouton * a , SDL_Surface *screen);
void afficherboutonpressed(bouton * a , SDL_Surface * screen);
void inittext(texte t[]);
void initboutonssettings(bouton* a , bouton *b , bouton *c , bouton *d , bouton *e , bouton * f, bouton * g);
void initcreditsbackground(image * a , SDL_Surface * screen);
void libererimage(image a );
void initring(image * a1 , image * a2 , image * a3);
void libererring(image a1 , image a2 , image a3);


#endif /* IMAGE_H */

