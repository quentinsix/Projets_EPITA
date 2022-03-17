#include "evalexpr.h"

void add_vector(struct heap *v)
{
  size_t size = v->size;
  int r = v->array[size - 2] + v->array[size - 1];
  pop(v);
  pop(v);
  add(v, r);
}

void sub_vector(struct heap *v)
{
  size_t size = v->size;
  int r = v->array[size - 2] - v->array[size - 1];
  pop(v);
  pop(v);
  add(v, r);
}

void mult_vector(struct heap *v)
{
  size_t size = v->size;
  int r = v->array[size - 2] * v->array[size - 1];
  pop(v);
  pop(v);
  add(v, r);
}

int my_pow(int a, int b)
{
  int result = 1;
  while (b > 0)
  {
    if (b & 1)
      result *= a;
    b = b >> 1;
    a *= a;
  }
  return result;
}

// power à gerer
void pow_vector(struct heap *v)
{
  size_t size = v->size;
  int r = my_pow(v->array[size - 2], v->array[size - 1]);
  pop(v);
  pop(v);
  add(v, r);
}

void div_vector(struct heap *v)
{
  size_t size = v->size;
  int r = v->array[size - 2] / v->array[size - 1];
  pop(v);
  pop(v);
  add(v, r);
}

void rest_vector(struct heap *v)
{
  size_t size = v->size;
  int r = v->array[size - 2] % v->array[size - 1];
  pop(v);
  pop(v);
  add(v, r);
}
