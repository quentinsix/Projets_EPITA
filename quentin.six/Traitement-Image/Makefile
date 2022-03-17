#Makefile

CPPFLAGS = -MMD
CC = gcc -rdynamic
CFLAGS = -Wall -Wextra -Werror -std=c99 -O2 `pkg-config --cflags sdl2  gtk+-3.0`
LDFLAGS =
LDLIBS = -lm `pkg-config --libs sdl2 gtk+-3.0` -lSDL2 -lSDL2_image

fichier = main.c Init/chargnbimage.c Init/getsetpixel.c Init/colorbw.c Separation/segmentation.c Separation/extraction.c Interface/gtk.c ../Reseau/backprop.c ../Reseau/neural_network.c ../Reseau/neuron.c ../Reseau/networkSaver.c ../Reseau/layer.c
fichierobj = ${fichier:.c=.o}
fichierd = ${fichier:.c=.d}

all: main

main: ${fichierobj}

run: all
	./main

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf *.d
	rm -rf ../Reseau/*.o
	rm -rf ../Reseau/*.d
	rm -rd */*.o
	rm -rf */*.d
	rm main
	rm [0-9]*
	
