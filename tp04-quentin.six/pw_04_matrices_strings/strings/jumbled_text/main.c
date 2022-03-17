#include "mix.h"
#include <err.h>

int main(int argc, char** argv)
{
    if(argc==2)
    {
        mix(argv[1]);
    }
    else
    {
        mix("This is the default text");
    }
    return 0;
}
