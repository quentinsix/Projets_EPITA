#include "complex_operations.h"

#include <stddef.h>

#include "complex.h"
#include "complex_print.h"
/*
#include <stdio.h>
*/
struct complex neg_complex(struct complex a)
{
    struct complex z = {
        .img = -a.img,
        .real = -a.real,
    };
    return z;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex z = {
        .img = a.img + b.img,
        .real = a.real + b.real,
    };
    return z;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex z = {
        .img = a.img - b.img,
        .real = a.real - b.real,
    };
    return z;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex z = {
        .real = a.real * b.real - a.img * b.img,
        .img = a.real * b.img + a.img * b.real,
    };
    return z;
}

struct complex div_complex(struct complex a, struct complex b)
{
    float quot = b.img * b.img + b.real * b.real;
    struct complex z = {
        .real = (a.real * b.real + a.img * b.img) / quot,
        .img = (a.img * b.real - a.real * b.img) / quot,
    };
    return z;
}
/*
int main()
{
    struct complex a =
    {
        .real = 1,
        .img = 2,
    };
    print_complex(add_complex(a,a));
    print_complex(neg_complex(a));
    print_complex(sub_complex(a,a));
    return 0;
}
*/
