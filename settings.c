#include <stdio.h>
#include"settings.h"
#include "image.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>






void liberersettings(image a , bouton b , bouton c , bouton d , bouton e , bouton f , bouton g , bouton h)
{
	SDL_FreeSurface(a.img);
	SDL_FreeSurface(b.boutonpressed);
	SDL_FreeSurface(b.boutonnonpressed);
	SDL_FreeSurface(c.boutonpressed);
	SDL_FreeSurface(c.boutonnonpressed);
	SDL_FreeSurface(d.boutonpressed);
	SDL_FreeSurface(d.boutonnonpressed);
	SDL_FreeSurface(e.boutonpressed);
	SDL_FreeSurface(e.boutonnonpressed);
	SDL_FreeSurface(f.boutonpressed);
	SDL_FreeSurface(f.boutonnonpressed);
	SDL_FreeSurface(g.boutonpressed);
	SDL_FreeSurface(g.boutonnonpressed);
	SDL_FreeSurface(h.boutonpressed);
	SDL_FreeSurface(h.boutonnonpressed);
	

}
