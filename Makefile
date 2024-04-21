rebelote:main.o image.o musique.o settings.o perso.o 
	gcc main.o musique.o perso.o image.o settings.o -o rebelote -lSDL -lm -lSDL_mixer -lSDL_ttf -g -lSDL_image 
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
