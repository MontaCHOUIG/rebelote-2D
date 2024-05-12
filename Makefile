rebelote:main.o image.o musique.o settings.o perso.o background.o ennemy.o enigmetf.o minimap.o tictactoe.o
	gcc main.o musique.o minimap.o background.o perso.o image.o ennemy.o enigmetf.o tictactoe.o settings.o -o rebelote -lSDL -lm -lSDL_mixer -lSDL_ttf -lSDL_image -lSDL_gfx -g 
main.o:main.c
	gcc -c main.c -g
image.o:image.c
	gcc -c image.c -g
musique.o:musique.c
	gcc -c musique.c -g
settings.o:settings.c
	gcc -c settings.c -g
perso.o:perso.c
	gcc -c perso.c -g
background.o:background.c
	gcc -c background.c -g
ennemy.o:ennemy.c
	gcc -c ennemy.c -g
enigmetf.o:enigmetf.c
	gcc -c enigmetf.c -g 
minimap.o:minimap.c
	gcc -c minimap.c -g
tictactoe.o:tictactoe.c
	gcc -c tictactoe.c -g