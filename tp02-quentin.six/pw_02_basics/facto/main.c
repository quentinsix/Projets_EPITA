#include "facto.h"

int main()
{
  for(int i=0; i<=20;i++)
    {
      printf("fact(%d) = %lu\n",i,facto(i));
    }
  
  return 0;
}
