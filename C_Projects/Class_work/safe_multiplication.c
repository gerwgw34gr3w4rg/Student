



#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


unsigned uint_safe_add(unsigned term1, unsigned term2, bool *is_overflow){
	if (NULL == is_overflow){
		fprintf(stderr, "NULL pointer error in %s!\n", __FUNCTION__);
		abort();
	}
	unsigned sum = term1 + term2;
	if (sum < term1){
		*is_overflow = true;
	}
	else {
		*is_overflow = false;
	}
	return sum;
}


int main(){
	unsigned a, b;
	scanf("%u %u", &a, &b);
	bool is_overflow;
	unsigned sum = uint_safe_add(a, b, &is_overflow);
	if (is_overflow){
		printf("Overflow!\n");
	}
	printf("%u + %u = %u\n", a, b, sum);
	printf("Bye!\n");
}
