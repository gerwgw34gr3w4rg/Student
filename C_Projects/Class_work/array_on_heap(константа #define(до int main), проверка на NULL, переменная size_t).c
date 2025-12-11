



#include <stdio.h>
#include <stdlib.h>


#define ARRAY_SIZE 10 * 1000 * 1000


int main(){
	int *arr = (int *)malloc(sizeof(int) * ARRAY_SIZE);
	if (NULL == arr){
		fprintf(stderr, "Not enough memory!\n");
		return 1;
	}
	for (size_t i = 0; i < ARRAY_SIZE; i++){
		arr[i] = i;	
	}
	for (size_t i = 0; i < ARRAY_SIZE; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	getchar();
}
