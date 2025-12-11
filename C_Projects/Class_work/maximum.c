





#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


#define SEQUENCE_SIZE 10
#define MAX_LIMIT 100


int main(){

	int maximum = 0;
	int i = 0;
	while (i < SEQUENCE_SIZE){
		int n;
		if (scanf("%d", &n) != 1){
			printf("Wrong input!\n");
			abort();
		}
		if (n < 0 or n > MAX_LIMIT){
			printf("Out of range!\n");
			abort();
		}
		if (n > maximum){
			maximum = n;
		}
		i++;
	}
	printf("%d\n", maximum);
}
