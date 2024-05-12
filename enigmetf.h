#ifndef ENIGMETF_H_INCLUDED
#define ENIGMETF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#define TEMPS_LIMITE 60000 // Example time limit in milliseconds


typedef struct {
    SDL_Surface *background; 
    SDL_Surface *question; 
    SDL_Surface *reponses[4]; 
    SDL_Surface *button; 
    SDL_Surface *button_s; 

    int pos_selected; 
    SDL_Rect pos_question; 
    SDL_Rect pos_reponse1; 
    SDL_Rect pos_reponse2; 
    SDL_Rect pos_reponse3; 
    int num_question; 

    SDL_Rect pos_reponse1txt; 
    SDL_Rect pos_reponse2txt; 
    SDL_Rect pos_reponse3txt; 
    int vrai_reponse; 
    int positionVraiReponse; 
    TTF_Font *police; 
    TTF_Font *police1; 

    SDL_Surface *image_clock; 
    SDL_Rect pos_image_clock; 

    SDL_Rect single_Clock;
    int clock_num; 
} enigmetf;


void InitEnigme(enigmetf *enigme, char nomfichier[]);


void afficherEnigme(enigmetf e, SDL_Surface *ecran);


void displayClock(enigmetf e, SDL_Surface *ecran);


void animer(enigmetf *e);


void free_Surface_enigme(enigmetf e);


void runEnigmeGame(enigmetf enigme, SDL_Surface* ecran, SDL_Surface* result, SDL_Surface* win, SDL_Surface* lost, SDL_Rect pos_result, SDL_Rect pos, Uint32 start_time);


#endif

