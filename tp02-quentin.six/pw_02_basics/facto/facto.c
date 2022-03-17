#include "facto.h"


unsigned long facto(unsigned long n){
  unsigned long fact = 1;
  for (unsigned long i = 1; i <= n; ++i)
   {
     fact *= i;
   }
  return fact;
}
