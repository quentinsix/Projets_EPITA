#include "is_perfect_number.h"
#include "divisor_sum.h"

int is_perfect_number(unsigned long n)
{
  return (int)divisor_sum(n);
}
