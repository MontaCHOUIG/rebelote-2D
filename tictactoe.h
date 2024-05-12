#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
	int joueur;
	SDL_Surface * image1,*image2,*image3;
	int tabsuivi[9];
	SDL_Rect pos;
	int tour;
	TTF_Font *angelina;
	SDL_Color couleur;
	SDL_Rect posMSG;
}tic;

void initialisation(tic *t);
void affichage(tic t,SDL_Surface *ecran ) ;
int atilganer(int tabsuivi[]);
int minimax(int tabsuivi[],int joueur);
void calcul_coup(int tabsuivi[]);
void Resultat (tic t,SDL_Surface* ecran);
void Rotozoom(SDL_Surface *ecran);
void Rotozoom2(SDL_Surface *ecran);
void Rotozoom3(SDL_Surface *ecran);
void animation(SDL_Surface* ecran);
void animation2(SDL_Surface* ecran);
void animation3(SDL_Surface* ecran);
void animation4(SDL_Surface* ecran);
void liberationmemoire(tic t);
void Ticgame(SDL_Surface* ecran);

#endif