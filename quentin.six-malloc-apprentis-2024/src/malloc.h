#ifndef MALLOC_H
#define MALLOC_H

//#include <sys/types.h>
//#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef struct s_blockmem {
  int free;
  size_t size;
  void *ptr;
  struct s_blockmem *next;
} t_blockmem;

void *mov_sbrk(int increment);

t_blockmem *search_memory(size_t size);
void add_last(t_blockmem *p);
t_blockmem *alloc(size_t size);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);

#define SIZE_BLOCK sizeof(struct s_blockmem)

#endif /* !MALLOC_H */
