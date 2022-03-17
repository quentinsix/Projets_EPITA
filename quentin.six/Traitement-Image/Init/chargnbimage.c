#include "chargnbimage.h"

SDL_Surface* img;

SDL_Surface* charg_img(char* path)
{
	img = IMG_Load(path);

	if (!img)
	    printf("no");
	return img;
}

SDL_Window* disp_img(SDL_Surface* img)
{
	if (SDL_VideoInit(NULL) < 0)
	{
		printf("erreur d'initalisation sdl : %s", SDL_GetError());
	}

	SDL_Window* screen; //creating the screen

	int w = img -> w;
	int h = img -> h;

	screen = SDL_CreateWindow("EKIP", SDL_WINDOWPOS_CENTERED,
                      SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);

	if(screen == NULL)
	{
		printf("Error while creating the window : %s", SDL_GetError());
	}

	SDL_BlitSurface(img, NULL, SDL_GetWindowSurface(screen), 0);
	SDL_UpdateWindowSurface(screen);

	return screen;
}

void wait_for_keypressed()
  {
      SDL_Event event;
 
      // Wait for a key to be down.
      do
      {
          SDL_PollEvent(&event);
      } while(event.type != SDL_KEYDOWN);
 
      // Wait for a key to be up.
      do
      {
          SDL_PollEvent(&event);
      } while(event.type != SDL_KEYUP);
 }

