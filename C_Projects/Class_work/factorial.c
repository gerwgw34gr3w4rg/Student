



#include <stdio.h>
#include <stdlib.h>


unsigned factorial(unsigned n);


int main(){
	printf("%u\n", factorial(1));
	printf("%u\n", factorial(5));
}


unsigned factorial(unsigned n){
	if (n > 10){
		fprintf(stderr, "factorial(%u) is too big for unsigned\n", n);
		abort();
	}
	if (n <= 1){
		return 1;
	}
	return n * factorial(n - 1);
}
