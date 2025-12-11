




#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void shuffle(int *arr, size_t size){
	if (NULL == arr){
		return;
	}
	for (size_t i = size - 1; i > 0; i--){
		int random_index = rand() % (i + 1);
		int tmp = arr[i];
		arr[i] = arr[random_index];
		arr[random_index] = tmp;
	}
}


int main(){
	srand(time(NULL));
	int arr[5] = {1, 2, 3, 4, 5};
	shuffle(arr, 5);
	for (size_t i = 0; i < 5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
