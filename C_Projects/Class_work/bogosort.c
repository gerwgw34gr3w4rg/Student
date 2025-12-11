#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iso646.h>
#include <stdbool.h>


void shuffle(int *arr, size_t size);
void fill_arr(int *arr, size_t size);
void print_arr(int *arr, size_t size);
bool is_sorted(int *arr, size_t size);
void bogosort(int *arr, size_t size);


int main(){
	int size;
	if (scanf("%d", &size) != 1 or size < 1 or size > 100){
		printf("Wrong input!\n");
		abort();
	}
	int arr[size];
	fill_arr(arr, (size_t)size);
	bogosort(arr, (size_t)size);
	print_arr(arr, (size_t)size);
}


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


void fill_arr(int *arr, size_t size){
	if (NULL == arr){
		return;
	}
	for (size_t i = 0; i < size; i++){
		if (scanf("%d", arr + i) != 1){
			printf("Wrong input!\n");
			abort();
		}
	}
}


void print_arr(int *arr, size_t size){
	if (NULL == arr){
		return;
	}
	for (size_t i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


bool is_sorted(int *arr, size_t size){
	if (NULL == arr){
		printf("NULL pointer error!\n");
		abort();
	}
	for (size_t i = 1; i < size; i++){
		if (arr[i] < arr[i - 1]){
			return false;
		}
	}
	return true;
}


void bogosort(int *arr, size_t size){
	if (NULL == arr){
		printf("NULL pointer error!\n");
		abort();
	}
	while (not is_sorted(arr, size)){
		shuffle(arr, size);
	}
}
