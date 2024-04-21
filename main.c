#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "image.h"
#include "musique.h"
#include "settings.h"
#include "perso.h"

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
    
    
    
    txt[1].text = TTF_RenderText_Blended(police1, "REBELOTE", black); //chargement text
        txt[1].postext.x = 350;
        txt[1].postext.y = 50;
    txt[2].text = TTF_RenderText_Blended(police1, "Volume", black); 
        txt[2].postext.x = 150;
        txt[2].postext.y = 200;
    txt[3].text = TTF_RenderText_Blended(police, "AZER SLIMANI", white); 
        txt[3].postext.x = 50;
        txt[3].postext.y = 200;
    txt[4].text = TTF_RenderText_Blended(police, "MONTASSAR CHOUIGUIR", white); 
        txt[4].postext.x = 50;
        txt[4].postext.y = 300;
    txt[5].text = TTF_RenderText_Blended(police, "MOENES KHAROUBI", white); 
        txt[5].postext.x = 50;
        txt[5].postext.y = 400;
    txt[6].text = TTF_RenderText_Blended(police, "YOUSSEF GOMRI", white); 
        txt[6].postext.x = 600;
        txt[6].postext.y = 200;
    txt[7].text = TTF_RenderText_Blended(police, "CHRIF SMAYA", white); 
        txt[7].postext.x = 650;
        txt[7].postext.y = 300;
    txt[8].text = TTF_RenderText_Blended(police, "SIRINE MERAI BOULAABA", white); 
        txt[8].postext.x = 600;
        txt[8].postext.y = 400;
    
    txt[9].text = TTF_RenderText_Blended(police1, "credits", white); 
        txt[9].postext.x = 300;
        txt[9].postext.y = 100;
    txt[10].text = TTF_RenderText_Blended(police1, "choose your player", white); 
        txt[10].postext.x = 300;
        txt[10].postext.y = 100;
    
    
    
    
    image background, backsettings , backplay , creditsback , anim1 , anim2 , anim3 ;
    bouton play, settings, quit, credits , pb , mb , mute , nm , fs , wd , hb , boutonperso1 , boutonperso2;
    
    personne  p1 ,p2 , p;
    int n ;
    Uint32 dt , t_prev ; 


    initbackground(&background);
    initplay(&play);
    initquit(&quit);
    initcredits(&credits);
    initsettings(&settings);
    initbackgroundsettings(&backsettings);
    initboutonssettings(&pb,&mb , &mute , &nm ,&hb , &wd ,&fs);
    initcomingsoon(&backplay);
    initcreditsbackground(&creditsback,screen);
    initring(&anim1,&anim2,&anim3);
    init(&boutonperso1,&boutonperso2);
    initperso(&p1,&p2);

    Mix_Music* music;
    Mix_Chunk* clic;
    int volume;
    volume=MIX_MAX_VOLUME / 2;
    Mix_VolumeMusic(volume);
    
    
    
    
    
    

    musiquebackground(music);
    clic = Mix_LoadWAV("clic.wav");
    SDL_Event event;
    int game_over = 0;

    int boutonquit = 0, boutonplay = 0, boutoncredits = 0, boutonsettings = 0 , boutonpb = 0 , boutonmb = 0 , boutonmute =0, boutonnm = 0 , boutonfs = 0 , boutonwd = 0 ,boutonhb = 0 ;
    int ring = 0;
    int boutonpersoo1 = 0 , boutonpersoo2 = 0;
    

    while (!game_over) {
    
    	ring++;
    	
        
       if (ring%3 == 0) {SDL_BlitSurface(anim1.img,NULL,screen,&(anim1.pos1));
        SDL_Flip(screen);
        SDL_Delay(40);}
        if (ring%3 == 1){SDL_BlitSurface(anim2.img,NULL,screen,&(anim2.pos1));
        SDL_Flip(screen);
        SDL_Delay(40);}
        if (ring%3 == 2){SDL_BlitSurface(anim3.img,NULL,screen,&(anim3.pos1));        
        SDL_Flip(screen);
        SDL_Delay(40);}
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
                            SDL_BlitSurface(txt[2].text,NULL,screen,&txt[2].postext);
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
                        afficher(backplay , screen);
                        afficherbouton(&hb,screen);
                        afficherbouton(&boutonperso1 , screen);
                        afficherbouton(&boutonperso2 , screen);
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
                    		boutonhb = (event.motion.x >= hb.posbouton.x && event.motion.x <= hb.posbouton.x + 160 &&
                                event.motion.y >= hb.posbouton.y && event.motion.y <= hb.posbouton.y + 160);
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
                            game = 1;
                            }
                            if(boutonpersoo2)
                            {p = p2;
                            Mix_PlayChannel(1, clic, 0);
                            game = 1 ;}
                            
    
    int posinit = 0; // Initialize posinit to indicate the character is on the ground

    while (game) {
        t_prev = SDL_GetTicks();
        p.direction = 0;

        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                game = 0;
                break;
            case SDL_MOUSEMOTION:
            boutonhb = (event.motion.x >= hb.posbouton.x && event.motion.x <= hb.posbouton.x + 160 &&
                   event.motion.y >= hb.posbouton.y && event.motion.y <= hb.posbouton.y + 160);

            case SDL_KEYDOWN:

                if (event.key.keysym.sym == SDLK_RIGHT) {
                    p.acceleration = 0.005;
                    p.direction = 1;
                } else if (event.key.keysym.sym == SDLK_LEFT) {
                    p.acceleration = -0.005;
                    p.direction = 2;
                } else if (event.key.keysym.sym == SDLK_SPACE && p.up == 0 && posinit == 1) { // Check if character is on the ground before allowing jump
                    posinit = 0;
                    p.up = 1;
                    p.vitesse_y = 2.0;
                }
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT) {
                    p.acceleration = 0.0;
                    p.direction = 0;
                }
                break;
            default:
                break;
        }

        movePerso(&p, dt);
        saut(&p, dt, &posinit); // Pass posinit by reference to manage jumping
        animerPerso(&p);
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        afficherperso(&p, screen);
        if (boutonhb)
		             {afficherboutonpressed(&hb, screen);game= 0;}
		             if(!boutonhb)
		             {afficherbouton(&hb, screen);}
        SDL_Flip(screen);
        dt = SDL_GetTicks() - t_prev;
    }




                           
                                default:
                                break;
                                    
                                    
                             
			   }
			  
			       if (boutonhb)
		             {afficherboutonpressed(&hb, screen);}
		             if(!boutonhb)
		             {afficherbouton(&hb, screen);}
			
			  
			   }
                    } else if (boutoncredits) {
                    	int credits_loop = 1;
                    	
                        Mix_PlayChannel(1, clic, 0);
                        afficher(creditsback,screen);
                        afficherbouton(&hb,screen);

                        for(int i = 3 ; i<10 ; i++)
                        {
                                SDL_BlitSurface(txt[i].text,NULL,screen,&txt[i].postext);
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
			 		{credits_loop = 0;Mix_PlayChannel(1, clic, 0);}
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
        SDL_BlitSurface(txt[1].text,NULL,screen,&txt[1].postext);
       

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
    libererring(anim1,anim2,anim3);
    freeperso(p1,p2,boutonperso1,boutonperso2);
    TTF_CloseFont(police);
    TTF_CloseFont(police1);
    TTF_Quit();
    Mix_FreeChunk(clic);
    SDL_Quit();

    
    return 0;

}









