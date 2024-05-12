#include "enigmetf.h"

void InitEnigme(enigmetf *enigme, char nomfichier[]) {
  
    FILE *fquestion = NULL;


    enigme->pos_selected = 0;
    enigme->background = IMG_Load("img/backgroundd.png");
    enigme->button = IMG_Load("img/bu.png");
    enigme->button_s = IMG_Load("img/bu2.png");

    TTF_Init();

    SDL_Color couleur = {0, 3, 3};

    enigme->police = TTF_OpenFont("Phonk Regular DEMO.otf", 30);
    enigme->police1 = TTF_OpenFont("Phonk Regular DEMO.otf", 20);

    char questionn[50];

   
    srand(time(NULL));
    enigme->num_question = rand() % 4;

 
    while (enigme->num_question == 0) {
        enigme->num_question = rand() % 4;
    }

    sprintf(nomfichier, "questions_rep_vrairep.txt");
    char reponse[50];

    int min, max, vrep;
    switch (enigme->num_question) {
        case 1: {
            min = 3;
            max = 5;
            vrep = 12;
            break;
        }
        case 2: {
            min = 6;
            max = 8;
            vrep = 13;
            break;
        }
        case 3: {
            min = 9;
            max = 11;
            vrep = 14;
            break;
        }
    }

    fquestion = fopen(nomfichier, "r+");
    if (fquestion != NULL) {
        int test = 1;
        while (fgets(questionn, 50, fquestion) && (test != enigme->num_question)) {
            test++;
        }
        fclose(fquestion);
    }

    fquestion = fopen(nomfichier, "r+");
    if (fquestion != NULL) {
        int testr = 0;
        while (fgets(reponse, 50, fquestion) && (testr < max)) {
            if (testr >= min) {
                enigme->reponses[testr - min] = TTF_RenderText_Blended(enigme->police1, reponse, couleur);
            }
            testr++;
        }
        fclose(fquestion);
    }

    fquestion = fopen(nomfichier, "r+");
    if (fquestion != NULL) {
        int testrv = 1;
        while (fgets(reponse, 50, fquestion)) {
            if (testrv == vrep) {
                enigme->reponses[2] = TTF_RenderText_Blended(enigme->police1, reponse, couleur);
            }
            testrv++;
        }
        fclose(fquestion);
    }


    srand(time(NULL));
    enigme->positionVraiReponse = rand() % 4;


    while (enigme->positionVraiReponse == 0) {
        enigme->positionVraiReponse = rand() % 4;
    }






    enigme->question = TTF_RenderText_Blended(enigme->police, questionn, couleur);


    enigme->pos_question.x = 272;
    enigme->pos_question.y = 150;

    enigme->pos_reponse1.x = 565;
    enigme->pos_reponse1.y = 310;

    enigme->pos_reponse2.x = 260;
    enigme->pos_reponse2.y = 455;

    enigme->pos_reponse3.x = 845;
    enigme->pos_reponse3.y = 455;

    enigme->pos_reponse1txt.x = 650;
    enigme->pos_reponse1txt.y = 360;

    enigme->pos_reponse2txt.x = 379;
    enigme->pos_reponse2txt.y = 500;

    enigme->pos_reponse3txt.x = 946;
    enigme->pos_reponse3txt.y = 500;

    enigme->image_clock = IMG_Load("aaaaaa.png");

    enigme->pos_image_clock.x = 1200;
    enigme->pos_image_clock.y = 0;

    enigme->single_Clock.w = 114;
    enigme->single_Clock.h = 162;
    enigme->single_Clock.x = 0;
    enigme->single_Clock.y = 0;

    enigme->clock_num = 0;
}

void afficherEnigme(enigmetf enigme, SDL_Surface *ecran) {
    SDL_BlitSurface(enigme.background, NULL, ecran, NULL);
    displayClock(enigme, ecran);
    SDL_BlitSurface(enigme.question, NULL, ecran, &enigme.pos_question);


    switch (enigme.positionVraiReponse) {
        case 1: {
            switch (enigme.pos_selected) {
                case 0: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 1: {
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 2: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 3: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
            }
            break;
        }
        case 2: {
            switch (enigme.pos_selected) {
                case 0: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 1: {
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 2: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 3: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
            }
            break;
        }
        case 3: {
            switch (enigme.pos_selected) {
                case 0: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 1: {
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 2: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
                case 3: {
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse1);
                    SDL_BlitSurface(enigme.button, NULL, ecran, &enigme.pos_reponse2);
                    SDL_BlitSurface(enigme.button_s, NULL, ecran, &enigme.pos_reponse3);
                    SDL_BlitSurface(enigme.reponses[0], NULL, ecran, &enigme.pos_reponse1txt);
                    SDL_BlitSurface(enigme.reponses[1], NULL, ecran, &enigme.pos_reponse2txt);
                    SDL_BlitSurface(enigme.reponses[2], NULL, ecran, &enigme.pos_reponse3txt);
                }
                break;
            }
            break;
        }
    }
}

void displayClock(enigmetf enigme, SDL_Surface *ecran) {
    SDL_BlitSurface(enigme.image_clock, &(enigme.single_Clock), ecran, &enigme.pos_image_clock);
}


void animer(enigmetf *enigme) {
    //  entre 0 inclus et 8 exclus
    if (enigme->clock_num >= 0 && enigme->clock_num < 8) {
        enigme->single_Clock.x = enigme->clock_num * enigme->single_Clock.w;

        enigme->clock_num++;
    } 
    else if (enigme->clock_num == 8) {
        // à 8 fois la largeur 
        enigme->single_Clock.x = enigme->clock_num * enigme->single_Clock.w;
        // recommencer l'animation
        enigme->clock_num = 0;
    }
}

void free_Surface_enigme(enigmetf e) {
    SDL_FreeSurface(e.background);
    SDL_FreeSurface(e.question);
    SDL_FreeSurface(e.reponses[0]);
    SDL_FreeSurface(e.reponses[1]);
    SDL_FreeSurface(e.reponses[2]);
    SDL_FreeSurface(e.button);
    SDL_FreeSurface(e.button_s);
}


#define TEMPS_LIMITE 60000 // Example time limit in milliseconds

// Assuming the structures and functions used in your code are defined elsewhere

void runEnigmeGame(enigmetf enigme, SDL_Surface* ecran, SDL_Surface* result, SDL_Surface* win, SDL_Surface* lost, SDL_Rect pos_result, SDL_Rect pos, Uint32 start_time) {
    int done = 1;
    int var = 0;
    SDL_Event event;

    while (done) {
        if (var == 0) {
            animer(&enigme);
            afficherEnigme(enigme, ecran);

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        done = 0;
                        break;
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym) {
                            case SDLK_a:
                                enigme.pos_selected = 1;
                                break;
                            case SDLK_b:
                                enigme.pos_selected = 2;
                                break;
                            case SDLK_c:
                                enigme.pos_selected = 3;
                                break;
                            case SDLK_RETURN:
                                if (enigme.positionVraiReponse == enigme.pos_selected) {
                                    SDL_BlitSurface(result, NULL, ecran, &pos_result);
                                    SDL_BlitSurface(win, NULL, ecran, &pos);
                                    SDL_Flip(ecran);
                                    SDL_Delay(3000);
                                    done = 0;
                                } else {
                                    SDL_BlitSurface(result, NULL, ecran, &pos_result);
                                    SDL_BlitSurface(lost, NULL, ecran, &pos);
                                    SDL_Flip(ecran);
                                    SDL_Delay(3000);
                                    done = 0;
                                }
                                break;
                        }
                        break;
                    case SDL_MOUSEMOTION:
                        if ((event.motion.x > enigme.pos_reponse1.x && event.motion.x < enigme.pos_reponse1.x + enigme.button->w) && (event.motion.y > enigme.pos_reponse1.y && event.motion.y < enigme.pos_reponse1.y + enigme.button->h)) {
                            enigme.pos_selected = 1;
                        } else if ((event.motion.x > enigme.pos_reponse2.x && event.motion.x < enigme.pos_reponse2.x + enigme.button->w) && (event.motion.y > enigme.pos_reponse2.y && event.motion.y < enigme.pos_reponse2.y + enigme.button->h)) {
                            enigme.pos_selected = 2;
                        } else if ((event.motion.x > enigme.pos_reponse3.x && event.motion.x < enigme.pos_reponse3.x + enigme.button->w) && (event.motion.y > enigme.pos_reponse3.y && event.motion.y < enigme.pos_reponse3.y + enigme.button->w)) {
                            enigme.pos_selected = 3;
                        } else {
                            enigme.pos_selected = 0;
                        }
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if ((event.motion.x > enigme.pos_reponse1.x && event.motion.x < enigme.pos_reponse1.x + enigme.button->w) && (event.motion.y > enigme.pos_reponse1.y && event.motion.y < enigme.pos_reponse1.y + enigme.button->h)) {
                            if (enigme.positionVraiReponse == enigme.pos_selected) {
                                SDL_BlitSurface(result, NULL, ecran, &pos_result);
                                SDL_BlitSurface(win, NULL, ecran, &pos);
                                SDL_Flip(ecran);
                                SDL_Delay(3000);
                                done = 0;
                            } else {
                                SDL_BlitSurface(result, NULL, ecran, &pos_result);
                                SDL_BlitSurface(lost, NULL, ecran, &pos);
                                SDL_Flip(ecran);
                                SDL_Delay(3000);
                                done = 0;
                            }
                        } else if ((event.motion.x > enigme.pos_reponse2.x && event.motion.x < enigme.pos_reponse2.x + enigme.button->w) && (event.motion.y > enigme.pos_reponse2.y && event.motion.y < enigme.pos_reponse2.y + enigme.button->h)) {
                            if (enigme.positionVraiReponse == enigme.pos_selected) {
                                SDL_BlitSurface(result, NULL, ecran, &pos_result);
                                SDL_BlitSurface(win, NULL, ecran, &pos);
                                SDL_Flip(ecran);
                                SDL_Delay(3000);
                                done = 0;
                            } else {
                                SDL_BlitSurface(result, NULL, ecran, &pos_result);
                                SDL_BlitSurface(lost, NULL, ecran, &pos);
                                SDL_Flip(ecran);
                                SDL_Delay(3000);
                                done = 0;
                            }
                        } else if ((event.motion.x > enigme.pos_reponse3.x && event.motion.x < enigme.pos_reponse3.x + enigme.button->w) && (event.motion.y > enigme.pos_reponse3.y && event.motion.y < enigme.pos_reponse3.y + enigme.button->w)) {
                            if (enigme.positionVraiReponse == enigme.pos_selected) {
                                SDL_BlitSurface(result, NULL, ecran, &pos_result);
                                SDL_BlitSurface(win, NULL, ecran, &pos);
                                SDL_Flip(ecran);
                                SDL_Delay(3000);
                                done = 0;
                            } else {
                                SDL_BlitSurface(result, NULL, ecran, &pos_result);
                                SDL_BlitSurface(lost, NULL, ecran, &pos);
                                SDL_Flip(ecran);
                                SDL_Delay(3000);
                                done = 0;
                            }
                        }
                        break;
                }
            }
            SDL_Flip(ecran);
            SDL_Delay(90);

            // temps 
            if (SDL_GetTicks() - start_time >= TEMPS_LIMITE) {
                var = 1;
                SDL_BlitSurface(lost, NULL, ecran, &pos);
                SDL_Flip(ecran);
                printf("You lost, time's up!\n");
                SDL_Delay(1000);
                break;
            }
        }
    }
}
