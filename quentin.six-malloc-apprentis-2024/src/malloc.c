#include <stddef.h>
#include "malloc.h"

#include <errno.h>

#define MEMORY_CAPACITY 20000

void *mov_sbrk(int increment)
{
    static char global_mem[MEMORY_CAPACITY] = {0};
    static char *p_break = global_mem;

    char *const limit = global_mem + MEMORY_CAPACITY;
    char *const original = p_break;

    if (increment < global_mem - p_break  ||  increment >= limit - p_break)
    {
        errno = ENOMEM;
        return (void*)-1;
    }
    p_break += increment;

    return original;
}




t_blockmem *g_first = NULL;

void		add_last(t_blockmem *p)
{
  t_blockmem	*end;

  end = g_first;
  while (end->next != NULL)
    end = end->next;
  end->next = p;
}

t_blockmem	*alloc(size_t size)
{
  t_blockmem	*ptr;


  //ptr = (t_blockmem *)sbrk(0);
  ptr = (t_blockmem *)mov_sbrk(0);
  if (mov_sbrk(SIZE_BLOCK) == (void*)-1)
    return (NULL);
  ptr->next = NULL;
  ptr->free = 0;
  ptr->size = size;
  ptr->ptr = mov_sbrk(0);
  if (mov_sbrk(size) == (void*)-1)
    return (NULL);
  return (ptr);
}


__attribute__((visibility("default")))
void *malloc(size_t size)
{
    t_blockmem	*p;

    if (g_first != NULL)
    {
        p = search_memory(size);
        if (p == NULL)
        {
            p = alloc(size);
            if (p == NULL)
                return (NULL);
            add_last(p);
        }
        p->free = 0;
    }
    else
    {
        p = alloc(size);
        g_first = p;
    }

    if (p == NULL)
        return (NULL);
    else
        return (p->ptr);

}

t_blockmem	*search_memory(size_t size)
{
  t_blockmem	*base;
  int		 ok;

  base = g_first;
  ok = 0;
  while (ok == 0)
    {
      if (base == NULL)
	ok = -1;
      else if (base->free == 1 && size <= base->size)
	ok = 1;
      else
	base = base->next;
    }
  return (base);
}



__attribute__((visibility("default")))
void free(void *ptr)
{
    t_blockmem	*tmp;

    tmp = g_first;
    while (tmp && tmp->ptr != ptr)
        tmp = tmp->next;
    if (tmp == NULL)
        ptr = NULL;
    else if (tmp->ptr == ptr)
    {
        ptr = memset(ptr, 0, tmp->size);
        tmp->free = 1;
    }
    else
        ptr = NULL;
}

__attribute__((visibility("default")))
void *realloc(void *ptr, size_t size)
{
    void  *new;

    if (ptr == NULL)
        new = malloc(size);
    else if (size == 0)
        free(ptr);
    else
    {
        new = malloc(size);
        if (new != NULL)
            new = memcpy(new, ptr, size);
    }
    return (new);

}

__attribute__((visibility("default")))
void *calloc(size_t nmemb, size_t size)
{
    void *p;

    p = malloc(nmemb * size);
    if (p)
        p = memset(p, 0, nmemb * size);
    return (p);

}
