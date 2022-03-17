#include "chargnbimage.h"
#include "colorbw.h"
#include "getsetpixel.h"

#define getByte(value, n) (value >> (n*8) & 0xFF)

float lerp(float s, float e, float t)
{
    return s+(e-s)*t;
}

float blerp(float c00, float c10, float c01, float c11, float tx, float ty)
{
    return lerp(lerp(c00, c10, tx), lerp(c01, c11, tx), ty);
}


//Gray formula applicated to each pixel.
void grayscale(SDL_Surface* image)
{
    int height = image->h;
    int width = image->w;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Uint32 px = get_pixel(image, x, y);
            Uint8 r = 0, g = 0, b = 0;
            SDL_GetRGB(px, image->format, &r, &g, &b);
            Uint8 gray = r * 0.3 + g * 0.58 + b * 0.11; 
            /*The "px" value is made
              3 values, the first for the red value, 
              the second for the green value and the last for the blue value  */
            px = SDL_MapRGB(image->format, gray, gray, gray);
            set_pixel(image, x, y, px);
        }

    }

}



void black_white(SDL_Surface* image)//Suppression of colors.
{
    int width = image->w;//width
    int height = image->h;//height

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++) 
        {
            Uint32 tmp = get_pixel(image, i, j);/*We get the pixel
                                                  at the position (i;j)*/
            Uint8 red, green, blue;/*We declare those variables to
                                     store the r, g and b of the tmp pixel.*/
            SDL_GetRGB(tmp, image->format, &red, &green, &blue);
            /*The
              SDL_GetRGB function allows us to get the rgb values 
              from a pixel, here from 'tmp'.*/
            int k = (red + blue + green) / 3;
            if (k > 127) /*Means the average color of the pixel is
                           closest to white than black*/
            {
                tmp = SDL_MapRGB(image->format, 255, 255, 255);
                set_pixel(image, i, j, tmp);
            }
            else
            {
                tmp = SDL_MapRGB(image->format, 0, 0, 0);
                set_pixel(image, i, j, tmp);
            }
        }
    }


}

void noise(SDL_Surface *img)
{
    int height = img->h;
    int width = img->w;
    /*
    //First we put the picture on grayscale
    for (int y = 0; y < height; y++)
    {
    for (int x = 0; x < width; x++)
    {
    Uint32 pixel = get_pixel(img, x, y);
    Uint8 r, g, b;
    SDL_GetRGB(pixel, img->format, &r, &g, &b);
    int average = r*0.3 + g*0.59 + b*0.11;
    pixel = SDL_MapRGB(img->format, average, average, average);
    set_pixel(img, x, y, pixel);
    }
    }
     */
  //  grayscale(img);
    for (int y = 1; y < height -1; y++)
    {
        for (int x = 1; x < width -1 ; x++)
        {
            //For each pixel, we put the pixel and the values of its 8 neighbors in an array
            Uint32 pixel = get_pixel(img, x, y);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, img->format, &r, &g, &b);
            if(pixel == 0 || pixel == 255)
            {
                int z = (get_pixel(img, x+1, y)
                + get_pixel(img, x+1, y-1)
                + get_pixel(img, x, y-1)
                + get_pixel(img, x-1, y-1)
                + get_pixel(img, x-1, y)
                + get_pixel(img, x-1, y+1)
                + get_pixel(img, x, y+1)
                + get_pixel(img, x+1, y+1))/8;
                Uint8 r, g, b;
                SDL_GetRGB(z, img->format, &r, &g, &b);
                pixel = SDL_MapRGB(img->format, r, g, b);
                set_pixel(img, x, y, pixel);
            }
            //We put the median value of the array (the fourth) as the new pixel
        }
    }
}




void otsu(SDL_Surface *img)
{

    int height = img->h;
    int width = img->w;

    float g = height * width;



    int hist[256] = { 0 };

    //Histogram of grayscales of the pictures
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {       Uint32 pixel = get_pixel(img, x, y);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, img->format, &r, &g, &b);
            int average = r*0.3 + g*0.59 + b*0.11;
            average = average / 1;
            hist[average] += 1;
        }
    }





    //On cherche le maximum et le minimum de l'histogramme
    int min = 0;
    int max = 0;
    for (int u = 0; u < 256; u++)
    {
        if(min > hist[u]){
            min = hist[u];}
        if(max < hist[u]){
            max = hist[u];}

    }

    //Normalization of the histogram, to put all the values between 0 and 1
    float hist1[256] = { 0 };
    for (int z = 1; z < 256; z++)
    {
        float z2 = hist[z];
        hist1[z] = (float)(z2/g) ;

    }



    float var[256] = {0};
    for (int k = 2; k < 255; k++)//k is the separator of the two classes, C1 and C2
    {
        //We calculate the probabilty of a value to be in the C1 class
        float pc1 = 0;
        int ct = 0;
        int er1 = 0;
        for(int a = 0; a<=k; a++){
            pc1 += hist1[a];
            ct += a * hist[a];
            er1 += hist[a];
        }
        float pc2 = 1 - pc1;

        //We calculate the within - class variance
        float u1 = 0;
        float u2 = 0;
        for(int a = 2; a<=k; a++){
            u1 += (a*hist1[a]) / pc1;
        }
        for(int a = k + 1; a< 255; a++){
            u2 += (a*hist1[a]) / pc2;
        }
        float o1 = 0;
        float o2 = 0;
        for(int a = 2; a<=k; a++){
            o1 += ((a - u1) * (a - u1))* (hist1[a]/pc1) ;
        }
        for(int a = k + 1; a< 255; a++){
            o2 += ((a - u2) * (a - u2))* (hist1[a]/pc2) ;
        }
        float var11 = pc1*o1 + pc2*o2;
        //We put the variance in the good place of the array
        var[k] = var11;
    }

    //We search the minimum value of within-class variance,
    //which is also the maximum value of between-class variance
    int max2 = 3;
    for(int u = 20; u < 255; u++)
    {
//        printf("%.6f %.6f \n", var[max2], var[u]);
        if(var[max2] > var[u])
        {
            max2 = u;
        }

    }

    //Then, we get all the pixels of the picture, if they are greater than the variance, they become white, else, they become black

    printf("%d", max2);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Uint32 pixel = get_pixel(img, x, y);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, img->format, &r, &g, &b);
            int average = (r + g + b) / 3 ;
            if(average > max2){
                pixel = SDL_MapRGB(img->format, 255, 255, 255);
                set_pixel(img, x, y, pixel);}
            else{
                pixel = SDL_MapRGB(img->format, 0, 0, 0);
                set_pixel(img, x, y, pixel);}


        }
    }




}



SDL_Surface* Resize(SDL_Surface *img, float scalex, float scaley)
{
  SDL_Surface *dest;
  dest = img;
  int newW = (int)img->w * scalex;
  int newH = (int)img->h * scaley;
  int x, y;
  for(x=0, y=0; y<newH; x++)
      {
        if(x>newW) {
            x = 0;
            y ++;
        }
        float gx = x/(float)(newW)*(img->w-1);
        float gy = y/(float)(newH)*(img->h-1);
        int gxi = (int)gx;
        int gyi = (int)gy;
        uint32_t result = 0;
        uint32_t c00 = get_pixel(img, gxi, gyi);
        uint32_t c10 = get_pixel(img, gxi+1, gyi);
        uint32_t c01 = get_pixel(img, gxi, gyi+1);
        uint32_t c11 = get_pixel(img, gxi+1, gyi+1);
        uint8_t i;
        for(i=0; i<3;i++)
            {
                result |= (uint8_t)blerp(getByte(c00, i), getByte(c10, i), 
                getByte(c01, i), getByte(c11, i), gx-gxi, gy-gyi)<<(8*i);
            }
            set_pixel(dest, x, y, result);
      }
      return dest;
}






