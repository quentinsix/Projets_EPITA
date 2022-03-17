#include "digit_count.h"

unsigned char digit_count(unsigned long n){

	int result=0;

	while (n>0){
		n/=10;
		result++;
	}


	return (unsigned char)(result);
}