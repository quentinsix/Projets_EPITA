#include "getsetpixel.h"




static inline Uint8* pix_ref(SDL_Surface* surface, unsigned x, unsigned y)
{
	int k = surface->format->BytesPerPixel; //bitdepth of the surface.
	return (Uint8*)surface->pixels + y * surface->pitch + x * k;/*return th
	e pixel*/
}


//Get a pixel thanks to its coordinate.
Uint32 get_pixel(SDL_Surface* image, unsigned x, unsigned y)
{
	Uint8* p = pix_ref(image, x, y);/*referance of the pixel at the coordin
	ate (x;y)*/

	if (image->format->BytesPerPixel==1)
	{
		return *p;
	} else if (image->format->BytesPerPixel==2) 
	{
		return *(Uint16 *)p;
	} else if (image->format->BytesPerPixel==3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)/*SDL_Big_ENDIAN is an
		    order when the most significant byte is stored first*/
		    //SDL_BYTEORDER, byte order...
		{
			return p[0] << 16 | p[1] << 8 | p[2];
		} else 
		{
			return p[0] | p[1] << 8 | p[2] << 16;
		}
	} else if (image->format->BytesPerPixel==4)
	{
		return *(Uint32 *)p;
	}
	return 0;
}


//Set a pixel to special coordinate((x;y)).
void set_pixel(SDL_Surface* image, unsigned x, unsigned y, Uint32 pxl)
{
	Uint8* p = pix_ref(image, x, y);/*reference of the pixel at the coordin
	ate given in parameter*/

	if (image->format->BytesPerPixel==1)
	{
		*p = pxl;
	} else if (image->format->BytesPerPixel == 2)
	{
		*(Uint16*)p = pxl;
	} else if (image->format->BytesPerPixel == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pxl >> 16) & 0xff;
			p[1] = (pxl >> 8) & 0xff;
			p[2] = pxl & 0xff;
		} else 
		{
			p[0] = pxl & 0xff;
			p[1] = (pxl >> 8) & 0xff;
			p[2] = (pxl >> 16) & 0xff;
		}
	} else if (image->format->BytesPerPixel == 4)
	{
		*(Uint32 *)p = pxl;
	}
}



//Thanks to this function we will be able to fill our matrix with 0 and 1
//If the pixel is black, its red value will be 0 so the function will return 
//1 and if it's white, it'll return 1 - 255/255 = 0.
double get_value(SDL_Surface* image, size_t x, size_t y)
{
  Uint32 pixel = get_pixel(image, x, y);

  Uint8 r = 0, g = 0, b = 0;
  SDL_GetRGB(pixel, image->format, &r, &g, &b);

  return (double) 1.0 - (r / 255);
}






