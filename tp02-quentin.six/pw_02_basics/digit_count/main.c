#include "digit_count.h"
#include "../power_of_two/power_of_two.c"

int main(){

	for (int i =0; i<=63;i++){

		printf("digit_count(%lu) = %lu \n", power_of_two(i),(unsigned long)(digit_count(power_of_two(i))));
	}
	return 0;
}