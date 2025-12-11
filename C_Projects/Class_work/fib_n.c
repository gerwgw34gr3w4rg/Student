



#include <stdio.h>
#include <stdlib.h>


#define LIMIT 47  // The largest Fibonacci number that fits into a 32-bit unsigned integer


unsigned fib(unsigned n);


int main(){
	for (unsigned i = 0; i < 50; i++){
		printf("%u: %u\n", i, fib(i));
	}
	printf("\n");
}


unsigned fib(unsigned n){
	if (n > LIMIT){
		fprintf(stderr, "Impossible to calculate %s(%u)!\n", __FUNCTION__, n);
		abort();
	}
	if (0 == n){
		return 0;
	}
	unsigned previous = 0;
	unsigned next = 1;
	while (n > 1){
		unsigned tmp = next;
		next += previous;
		previous = tmp;
		n--;
	}
	return next;
}
