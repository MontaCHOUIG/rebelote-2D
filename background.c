#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "background.h"

void initBack(background *b)
{
	b->url="level1.png";
	b->back=IMG_Load(b->url);
	if(b->back==NULL)
	{
		printf("Unable to load background image %s \n",SDL_GetError());
		return;
	}
	b->pos_back_ecran.x=10;
	b->pos_back_ecran.y=-5;
	b->pos_back_affiche.x=0;
	b->pos_back_affiche.y=0;
	b->pos_back_affiche.h=SCREEN_H;
	b->pos_back_affiche.w=SCREEN_W;

	b->camera_pos.x=0;
	b->camera_pos.y=0;
	b->camera_pos.w=SCREEN_W;
	b->camera_pos.h=SCREEN_H;

}
void afficherBack(SDL_Surface *screen,background b)
{
	SDL_BlitSurface(b.back,&b.pos_back_affiche,screen,&b.pos_back_ecran);
}
void libererBack(background *b)
{
	SDL_FreeSurface(b->back);
}






void intialiser_texte(texte *txte)
{
	TTF_Init();
	txte->police=TTF_OpenFont("Getrok.ttf",30);
	txte->color_txt.r=255;
	txte->color_txt.g=255;
	txte->color_txt.b=255;

	txte->pos_txt.x=250;
	txte->pos_txt.y=10;
}
void afficher_texte(SDL_Surface *screen,texte txte)
{
	txte.txt=TTF_RenderText_Blended(txte.police,"Level 1",txte.color_txt);
	SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);
}
void liberer_texte(texte txte)
{
	TTF_CloseFont(txte.police);
	TTF_Quit();
}


void scrolling(background* b, int direction, int pas)
{
    switch(direction)
    {
        case 1: 
            b->camera_pos.x += pas;
            break;
        case 2: 
            b->camera_pos.x -= pas;
            break;
        
    }

    
    if(b->camera_pos.x < 0)
        b->camera_pos.x = 0;
    if(b->camera_pos.y < 0)
        b->camera_pos.y = 0;
    if(b->camera_pos.x + b->camera_pos.w > b->back->w)
        b->camera_pos.x = b->back->w - b->camera_pos.w;
    if(b->camera_pos.y + b->camera_pos.h > b->back->h)
        b->camera_pos.y = b->back->h - b->camera_pos.h;

    
    b->pos_back_affiche.x = b->camera_pos.x;
    b->pos_back_affiche.y = b->camera_pos.y;
}









void initialiser_coeur1(NombreDeVie *c)
{
	c->coeur=IMG_Load("coeur.png");
	if(c->coeur==NULL)
	{
		printf("Unable to load background image %s \n",SDL_GetError());
		return;
	}
	c->pos_coeur.x = -390;
	c->pos_coeur.y = -335;
	c->pos_coeur.h = SCREEN_H;
	c->pos_coeur.w = SCREEN_W;
}
void afficher_coeur1(SDL_Surface *screen,NombreDeVie c)
{
	SDL_BlitSurface(c.coeur,NULL,screen,&c.pos_coeur);
}

void liberer_coeur1(NombreDeVie *c)
{
	SDL_FreeSurface(c->coeur);
}

void initialiser_coeur2(NombreDeVie *c)
{
	c->coeur=IMG_Load("coeur.png");
	if(c->coeur==NULL)
	{
		printf("Unable to load background image %s \n",SDL_GetError());
		return;
	}
	c->pos_coeur.x = -355;
	c->pos_coeur.y = -335;
	c->pos_coeur.h = SCREEN_H;
	c->pos_coeur.w = SCREEN_W;
}
void afficher_coeur2(SDL_Surface *screen,NombreDeVie c)
{
	SDL_BlitSurface(c.coeur,NULL,screen,&c.pos_coeur);
}
void liberer_coeur2(NombreDeVie *c)
{
	SDL_FreeSurface(c->coeur);
}
void initialiser_coeur3(NombreDeVie *c)
{
	c->coeur=IMG_Load("coeur.png");
	if(c->coeur==NULL)
	{
		printf("Unable to load background image %s \n",SDL_GetError());
		return;
	}
	c->pos_coeur.x = -320;
	c->pos_coeur.y = -335;
	c->pos_coeur.h = SCREEN_H;
	c->pos_coeur.w = SCREEN_W;
}
void afficher_coeur3(SDL_Surface *screen,NombreDeVie c)
{
	SDL_BlitSurface(c.coeur,NULL,screen,&c.pos_coeur);
}
void liberer_coeur3(NombreDeVie *c)
{
	SDL_FreeSurface(c->coeur);
}
void initialiser_coeur11(NombreDeVie *c)
{
	c->coeur=IMG_Load("coeurgris.png");
	if(c->coeur==NULL)
	{
	printf("Unable to load background image %s \n",SDL_GetError());
	return;
	}
	c->pos_coeur.x = -390;
	c->pos_coeur.y = -335;
	c->pos_coeur.h = SCREEN_H;
	c->pos_coeur.w = SCREEN_W;
}
void afficher_coeur11(SDL_Surface *screen,NombreDeVie c)
{
	SDL_BlitSurface(c.coeur,NULL,screen,&c.pos_coeur);
}
void liberer_coeur11(NombreDeVie *c)
{
	SDL_FreeSurface(c->coeur);
}
void initialiser_coeur22(NombreDeVie *c)
{
	c->coeur=IMG_Load("coeurgris.png");
	if(c->coeur==NULL)
	{
		printf("Unable to load background image %s \n",SDL_GetError());
		return;
	}
	c->pos_coeur.x = -355;
	c->pos_coeur.y = -335;
	c->pos_coeur.h = SCREEN_H;
	c->pos_coeur.w = SCREEN_W;
}
void afficher_coeur22(SDL_Surface *screen,NombreDeVie c)
{
	SDL_BlitSurface(c.coeur,NULL,screen,&c.pos_coeur);
}
void liberer_coeur22(NombreDeVie *c)
{
	SDL_FreeSurface(c->coeur);
}
void initialiser_coeur33(NombreDeVie *c)
{
	c->coeur=IMG_Load("coeurgris.png");
	if(c->coeur==NULL)
	{
		printf("Unable to load background image %s \n",SDL_GetError());
		return;
	}
	c->pos_coeur.x = -320;
	c->pos_coeur.y = -335;
	c->pos_coeur.h = SCREEN_H;
	c->pos_coeur.w = SCREEN_W;
}
void afficher_coeur33(SDL_Surface *screen,NombreDeVie c)
{
	SDL_BlitSurface(c.coeur,NULL,screen,&c.pos_coeur);
}
void liberer_coeur33(NombreDeVie *c)
{
	SDL_FreeSurface(c->coeur);
}


 
void initialiser_score(scoreinfo* score)
{
    score->score = 0;
    score->temps = 0;
    strcpy(score->playername, "Player ");
}

void augmenter_score(scoreinfo *score)
{
    score->score += 50;
}
void afficher_score(SDL_Surface* screen, TTF_Font* police, scoreinfo* score)
{
    char score_str[50];
    SDL_Color couleur = {0, 0, 0};  
    SDL_Rect pos_score;
   

    sprintf(score_str, "Score:%d", score->score);
    
    SDL_Surface* surface_score = TTF_RenderText_Solid(police, score_str, couleur);
    
   
    pos_score.x = screen->w - surface_score->w - 40;
    pos_score.y = 10;

    SDL_BlitSurface(surface_score, NULL, screen, &pos_score);

    SDL_FreeSurface(surface_score);
}


void enregistrer_scores(scoreinfo* score, char* filename)
{
    FILE* fichier = fopen(filename, "a+");

    if (fichier != NULL) 
    {
        fprintf(fichier, "%s %d %d\n", score->playername, score->score, score->temps);
        fclose(fichier);
    }
}

void bestScore(char *filename, scoreinfo t[]) {

    FILE *fichier = fopen(filename, "r");
    if (fichier == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier");
    }

    int i = 0;
    while (fscanf(fichier, "%s %d %d ", t[i].playername, &t[i].score, &t[i].temps) != EOF) {
        i++;
    }
    fclose(fichier);

    int n = i;
    int j;
    scoreinfo tmp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {

            if (t[i].score == t[j].score) {
                if (t[i].temps > t[j].temps) {
                    tmp = t[i];
                    t[i] = t[j];
                    t[j] = tmp;
                }
            } else if (t[i].score < t[j].score) {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

void afficherBest(SDL_Surface* ecran, scoreinfo t[]) {
    SDL_Color textColor = {0, 0, 0}; // Couleur du texte en blanc
    TTF_Font* font = TTF_OpenFont("Virgo.ttf", 24); // Police de caractères
    
    if (!font) {
        printf("Erreur chargement de la police : %s\n", TTF_GetError());
        return;
    }

    SDL_Surface* textSurface = NULL;
    char bestScore[100];
    sprintf(bestScore, "Best Score: %d", t[0].score); // Formater le texte du meilleur score

    textSurface = TTF_RenderText_Solid(font, bestScore, textColor); // Créer une surface de texte

    if (!textSurface) {
        printf("Erreur création de la surface de texte : %s\n", TTF_GetError());
        return;
    }

    // Calculer les coordonnées du point de départ pour afficher le texte au milieu de l'écran
    int x = (SCREEN_W - textSurface->w) / 2;
    int y = (SCREEN_H - textSurface->h) / 2;

    SDL_Rect textLocation = {x, y, 0, 0}; // Position du texte sur l'écran

    SDL_BlitSurface(textSurface, NULL, ecran, &textLocation); // Dessiner le texte sur l'écran
    SDL_FreeSurface(textSurface); // Libérer la surface de texte
    TTF_CloseFont(font); // Fermer la police de caractères
}







