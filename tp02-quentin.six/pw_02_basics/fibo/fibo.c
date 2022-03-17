#include "fibo.h"


unsigned long fibo(unsigned long n){
	unsigned long a = 0, b = 1;

  unsigned long tmp;
  while (n--) 
  {
    tmp = a+b;
    a = b;
    b = tmp;
  }
  return a;

}
