#include "divisor_sum.h"

unsigned long divisor_sum(unsigned long num){

 
    
    unsigned long int result = 1; 
   
    // Find all divisors and add them 
    for (unsigned long int i=2; i*i<=num; i++) 
    { 
        if (num%i==0) 
        { 
            if(i*i!=num) 
                result = result + i + num/i; 
            else
                result=result+i; 
        } 
    } 

    if(num==1){
    	return 0;
    }
    return result;
}
