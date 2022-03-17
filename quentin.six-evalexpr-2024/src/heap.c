#include "evalexpr.h"
#include <stdio.h>
#include <stdlib.h>

struct heap *create_heap(size_t c)
{
  struct heap *new = malloc(sizeof(struct heap));
  if (new == NULL)
    return NULL;
  new->size = 0;
  int *array = malloc(sizeof(int) * c);
  if (array == NULL)
    return NULL;
  new->array = array;
  new->capacity = c;
  return new;
}

void delete_heap(struct heap *heap)
{
  if (heap)
  {
    free(heap->array);
    free(heap);
  }
}

void pop(struct heap *heap)
{
    heap->size--;
}

void add(struct heap *heap, int val)
{
  heap->array[heap->size] = val;
  heap->size++;
}

void print_heap(struct heap *heap)
{
  if (heap && heap->size > 0)
  {
    printf("%d", heap->array[0]);
    for (size_t i = 1; i < heap->size - 1; i++)
    {
      printf(" %d", heap->array[i]);
    }
    printf(" %d", heap->array[heap->size - 1]);
  }
  printf("\n");
}
/*
int main()
{
    struct heap *tmp = create_heap(500);
    add(tmp, 1);
    add(tmp, 2);
    add(tmp, 3);
    add(tmp, 4);
    add(tmp, 5);
    add(tmp, 6);
    print_heap(tmp);
    pop(tmp);
    pop(tmp);
    print_heap(tmp);
    delete_heap(tmp);
    return 0;
}
*/
