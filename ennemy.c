#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<math.h>
#include "ennemy.h"
#include "perso.h"
#include "background.h"
void initEnnemi(Ennemi *e)
{
e->enem[1] = IMG_Load("8.png");
e->enem[2] = IMG_Load("9.png");
e->enem[3] = IMG_Load("10.png");
e->enem[4] = IMG_Load("11.png");
e->enem[5] = IMG_Load("12.png");
e->enem[6] = IMG_Load("13.png");
e->enem[7] = IMG_Load("14.png");
e->enem[8] = IMG_Load("15.png");
e->enem[9] = IMG_Load("1.png");
e->enem[10] = IMG_Load("2.png");
e->enem[11] = IMG_Load("3.png");
e->enem[12] = IMG_Load("4.png");
e->enem[13] = IMG_Load("5.png");
e->enem[14] = IMG_Load("6.png");
e->enem[15] = IMG_Load("7.png");
e->enem[16] = IMG_Load("16.png");
e->enem[17] = IMG_Load("17.png");
e->pos.x=1400 ;
e->pos.y=550 ;

e->pos.h=0;
e->pos.w=0;
e->d=0;
e->num=0;

}



void afficherEnnemi(Ennemi e, SDL_Surface *screen )

{
SDL_BlitSurface(e.enem[e.num],NULL,screen,&e.pos);
}

void animerEnnemi( Ennemi * e,SDL_Surface *screen)
{

e->num ++;
 if (e->num==17)
{ e->num=1;}
  }
void deplacer( Ennemi * e)
{
int posmax=1100;
int posmin=1000;
 if (e->pos.x > posmax)
    {
        e->d=1;
    }
    if (e->pos.x < posmin)
    {
        e->d=0;
    }
if (e->d==0)
    {
        e->pos.x += 50;
    }else if (e->d==1)
    {
        e->pos.x -= 50;
    }

     } 


int collisionBB( personne p, Ennemi e)
{
int collision;
  if (((p.pos1.x + p.pos1.w) < e.pos.x) || (p.pos1.x > (e.pos.x + e.pos.w)) || ((p.pos1.y + p.pos1.y) < e.pos.y) || (p.pos1.y > (e.pos.y + e.pos.y))) 
  {
    collision = 0;//pas de collision
  }
 else
  {
    collision = 1;//il y a une collision
      }
  return collision;
}


void initCoeurs(Coeur coeurs[])
{
    int i;
    char nom_image[50];
    for (i = 0; i < 8; i++)
    {

        sprintf(nom_image, "bonus/%d.png", i + 1);
        coeurs[i].image = IMG_Load(nom_image);
        coeurs[i].position.x = rand() % 600; // Position aléatoire en x
        coeurs[i].position.y = rand() % 100 + 600; // Position aléatoire en y
        coeurs[i].position.w = 50;
        coeurs[i].position.h = 50;
        coeurs[i].visible = 1;
    }
}


void afficherCoeurs(Coeur coeurs[], SDL_Surface *screen)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (coeurs[i].visible)
        {
            SDL_BlitSurface(coeurs[i].image, NULL, screen, &coeurs[i].position);
        }
    }
}


int collisionTri(personne p, Coeur coeur) {
    float centerX1 = p.pos1.x + p.pos1.w / 2.0;
    float centerY1 = p.pos1.y + p.pos1.h / 2.0;
    float R1 = fmax(p.pos1.w / 2.0, p.pos1.h / 2.0); // Rayon du cercle

    float centerX2 = coeur.position.x + coeur.position.w / 2.0;
    float centerY2 = coeur.position.y + coeur.position.h / 2.0;
    float R2 = coeur.position.w / 2.0; // Rayon du cercle

    float dx = centerX2 - centerX1;
    float dy = centerY2 - centerY1;
    float D = sqrt(dx * dx + dy * dy); // Distance entre les centres des deux cercles

    if (D <= R1 + R2) {
        return 1;
    } else {
        return 0;
    }
}



void deplacerIA(Ennemi *e,personne p ) 
{
  if (((e->pos.x - p.pos1.x) < 200) && ((e -> pos.x - p.pos1.x) > 80))  
   {
    e -> d = 1; 
    e -> pos.x -= 10;
  } 
  else if (((e -> pos.x - p.pos1.x) < -80) && ((e -> pos.x - p.pos1.x) > -400))
   {
    e -> d = 0; 
    e -> pos.x += 10;
  } 
  else if (((e -> pos.x - p.pos1.x) <= 80) && ((e -> pos.x - p.pos1.x) >= 0)) 
  {
    e -> d =1;
  } 
  else if (((e -> pos.x - p.pos1.x) <= 0) && ((e -> pos.x - p.pos1.x) >= -80)) 
  {
    e -> d = 0;

  }
  else 
deplacer(e);
}