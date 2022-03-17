#include <string.h>
#include "Init/chargnbimage.h"
#include "Init/getsetpixel.h"
#include "Init/colorbw.h"
#include "Separation/segmentation.h"
#include "Separation/extraction.h"
#include "Interface/gtk.h"


void help()
{
    printf("This is ekip 667\n");
    printf("type make\n");
    printf("Type ./main *path to image* --sdl\n ###To use SDL and see the steps\n");
    printf("Type ./main \n ###To use the user interface\n");
    printf("Enjoy\n");
}
int main(int argc, char** argv)
{
    help();
    if (argc == 1)
    {
        create_gtk(argc, argv);
//        return EXIT_SUCCESS;
    } else if (argc > 1)
    {
        if (strcmp(argv[2], "--sdl") == 0)
        {
            SDL_Surface* img;
            SDL_Window* screen;

            img = charg_img(argv[1]);
            screen = disp_img(img);
            wait_for_keypressed();

            grayscale(img);//Showing the gray
            SDL_BlitSurface(img, NULL, SDL_GetWindowSurface(screen),0);
            SDL_UpdateWindowSurface(screen);
            wait_for_keypressed();
            //SDL_SaveBMP(img, "gray.bmp");

               noise(img);
               SDL_BlitSurface(img, NULL, SDL_GetWindowSurface(screen), 0);
               SDL_UpdateWindowSurface(screen);
               wait_for_keypressed();
 
/*
            otsu(img);
            SDL_BlitSurface(img, NULL, SDL_GetWindowSurface(screen), 0);
            SDL_UpdateWindowSurface(screen);
            wait_for_keypressed();
*/
             black_white(img);//Changing to black and white
            SDL_BlitSurface(img, NULL, SDL_GetWindowSurface(screen), 0);
            SDL_UpdateWindowSurface(screen);
            wait_for_keypressed();

            seg_hor(img);//Segmenting and extracting.
            SDL_BlitSurface(img, NULL, SDL_GetWindowSurface(screen), 0);
            SDL_UpdateWindowSurface(screen);
            wait_for_keypressed();
            //        SDL_SaveBMP(img, "seg.bmp");



  //          return 0;
        }else if (strcmp(argv[1], "--help") == 0)
        {
            help();
        }
        else
        {
            printf("Too few arguments");
        }
    }
    else 
    {
        printf("Type --help too see commands");
    //    return 1;
    }
return EXIT_SUCCESS;
}
