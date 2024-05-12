#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_rotozoom.h>
#include <math.h>
#include <limits.h>
#include "tictactoe.h"
void initialisation(tic * t)
{
    int i;
    for(i=0;i<9;i++)
       t-> tabsuivi[i]=0;
    t->image1=SDL_LoadBMP("fond.bmp");
    t->image2=SDL_LoadBMP("croix.bmp");
    t->image3=SDL_LoadBMP("rond.bmp");
    t->joueur=1;
    t->tour=0;
    t->angelina=TTF_OpenFont("angelina.ttf",55);
    t->couleur.r=0;
    t->couleur.g=0;
    t->couleur.b=0;
    t->posMSG.x=210;
    t->posMSG.y=250;
}


void affichage(tic t,SDL_Surface *ecran ) 
{
    int i;

    SDL_BlitSurface(t.image1,NULL,ecran,NULL);
    for(i=0;i<9;i++)
   {
		t.pos.x=190*(i%3);
		t.pos.y=190*(i/3);
        	switch(t.tabsuivi[i]) 
        	{
            		case -1:
                		SDL_BlitSurface(t.image2,NULL,ecran,&t.pos);	
            		break;
            		case 1:
                		SDL_BlitSurface(t.image3,NULL,ecran,&t.pos);
            		break;
        	}
	
    }
    
}


void Resultat (tic t,SDL_Surface* ecran)
{
SDL_Rect pos;
char msg[20];

    SDL_FillRect(ecran,0,SDL_MapRGB(ecran->format,255,255,255));
    pos.x=0;
    pos.y=0;
affichage(t,ecran);
    switch(atilganer(t.tabsuivi))
    {
        case 0:
            strcpy(msg, "NUL");
        break;
        case 1:
            strcpy(msg, "Defaite");
        break;
        case -1:  
            strcpy(msg, "Victoire");
    }

 SDL_BlitSurface(TTF_RenderText_Solid(t.angelina,msg,t.couleur),NULL,ecran,&t.posMSG);
 SDL_Flip(ecran);
    SDL_Delay(4028);
    
}

void liberationmemoire(tic t)
{
    SDL_FreeSurface(t.image1);
    SDL_FreeSurface(t.image2);
    SDL_FreeSurface(t.image3);
}



int atilganer(int tabsuivi[])
{

    int lignes_gagnantes[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i=0;i<8;++i)
        if(tabsuivi[lignes_gagnantes[i][0]]!=0&&
           tabsuivi[lignes_gagnantes[i][0]]==tabsuivi[lignes_gagnantes[i][1]]&&
           tabsuivi[lignes_gagnantes[i][0]]==tabsuivi[lignes_gagnantes[i][2]])
                return tabsuivi[lignes_gagnantes[i][2]];
    return 0;
}


int minimax(int tabsuivi[],int joueur)
{
    int gagnant=atilganer(tabsuivi);
    if(gagnant!=0)
        return gagnant*joueur;
    int coup=-1;
    int score=-2;
    int i;
    for(i=0;i<9;++i)
    {
        if(tabsuivi[i]==0)
        {
            tabsuivi[i]=joueur;
            int mmscore=-minimax(tabsuivi,joueur*-1);
            if(mmscore>score)
            {
                score=mmscore;
                coup=i;
            }
            tabsuivi[i]=0;
        }
    }
    if(coup==-1)
        return 0;
    return score;
}



void calcul_coup(int tabsuivi[])
{
    int coup=-1;
    int score=-2;
    int i;
    for(i=0;i<9;++i)
    {
        if(tabsuivi[i]==0)
        {
            tabsuivi[i]=1;
            int mmscore=-minimax(tabsuivi,-1);
            tabsuivi[i]=0;
            if(mmscore>score)
            {
                score=mmscore;
                coup=i;
            }
        }
    }
    tabsuivi[coup]=1;
}
void Rotozoom(SDL_Surface *ecran)

{

    SDL_Surface *loaded_image = IMG_Load("good.png");

    SDL_Surface *optimized_image = NULL;

    SDL_Surface *background = NULL;

        Uint32 start_time = SDL_GetTicks();



    if (loaded_image != NULL)

    {

        optimized_image = SDL_DisplayFormatAlpha(loaded_image);

        SDL_FreeSurface(loaded_image);

    }



    background = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA, ecran->w, ecran->h, ecran->format->BitsPerPixel,

                                       ecran->format->Rmask, ecran->format->Gmask, ecran->format->Bmask, ecran->format->Amask);

    SDL_FillRect(background, NULL, SDL_MapRGBA(background->format, 0, 0, 0, 0));



    if (optimized_image != NULL)

    {

        SDL_Rect dstrect;

        dstrect.w = optimized_image->w;

        dstrect.h = optimized_image->h;

        dstrect.x =0;

        dstrect.y =0;



        double angle = 0;

        double zoom = 1;

        double rotation_speed = 1;

        double zoom_speed = 0.01;

        SDL_Event event;

        int quit = 0;



        while (!quit)

        {

     

            while (SDL_PollEvent(&event))

            {

                if (event.type == SDL_QUIT)

                {

                    quit = 1;

                }

            }



            angle += rotation_speed;

            zoom += zoom_speed;





            SDL_BlitSurface(background, &dstrect, ecran, &dstrect);





            SDL_Surface *rotozoomed_image = rotozoomSurface(optimized_image, angle, zoom, SMOOTHING_ON);

            SDL_Rect image_rect = {0, 0, rotozoomed_image->w, rotozoomed_image->h};





            SDL_SetAlpha(rotozoomed_image, SDL_SRCALPHA, 128);

            SDL_BlitSurface(rotozoomed_image, &image_rect, ecran, &dstrect);



            SDL_FreeSurface(rotozoomed_image);



            SDL_Flip(ecran);

            SDL_Delay(10);

            if (SDL_GetTicks() - start_time >=10000)

            {

                quit = 1;

            }



        }

       

        SDL_FreeSurface(optimized_image);

    }



    SDL_FreeSurface(background);

}
void Rotozoom2(SDL_Surface *ecran)

{

    SDL_Surface *loaded_image = IMG_Load("wrong.png");

    SDL_Surface *optimized_image = NULL;

    SDL_Surface *background = NULL;

        Uint32 start_time = SDL_GetTicks();



    if (loaded_image != NULL)

    {

        optimized_image = SDL_DisplayFormatAlpha(loaded_image);

        SDL_FreeSurface(loaded_image);

    }



    background = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA, ecran->w, ecran->h, ecran->format->BitsPerPixel,

                                       ecran->format->Rmask, ecran->format->Gmask, ecran->format->Bmask, ecran->format->Amask);

    SDL_FillRect(background, NULL, SDL_MapRGBA(background->format, 0, 0, 0, 0));



    if (optimized_image != NULL)

    {

        SDL_Rect dstrect;

        dstrect.w = optimized_image->w;

        dstrect.h = optimized_image->h;

        dstrect.x =0;

        dstrect.y =0;



        double angle = 0;

        double zoom = 1;

        double rotation_speed = 1;

        double zoom_speed = 0.01;

        SDL_Event event;

        int quit = 0;



        while (!quit)

        {

     

            while (SDL_PollEvent(&event))

            {

                if (event.type == SDL_QUIT)

                {

                    quit = 1;

                }

            }



            angle += rotation_speed;

            zoom += zoom_speed;





            SDL_BlitSurface(background, &dstrect, ecran, &dstrect);





            SDL_Surface *rotozoomed_image = rotozoomSurface(optimized_image, angle, zoom, SMOOTHING_ON);

            SDL_Rect image_rect = {0, 0, rotozoomed_image->w, rotozoomed_image->h};





            SDL_SetAlpha(rotozoomed_image, SDL_SRCALPHA, 128);

            SDL_BlitSurface(rotozoomed_image, &image_rect, ecran, &dstrect);



            SDL_FreeSurface(rotozoomed_image);



            SDL_Flip(ecran);

            SDL_Delay(10);

            if (SDL_GetTicks() - start_time >=10000)

            {

                quit = 1;

            }



        }

       

        SDL_FreeSurface(optimized_image);

    }



    SDL_FreeSurface(background);

}



void Rotozoom3(SDL_Surface *ecran)

{

    SDL_Surface *loaded_image = IMG_Load("draw.png");

    SDL_Surface *optimized_image = NULL;

    SDL_Surface *background = NULL;

        Uint32 start_time = SDL_GetTicks();



    if (loaded_image != NULL)

    {

        optimized_image = SDL_DisplayFormatAlpha(loaded_image);

        SDL_FreeSurface(loaded_image);

    }



    background = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA, ecran->w, ecran->h, ecran->format->BitsPerPixel,

                                       ecran->format->Rmask, ecran->format->Gmask, ecran->format->Bmask, ecran->format->Amask);

    SDL_FillRect(background, NULL, SDL_MapRGBA(background->format, 0, 0, 0, 0));



    if (optimized_image != NULL)

    {

        SDL_Rect dstrect;

        dstrect.w = optimized_image->w;

        dstrect.h = optimized_image->h;

        dstrect.x =0;

        dstrect.y =0;



        double angle = 0;

        double zoom = 1;

        double rotation_speed = 1;

        double zoom_speed = 0.01;

        SDL_Event event;

        int quit = 0;



        while (!quit)

        {

     

            while (SDL_PollEvent(&event))

            {

                if (event.type == SDL_QUIT)

                {

                    quit = 1;

                }

            }



            angle += rotation_speed;

            zoom += zoom_speed;





            SDL_BlitSurface(background, &dstrect, ecran, &dstrect);





            SDL_Surface *rotozoomed_image = rotozoomSurface(optimized_image, angle, zoom, SMOOTHING_ON);

            SDL_Rect image_rect = {0, 0, rotozoomed_image->w, rotozoomed_image->h};





            SDL_SetAlpha(rotozoomed_image, SDL_SRCALPHA, 128);

            SDL_BlitSurface(rotozoomed_image, &image_rect, ecran, &dstrect);



            SDL_FreeSurface(rotozoomed_image);



            SDL_Flip(ecran);

            SDL_Delay(10);

            if (SDL_GetTicks() - start_time >=10000)

            {

                quit = 1;

            }



        }

       

        SDL_FreeSurface(optimized_image);

    }



    SDL_FreeSurface(background);

}

void animation(SDL_Surface* ecran){

SDL_Rect pos;
pos.x=0;
pos.y=10;
SDL_Surface *anim = NULL;
anim=IMG_Load("star.jpg");
SDL_BlitSurface(anim,NULL,ecran,&pos);
pos.x=pos.x+10;
if(pos.x<541){
pos.x=pos.x+10;
}

SDL_Flip(ecran);

}
void animation2(SDL_Surface* ecran){

SDL_Rect pos;
pos.x=0;
pos.y=10;
SDL_Surface *anim = NULL;
anim=IMG_Load("star.jpg");
SDL_BlitSurface(anim,NULL,ecran,&pos);
pos.x=pos.x+10;
if(pos.x<541){
pos.x=pos.x+10;
}

SDL_Flip(ecran);

}
void animation3(SDL_Surface* ecran){

SDL_Rect pos;
pos.x=0;
pos.y=10;
SDL_Surface *anim = NULL;
anim=IMG_Load("star.jpg");
SDL_BlitSurface(anim,NULL,ecran,&pos);
pos.x=pos.x+10;
if(pos.x<541){
pos.x=pos.x+10;
}

SDL_Flip(ecran);

}
void animation4(SDL_Surface* ecran){

SDL_Rect pos;
pos.x=0;
pos.y=10;
SDL_Surface *anim = NULL;
anim=IMG_Load("star.jpg");
SDL_BlitSurface(anim,NULL,ecran,&pos);
pos.x=pos.x+10;
if(pos.x<541){
pos.x=pos.x+10;
}

SDL_Flip(ecran);

}


void Ticgame(SDL_Surface * ecran){

    SDL_Event event;

  for (int partie = 0; partie < 3; partie++) 
    {
        int a, p;
        int coup;
        int contin = 1; 
        int joueur;
        tic t;

        initialisation(&t);
	
        while (contin)
        {
            affichage(t, ecran);

            SDL_Flip(ecran);

            animation(ecran);
            animation2(ecran);
            animation3(ecran);
            animation4(ecran);

           
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    contin = 0;
                }
                else if (event.type == SDL_MOUSEBUTTONUP)
                {
                    
                    a = event.button.x / 190;
                    p = event.button.y / 190;
                    coup = 3 * p + a;
                    if (t.tabsuivi[coup] == 0)
                    {
                        t.tabsuivi[coup] = -1;
                        t.tour++;
                    }
                }
                else if (event.type == SDL_KEYDOWN)
                {
                   
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            contin = 0;
                            break;
                        case SDLK_KP0:
                        case SDLK_0:
                            
                            if (t.tour % 2 == 0 && t.tabsuivi[0] == 0)
                            {
                                t.tabsuivi[0] = -1;
                                t.tour++;
                            }
                            break;
                        case SDLK_KP1:
                        case SDLK_1:
                           
                            if (t.tour % 2 == 0 && t.tabsuivi[1] == 0)
                            {
                                t.tabsuivi[1] = -1;
                                t.tour++;
                            }
                            break;
                       
                        case SDLK_KP2:
                        case SDLK_2:
                            
                            if (t.tour % 2 == 0 && t.tabsuivi[2] == 0)
                            {
                                t.tabsuivi[2] = -1;
                                t.tour++;
                            }
                            break;
                        case SDLK_KP3:
                        case SDLK_3:
                           
                            if (t.tour % 2 == 0 && t.tabsuivi[3] == 0)
                            {
                                t.tabsuivi[3] = -1;
                                t.tour++;
                            }
                            break;
                        
                        case SDLK_KP4:
                        case SDLK_4:
                         
                            if (t.tour % 2 == 0 && t.tabsuivi[4] == 0)
                            {
                                t.tabsuivi[4] = -1;
                                t.tour++;
                            }
                            break;
                        case SDLK_KP5:
                        case SDLK_5:
                            
                            if (t.tour % 2 == 0 && t.tabsuivi[5] == 0)
                            {
                                t.tabsuivi[5] = -1;
                                t.tour++;
                            }
                            break;
                        case SDLK_KP6:
                        case SDLK_6:
                           
                            if (t.tour % 2 == 0 && t.tabsuivi[6] == 0)
                            {
                                t.tabsuivi[6] = -1;
                                t.tour++;
                            }
                            break;
                        case SDLK_KP7:
                        case SDLK_7:
                     
                            if (t.tour % 2 == 0 && t.tabsuivi[7] == 0)
                            {
                                t.tabsuivi[7] = -1;
                                t.tour++;
                            }
                            break;
                        case SDLK_KP8:
                        case SDLK_8:
                            
                            if (t.tour % 2 == 0 && t.tabsuivi[8] == 0)
                            {
                                t.tabsuivi[8] = -1;
                                t.tour++;
                            }
                            break;
                    }
                }
            }

   
            if (t.tour >= 9 || atilganer(t.tabsuivi) != 0)
            {
                Resultat(t, ecran);
                contin = 0;
                printf("%d", t.tour);
            }
            else
            {

                if (t.tour % 2 != 0)
                {

                    calcul_coup(t.tabsuivi);
                    t.tour++;
                }
            }
        }

 
        if (atilganer(t.tabsuivi) == 1)
        {
            Resultat(t, ecran);
            Rotozoom(ecran);
            printf("Player wins\n");
        }
        else if (atilganer(t.tabsuivi) == -1)
        {
            Resultat(t, ecran);
            Rotozoom2(ecran);
            printf("Pc wins\n");
        }
        else
        {
            Resultat(t, ecran);
            Rotozoom3(ecran);
            printf("It's a draw\n");
        }


        liberationmemoire(t);
    }
}