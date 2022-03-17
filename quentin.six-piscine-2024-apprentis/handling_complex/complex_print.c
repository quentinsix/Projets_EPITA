#include "complex_print.h"

#include <stdio.h>

#include "complex.h"

void print_complex(struct complex a)
{
    if (a.img < 0)
        printf("complex(%.2f - %.2fi)\n", a.real, -a.img);
    else
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
}
/*
int main()
{
    struct complex a =
    {
        .real = 1,
        .img = 2,
    };
    print_complex(a);
    a.real = -1;
    a.img = -2;
    print_complex(a);
    return 0;
}
*/
