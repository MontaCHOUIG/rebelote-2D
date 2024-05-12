#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#define SCREEN_W 1600
#define SCREEN_H 800

typedef struct {
    char *url; 
    SDL_Surface *back;
    SDL_Rect pos_back_affiche;
    
    SDL_Rect pos_back_ecran;
    
    SDL_Rect camera_pos;
   
    int direction;
} background;

/*typedef struct {
    SDL_Surface **frames;  
    int num_frames;        
    int current_frame;      
    int frame_delay;        
    Uint32 last_frame_time; 
    SDL_Rect position;      
} animation;*/

typedef struct {
    SDL_Surface *txt;
    SDL_Rect pos_txt;
    SDL_Color color_txt;
    TTF_Font *police;
} texte;

typedef struct {
    int nbvies; 
    SDL_Surface* coeur;
    SDL_Rect pos_coeur;
} NombreDeVie;

typedef struct {
    int score;
    int temps;
    char playername[20];
} scoreinfo;

void initBack(background *b);
void afficherBack(SDL_Surface *screen, background b);
void libererBack(background *b);


void initialiser_musique(Mix_Music *music);
void liberer_musique(Mix_Music *music);
void intialiser_texte(texte *txte);
void afficher_texte(SDL_Surface *screen, texte txte);
void liberer_texte(texte txte);


void initialiser_score(scoreinfo* score);
TTF_Font* charger_police(char* nom_fichier, int taille_police);
void augmenter_score(scoreinfo *score);
void afficher_score(SDL_Surface* screen, TTF_Font* police, scoreinfo* score);
void enregistrer_scores(scoreinfo* score, char* filename);
void bestScore(char *filename, scoreinfo t[]);
void liberer_texte(texte txte);



void scrolling(background *b, int direction, int pas);


void afficherBackComplet(SDL_Surface *screen, background b);


/* void initialiser_animation2(animation *anim, int num_frames);
void animerBack2(animation *anim, SDL_Surface *screen);
void mise_a_jour_animation2(animation *anim, Uint32 delta_time);
void liberer_animation2(animation *anim);*/


void initialiser_coeur1(NombreDeVie *c);
void afficher_coeur1(SDL_Surface *screen, NombreDeVie c);
void liberer_coeur1(NombreDeVie *c);


void initialiser_coeur2(NombreDeVie *c);
void afficher_coeur2(SDL_Surface *screen, NombreDeVie c);
void liberer_coeur2(NombreDeVie *c);


void initialiser_coeur3(NombreDeVie *c);
void afficher_coeur3(SDL_Surface *screen, NombreDeVie c);
void liberer_coeur3(NombreDeVie *c);


void initialiser_coeur11(NombreDeVie *c);
void afficher_coeur11(SDL_Surface *screen, NombreDeVie c);
void liberer_coeur11(NombreDeVie *c);

void initialiser_coeur22(NombreDeVie *c);
void afficher_coeur22(SDL_Surface *screen, NombreDeVie c);
void liberer_coeur22(NombreDeVie *c);

void initialiser_coeur33(NombreDeVie *c);
void afficher_coeur33(SDL_Surface *screen, NombreDeVie c);
void liberer_coeur33(NombreDeVie *c);














void afficherBest(SDL_Surface* ecran, scoreinfo t[]) ;

#endif

