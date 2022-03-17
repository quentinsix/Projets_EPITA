# ifndef _INSERT_SORT_H_
# define _INSERT_SORT_H_

# include <stdlib.h>
# include <string.h>

# include "helper.h"

// Insertion using the plain algorithm.
void array_insert(int *begin, int *end, int x);

// Insertion using the binary-search algorithm.
void array_insert_bin(int *begin, int *end, int x);

// Insertion sort using plain method.
void array_insert_sort(int *begin, int *end);

// Insertion sort using binary search.
void array_insert_sort_bin(int *begin, int *end);

# endif