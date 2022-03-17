#ifndef EVALEXPR_H
#define EVALEXPR_H

// size_t
#include <stddef.h>

int Appartient(char c);
int IsStrCorrect(char *str);
char *NormalToRPN(char *str, char *str1);
int RPN(char *buf);


struct heap
{
  size_t size;
  size_t capacity;
  int *array;
};

struct heap *create_heap(size_t c);
void add(struct heap *heap, int val);
void pop(struct heap *heap);
void delete_heap(struct heap *heap);
void print_heap(struct heap *heap);

void add_vector(struct heap *v);
void sub_vector(struct heap *v);
void mult_vector(struct heap *v);
void pow_vector(struct heap *v);
void div_vector(struct heap *v);
void rest_vector(struct heap *v);

#endif /* !EVALEXPR_H */
