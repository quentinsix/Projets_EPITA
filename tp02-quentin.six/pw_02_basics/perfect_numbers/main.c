#include "is_perfect_number.h"
#include "divisor_sum.h"

int main (){

	  for(int i=1; i<=100000;i++)
	    {
	      if(i==is_perfect_number(i))
		{
		  printf("%d\n",i);
		}
	    }
	
  return 0;
}
