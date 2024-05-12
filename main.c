#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "image.h"
#include "musique.h"
#include "settings.h"
#include "perso.h"
#include "background.h"
#include "ennemy.h"
#include "enigmetf.h"
#include "minimap.h"
#include "tictactoe.h"


#define SCREEN_W 1600
#define SCREEN_H 800

int main() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0) {
        printf("Erreur d'initialisation : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    if (screen == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    
    
    

        texte txt[20];

    
	TTF_Init(); //initialisation du ttf
	TTF_Font *police1 = NULL ;
	TTF_Font *police = NULL ;
	SDL_Color black = {0, 0, 0};
	SDL_Color white = {255, 255, 255};	
    SDL_Color red = {255,0,0};
	police1 = TTF_OpenFont("police.ttf", 80); //chargement police
if (police1==NULL)
    {
        printf("police1 erreur\n");
    }
    
    police = TTF_OpenFont("bronco.ttf", 80); //chargement police
if (police==NULL)
    {
        printf("police erreur\n");
    }
    
    
    //back

    background b,backscore;
    texte text;
    int direction,pos_joueur;
    int pas_joueur=5 ; 
    NombreDeVie c1,c2,c3,c11,c22,c33;
    scoreinfo score;
    scoreinfo tab[2000];
    /*animation anim,anim2;*/
    Uint32 last_time, delta_time,last_time2, delta_time2;
    int test;


    initBack(&b);


    intialiser_texte(&text);

    initialiser_coeur1(&c1);initialiser_coeur11(&c11);
    initialiser_coeur2(&c2);initialiser_coeur22(&c22);
    initialiser_coeur3(&c3);initialiser_coeur33(&c33);
   
    initialiser_score(&score);








    Ennemi e;

    initEnnemi(&e);



   





    // enigme


    int startenigme = 0;
    char nomfichier[100];
    SDL_Surface *result;
    SDL_Surface *lost;
    SDL_Surface *win;
    SDL_Rect pos_result;
    SDL_Rect pos;
    enigmetf enigme;
    InitEnigme(&enigme, nomfichier);

    lost = TTF_RenderText_Solid(police, "YOU LOST(-_-)", black);
    win = TTF_RenderText_Solid(police, "YOU WIN :)", black);


    


    result = IMG_Load("img/result.png");
    pos_result.x = 320;
    pos_result.y = 100;
    pos.x = 530;
    pos.y = 310;





    //minimap

     Minimap minimap;
















































    
    txt[1].txt = TTF_RenderText_Blended(police1, "REBELOTE", black); //chargement text
        txt[1].pos_txt.x = SCREEN_W / 2 - 220;
        txt[1].pos_txt.y = 50;
    txt[2].txt = TTF_RenderText_Blended(police1, "Volume", black); 
        txt[2].pos_txt.x = 150;
        txt[2].pos_txt.y = 200;
    txt[3].txt = TTF_RenderText_Blended(police, "AZER", white); 
        txt[3].pos_txt.x = 50;
        txt[3].pos_txt.y = 200;
    txt[4].txt = TTF_RenderText_Blended(police, "MONTASSAR", white); 
        txt[4].pos_txt.x = 50;
        txt[4].pos_txt.y = 300;
    txt[5].txt = TTF_RenderText_Blended(police, "MOENES", white); 
        txt[5].pos_txt.x = 50;
        txt[5].pos_txt.y = 400;
    txt[6].txt = TTF_RenderText_Blended(police, "YOUSSEF", white); 
        txt[6].pos_txt.x = 600;
        txt[6].pos_txt.y = 200;
    txt[7].txt = TTF_RenderText_Blended(police, "CHRIF", white); 
        txt[7].pos_txt.x = 650;
        txt[7].pos_txt.y = 300;
    txt[8].txt = TTF_RenderText_Blended(police, "SIRINE", white); 
        txt[8].pos_txt.x = 600;
        txt[8].pos_txt.y = 400;
    
    txt[9].txt = TTF_RenderText_Blended(police1, "credits", white); 
        txt[9].pos_txt.x = 300;
        txt[9].pos_txt.y = 100;
    txt[10].txt = TTF_RenderText_Blended(police1, "choose your player", black); 
        txt[10].pos_txt.x = SCREEN_W / 2 - 400;
        txt[10].pos_txt.y = SCREEN_H/2 - 200;
    txt[11].txt = TTF_RenderText_Blended(police, "YOU CAN'T GO IN ", black); 
        txt[11].pos_txt.x = SCREEN_W / 2 - 400;
        txt[11].pos_txt.y = SCREEN_H/2 - 200;
    txt[12].txt = TTF_RenderText_Blended(police, "IM WARNING YOU,THIS IS YOU LAST CHANCE !! ", red); 
        txt[12].pos_txt.x = SCREEN_W / 2 - 400;
        txt[12].pos_txt.y = SCREEN_H/2 - 200;
    txt[13].txt = TTF_RenderText_Blended(police, "FINE,IF YOU WANT TO GO INTO THIS TERRITORY,you must win these mini games!!", black); 
        txt[13].pos_txt.x = SCREEN_W / 2 - 700;
        txt[13].pos_txt.y = SCREEN_H/2 - 200;
        txt[13].pos_txt.w =200;
        txt[13].pos_txt.h =600;

    
    
    
    
    
    image background, backsettings , backplay , creditsback , animm1 , animm2 , animm3 , TOUNSI , NORMAL;
    bouton play, settings, quit, credits , pb , mb , mute , nm , fs , wd , hb , boutonperso1 , boutonperso2;
    
    personne  p1 ,p2 , p;
    Coeur coeurs[8];
    initCoeurs(coeurs);

    int n ;
    Uint32 dt , t_prev ; 


    initbackground(&background);
    initplay(&play);
    initquit(&quit);
    initcredits(&credits);
    initsettings(&settings);
    initbackgroundsettings(&backsettings);
    initboutonssettings(&pb,&mb , &mute , &nm ,&hb , &wd ,&fs);
    initcreditsbackground(&creditsback,screen);
    initring(&animm1,&animm2,&animm3);
    init(&boutonperso1,&boutonperso2 , &TOUNSI , & NORMAL);
    initperso(&p1,&p2);

    Mix_Music* music;
    Mix_Chunk* clic;
    int volume;
    volume=MIX_MAX_VOLUME / 2;
    Mix_VolumeMusic(volume);
    
    SDL_Surface* masque = IMG_Load("masque.png");
    
    
    
    

    musiquebackground(music);
    clic = Mix_LoadWAV("clic.wav");
    SDL_Event event;
    int game_over = 0;

    int boutonquit = 0, boutonplay = 0, boutoncredits = 0, boutonsettings = 0 , boutonpb = 0 , boutonmb = 0 , boutonmute =0, boutonnm = 0 , boutonfs = 0 , boutonwd = 0 ,boutonhb = 0 ;
    int ring = 0;
    int boutonpersoo1 = 0 , boutonpersoo2 = 0;
    Uint32 start_time = SDL_GetTicks();


    while (!game_over) {
    
    	ring++;
    	
        
       if (ring%3 == 0) {SDL_BlitSurface(animm1.img,NULL,screen,&(animm1.pos1));
        SDL_Flip(screen);
        SDL_Delay(30);}
        if (ring%3 == 1){SDL_BlitSurface(animm2.img,NULL,screen,&(animm2.pos1));
        SDL_Flip(screen);
        SDL_Delay(30);}
        if (ring%3 == 2){SDL_BlitSurface(animm3.img,NULL,screen,&(animm3.pos1));        
        SDL_Flip(screen);
        SDL_Delay(30);}
        while (SDL_PollEvent(&event)) {
        
            switch (event.type) {
                case SDL_QUIT:
                    game_over = 1;
                    break;
                case SDL_MOUSEMOTION:
                    boutonquit = (event.motion.x >= quit.posbouton.x && event.motion.x <= quit.posbouton.x + 460 &&
                                  event.motion.y >= quit.posbouton.y && event.motion.y <= quit.posbouton.y + 130);
                    boutonplay = (event.motion.x >= play.posbouton.x && event.motion.x <= play.posbouton.x + 460 &&
                                  event.motion.y >= play.posbouton.y && event.motion.y <= play.posbouton.y + 130);
                    boutoncredits = (event.motion.x >= credits.posbouton.x && event.motion.x <= credits.posbouton.x + 460 &&
                                     event.motion.y >= credits.posbouton.y && event.motion.y <= credits.posbouton.y + 130);
                    boutonsettings = (event.motion.x >= settings.posbouton.x && event.motion.x <= settings.posbouton.x + 460 &&
                                      event.motion.y >= settings.posbouton.y && event.motion.y <= settings.posbouton.y + 130);
                    
                    
                    
                    
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        game_over = 1;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (boutonsettings) {
                        Mix_PlayChannel(1, clic, 0);
                        int settings_loop = 1;
                            afficher(backsettings,screen);
                            afficherbouton(&pb, screen);
                            afficherbouton(&mb, screen);
                            afficherbouton(&mute , screen);
                            afficherbouton(&nm , screen);
                            SDL_BlitSurface(txt[2].txt,NULL,screen,&txt[2].pos_txt);
                            SDL_Flip(screen);
                        while (settings_loop) {
                            
                            SDL_WaitEvent(&event);
                            
                            
                            switch (event.type) {
                                case SDL_KEYDOWN:
                                    if (event.key.keysym.sym == SDLK_q) {
                                        settings_loop = 0;
                                        
                                    }
                                
                    	            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                     game_over = 1;
                                     settings_loop = 0;
                    }
                                case SDL_MOUSEMOTION:
                                  
                                  boutonpb = (event.motion.x >= pb.posbouton.x && event.motion.x <= pb.posbouton.x + 100 &&
                                  event.motion.y >= pb.posbouton.y && event.motion.y <= pb.posbouton.y + 100) ;
                                  
                                  boutonmb = (event.motion.x >= mb.posbouton.x && event.motion.x <= mb.posbouton.x + 110 &&
                                  event.motion.y >= mb.posbouton.y && event.motion.y <= mb.posbouton.y + 30);

                                  boutonmute = (event.motion.x >= mute.posbouton.x && event.motion.x <= mute.posbouton.x + 140 &&
                                  event.motion.y >= mute.posbouton.y && event.motion.y <= mute.posbouton.y + 140); 
                                 
                                  boutonnm = (event.motion.x >= nm.posbouton.x && event.motion.x <= nm.posbouton.x + 140 &&
                                  event.motion.y >= nm.posbouton.y && event.motion.y <= nm.posbouton.y + 140); 
                                  
                                  boutonfs = (event.motion.x >= fs.posbouton.x && event.motion.x <= fs.posbouton.x + 360 &&
                                  event.motion.y >= fs.posbouton.y && event.motion.y <= fs.posbouton.y + 80);
                                  
                                  boutonwd = (event.motion.x >= wd.posbouton.x && event.motion.x <= wd.posbouton.x + 250 &&
                                  event.motion.y >= wd.posbouton.y && event.motion.y <= wd.posbouton.y + 80);
                                
                                  boutonhb = (event.motion.x >= hb.posbouton.x && event.motion.x <= hb.posbouton.x + 160 &&
                                  event.motion.y >= hb.posbouton.y && event.motion.y <= hb.posbouton.y + 160);
                                  
                                
                                
                                    break;

                                case SDL_MOUSEBUTTONDOWN :
                                if(boutonpb)
                                { Mix_PlayChannel(1, clic, 0);
                                  if (volume<128)
                                                    {
                                                        volume=volume+10;
                                                   
                                                        
                                                    }
                                                   Mix_VolumeMusic(volume);
                                }
                                if(boutonmb)
                                { Mix_PlayChannel(1, clic, 0);
                                if (volume>0)
                                                    {
                                                        volume=volume-10;
                                                        
                                                    }
                                                   Mix_VolumeMusic(volume);
                                }
                                if(boutonmute)
                                { Mix_PlayChannel(1, clic, 0);
                                  Mix_PauseMusic();
                                
                                
                                }
                                if(boutonnm)
                                {Mix_PlayChannel(1, clic, 0);
                                 Mix_ResumeMusic();
                                }
                                if(boutonhb)
                                {Mix_PlayChannel(1, clic, 0);settings_loop = 0;}
                                
                                if(boutonfs)
                                {Mix_PlayChannel(1, clic, 0);screen = SDL_SetVideoMode(0,0,0, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF);
                                  afficher(backsettings,screen);
                                }
                                
                                if(boutonwd)
                                {Mix_PlayChannel(1, clic, 0);screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
                                  afficher(backsettings,screen);                                
                                }
                                
                                    break;
                                   default:
                                   break;
                            }
		             if(boutonmute)
		             {afficherboutonpressed(&mute,screen);}
		             if(!boutonmute)
		             {afficherbouton(&mute,screen);}   
		             if(boutonnm)
		             {afficherboutonpressed(&nm,screen);}
		             if(!boutonnm)
		             {afficherbouton(&nm,screen);}       
		             if (boutonpb)
		             {afficherboutonpressed(&pb, screen);SDL_Flip(screen);}
		             if(!boutonpb)
		             {afficherbouton(&pb, screen);}
		             if (boutonmb)
		             {afficherboutonpressed(&mb, screen);}
		             if(!boutonmb)
		             {afficherbouton(&mb, screen);}
		             if (boutonfs)
		             {afficherboutonpressed(&fs, screen);}
		             if(!boutonfs)
		             {afficherbouton(&fs, screen);}
		             if (boutonhb)
		             {afficherboutonpressed(&hb, screen);}
		             if(!boutonhb)
		             {afficherbouton(&hb, screen);}
		             if (boutonwd)
		             {afficherboutonpressed(&wd, screen);}
		             if(!boutonwd)
		             {afficherbouton(&wd, screen);}
                     
                     
                     SDL_Flip(screen);
                     
                        }
                    } else if (boutonquit) {
                        Mix_PlayChannel(1, clic, 0);
                        game_over = 1;
                    } else if (boutonplay) {
                        Mix_PlayChannel(1, clic, 0);
                        int play_loop = 1;
                        afficher(backsettings , screen);
                        afficherbouton(&boutonperso1 , screen);
                        afficherbouton(&boutonperso2 , screen);
                        SDL_BlitSurface(txt[10].txt,NULL,screen,&txt[10].pos_txt);
                        
                      

                        
	                    SDL_BlitSurface(TOUNSI.img,NULL,screen,&TOUNSI.pos1); 
                        SDL_BlitSurface(NORMAL.img,NULL,screen,&NORMAL.pos1); 



                        int game = 0;


                        

















                        while(play_loop){
                            
                           SDL_WaitEvent(&event);
			   
			   SDL_Flip(screen);
			   
			   switch(event.type){
			   
			   	case SDL_KEYDOWN:
			   	    if (event.key.keysym.sym == SDLK_q) {
                                        play_loop = 0;
                                    }
				   
                                    
                                
                    	            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                     game_over = 1;
                                     play_loop = 0;
                    }
                    	break;
                    		case SDL_MOUSEMOTION :
                            boutonpersoo1= (event.motion.x >= boutonperso1.posbouton.x && event.motion.x <= boutonperso1.posbouton.x + 290 &&
                                event.motion.y >= boutonperso1.posbouton.y && event.motion.y <= boutonperso1.posbouton.y + 120);
                            boutonpersoo2 = (event.motion.x >= boutonperso2.posbouton.x && event.motion.x <= boutonperso2.posbouton.x + 290&&
                                event.motion.y >= boutonperso2.posbouton.y && event.motion.y <= boutonperso2.posbouton.y + 120);    
                    		break;
                    		case SDL_MOUSEBUTTONDOWN:
                    		if(boutonhb)
                    		{play_loop = 0;Mix_PlayChannel(1, clic, 0);}
                            if(boutonpersoo1)
                            {p = p1;

                            Mix_PlayChannel(1, clic, 0);
                            start_time =  SDL_GetTicks();

                            game = 1;
                            }
                            if(boutonpersoo2)
                            {p = p2;
                            Mix_PlayChannel(1, clic, 0);
                            start_time =  SDL_GetTicks();

                            game = 1 ;}
               }    
    
    int posinit = 0; // Initialize posinit to indicate the character is on the ground
    int pospas;
    SDL_Surface * perm;
    int collision = 0;
    int hits = 0;
    init_minimap(&minimap,p);


    Uint32 start_time  , elapsed_time ;
    start_time =  SDL_GetTicks();
    elapsed_time = 0;
    Uint32 dx ;
    int frames;
    while (game) {
        frames ++ ;
        int collisionCoeur = 0;
        t_prev = SDL_GetTicks();
        p.direction = 0;


        afficherBack(screen,b);
        afficher_minimap(minimap, screen);

        affichertempsen(elapsed_time / 1000);
        affichertemps(elapsed_time / 1000);  
        animerMinimap(&minimap);
        animerMinimape(&minimap);

            
                    
                    
        MAJMinimap(p.pos1, &minimap,b.camera_pos, 25);


        if (p.pos1.x >400){
            if (!(frames % 8)){
        
        animerEnnemi(&e,screen);
        deplacer(&e);
        }
        afficherEnnemi(e,screen);
        
        }

        
        
        

        



















        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                game = 0;
                break;
            
            case SDL_MOUSEBUTTONDOWN:
            
            case SDL_KEYDOWN:

                if (event.key.keysym.sym == SDLK_RIGHT) {
                    p.acceleration = 0.005;
                    p.direction = 1;
                    
                    augmenter_score(&score);

                } else if (event.key.keysym.sym == SDLK_LEFT) {
                    p.acceleration = -0.005;
                    p.direction = 2;
                    
                    
                } else if (event.key.keysym.sym == SDLK_UP && p.up == 0 && posinit == 1) { // Check if character is on the ground before allowing jump
                    posinit = 0;
                    p.up = 1;
                    p.vitesse_y = 2.5;
                    if(event.key.keysym.sym == SDLK_LEFT)
                        {
                        
                            p.direction = 2;
                           
                        }
                    else if(event.key.keysym.sym == SDLK_RIGHT)
                    {
                        p.direction = 1;
                        
                        
                    }
                }
                    else if(event.key.keysym.sym == SDLK_q)
                    {game = 0;play_loop = 0;}
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT) {
                    p.acceleration = 0.0;
                }
                break;
            default:
                break;
        }



        
        saut(&p, dt, &posinit);
        


        if (((b.pos_back_affiche.x >= (3200 - SCREEN_W)) || (p.pos1.x >0 ))&&(!collisionPP(p.pos1,masque)))
                            {
                                  movePerso(&p, dt);
                                  afficherCoeurs(coeurs,screen);


                            }

        for (int i = 0; i < 8; i++) 
    {
        collisionCoeur = collisionTri(p, coeurs[i]);
        if(collisionCoeur == 1) {
            coeurs[i].visible = 0;
            
        } 
    }
        collision = collisionBB(p,e);
        if (collision){
            p.pos1.x -= 300;
        }

        hits = hits + collision;
        

        scrolling(&b,p.direction,12);
        afficherperso(&p, screen);

        if (frames%5){
        animerPerso(&p);
                
}
       
        afficher_texte(screen,text);

        afficher_score(screen, police1, &score);
       
       if (hits == 0 ){
        afficher_coeur1(screen,c1);
        afficher_coeur2(screen,c2);
        afficher_coeur3(screen,c3);


       }
       if (hits == 1){
        afficher_coeur1(screen,c11);
        afficher_coeur2(screen,c2);
        afficher_coeur3(screen,c3);
        SDL_BlitSurface(txt[11].txt,NULL,screen,&txt[11].pos_txt);

        ;
       }
       if (hits == 2){
        afficher_coeur1(screen,c11);
        afficher_coeur2(screen,c22);
        afficher_coeur3(screen,c3);
        SDL_BlitSurface(txt[12].txt,NULL,screen,&txt[12].pos_txt);


        ;

       }
        if (hits == 3){
        afficher_coeur1(screen,c11);
        afficher_coeur2(screen,c22);
        afficher_coeur3(screen,c33);
        SDL_BlitSurface(txt[13].txt,NULL,screen,&txt[13].pos_txt);

        enregistrer_scores(&score, "scores.txt");
			    bestScore("scores.txt", tab);
			    afficherBest(screen, tab); // Afficher le meilleur score
			    SDL_Flip(screen); // Rafraîchit l'écran pour afficher le texte
                SDL_Delay(3000);
                runEnigmeGame(enigme, screen, result, win, lost, pos_result, pos, start_time);
                //Ticgame(screen);
                game = 0;
                play_loop = 0;
        
        }







        SDL_Flip(screen);
       // SDL_Delay(30);
        dt = SDL_GetTicks() - t_prev;
        elapsed_time = SDL_GetTicks() - start_time;
   
   
   
   
   
   

   
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

   
   
   
   
   
   
    }




		  
			      
			
			  
			   }
                    } else if (boutoncredits) {
                    	int credits_loop = 1;
                    	
                        Mix_PlayChannel(1, clic, 0);
                        afficher(creditsback,screen);
                        afficherbouton(&hb,screen);

                        for(int i = 3 ; i<10 ; i++)
                        {
                                SDL_BlitSurface(txt[i].txt,NULL,screen,&txt[i].pos_txt);
                        }
                        
                        
                        
                        SDL_Flip(screen);
                        while(credits_loop)
                        {
			 	SDL_WaitEvent(&event);
			 	switch(event.type)
			 	{
			 		case SDL_MOUSEMOTION :
			        boutonhb = (event.motion.x >= hb.posbouton.x && event.motion.x <= hb.posbouton.x + 160 &&
                                event.motion.y >= hb.posbouton.y && event.motion.y <= hb.posbouton.y + 160);
			 		break;
			 		
			 		case SDL_MOUSEBUTTONDOWN :
			 		if(boutonhb)
			 		{credits_loop = 0;Mix_PlayChannel(1,clic, 0);}
			 		break;
			 		default:
			 		break;
			 		                       
                        	
				}
				
			     if (boutonhb)
		             {afficherboutonpressed(&hb, screen);}
		             if(!boutonhb)
		             {afficherbouton(&hb, screen);}
		             SDL_Flip(screen);
			  	                        
                        }
                       } 
                    
                    break;
                default:
                    break;
            }
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        afficher(background, screen);
        afficherbouton(&play, screen);
        afficherbouton(&credits, screen);
        afficherbouton(&settings, screen);
        afficherbouton(&quit, screen);
        SDL_BlitSurface(txt[1].txt,NULL,screen,&txt[1].pos_txt);
       

        if (boutonquit) {
            afficherboutonpressed(&quit, screen);

        }
        if (boutonplay) {
            afficherboutonpressed(&play, screen);

        }
        if (boutonsettings) {
            afficherboutonpressed(&settings, screen);

        }
        if (boutoncredits) {
            afficherboutonpressed(&credits, screen);

        }
	                    SDL_Flip(screen);


    }

    Mix_FreeMusic(music);
    liberermenu(background, quit, play, credits, settings);
    liberersettings(backsettings,pb , mb , mute , nm , fs , wd , hb);
    libererimage(creditsback);
    libererimage(backplay);
    libererring(animm1,animm2,animm3);
    liberer_minimap(&minimap);

    freeperso(p1,p2,boutonperso1,boutonperso2);
    free_Surface_enigme(enigme);

    TTF_CloseFont(police);
    TTF_CloseFont(police1);
    TTF_Quit();
    Mix_FreeChunk(clic);

     libererBack(&b);
     
        for( int i=0; i<17 ;i++)
	{
		
			SDL_FreeSurface(e.enem[i]);
		
	}
     liberer_texte(text);

    liberer_coeur1(&c1);
    liberer_coeur1(&c2);
    liberer_coeur1(&c3);
    liberer_coeur1(&c11);
    liberer_coeur1(&c22);
    liberer_coeur1(&c33);
    SDL_Quit();

    
    return 0;

}









