#include "segmentation.h"
#include "../Init/chargnbimage.h"
#include "../Init/getsetpixel.h"
#include "extraction.h"




// vertical segmentation of the image
int seg_ver(SDL_Surface* image,
                    size_t counter,
                    int pligne,
                    int dligne)
{
  int bpix = 0;//bool to know if there is a black pixel
  int pcol = 0; // beginning of the character.
  int dcol; // end of the character

  for(int x = 0; x < image->w; ++x)
  {
    int oneblank = 1;
    for(int y = pligne; y <= dligne; ++y)
    {
      Uint32 pixel = get_pixel(image, x, y);
      Uint8 r = 0, g = 0, b = 0;
      SDL_GetRGB(pixel, image->format, &r, &g, &b);
      if (r == 0)//enough to know if the pixel is black as the image is in b&w.
      {
        oneblank = 0;
        if (bpix == 0)
        {
          bpix = 1;
          pcol = x;//beginning of the chracter indice's.

	  for(int i = pligne; i<dligne; i++) {
		Uint32 pixelGreen;
		pixelGreen = SDL_MapRGB(image->format, 0 ,255, 0);
		set_pixel(image, pcol-2, i, pixelGreen);
	  }//Let's change the color of the column in green.

        }
        y = dligne + 1;
      }
    }

    if (bpix == 1 && oneblank == 1)
    {
      dcol = x - 1;//last column's indice.

      //extraction function that will create a matrix.
      extract(image, pligne, dligne, pcol, dcol, counter);

      counter += 1;
	for(int i = pligne; i<dligne; i++) {
		Uint32 pixelGreen;
		pixelGreen = SDL_MapRGB(image->format, 0 ,255, 0);
		set_pixel(image, dcol, i, pixelGreen);
	}//We change the color.


      bpix = 0;
    }
  }

  return counter;
}






void seg_hor(SDL_Surface* img)
{
  size_t counter = 0;

  int bpix = 0 ; // Is there a black pixel
  int pligne = 0; // first line
  int dligne; // last line

  for(int y = 0; y < img->h; ++y)//through the lines
  {
    int oneblank = 1;//bool to know if there's a blank
    for(int x = 0; x < img->w; ++x)//through the column's
    {
      Uint32 pixel = get_pixel(img, x, y);
      Uint8 r = 0, g = 0, b = 0;

      SDL_GetRGB(pixel, img->format, &r, &g, &b);
      if (r == 0)//enough to know if it's a black or white pixel.
      {
        oneblank = 0;
        if (bpix == 0)
        {
          bpix = 1;
          pligne = y;//first line indice

	for(int i = 0; i<img->w; i++){
		Uint32 pixelRed;
		pixelRed = SDL_MapRGB(img->format, 255, 0, 0);
		set_pixel(img, i, y-2, pixelRed);
	}//Changing th e color to red

        }
        x = img->w;
      }
    }
    if (bpix == 1 && oneblank == 1)
    {
      dligne = y - 1;//last line
      counter = seg_ver(img, counter, pligne, dligne);
      bpix = 0;


	for(int i = 0; i<img->w; i++){
		Uint32 pixelRed;
		pixelRed = SDL_MapRGB(img->format, 255, 0, 0);
		set_pixel(img, i, y+1, pixelRed);
	}//Changing the color
    }
  }
}
