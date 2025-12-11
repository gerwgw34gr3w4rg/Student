#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

void print_array(int *array, size_t size);
void fill_array(int *array, size_t size);
void reverse_array(int *array, size_t size);

int main(){
	int tmp_size;
	if (scanf("%d", &tmp_size) != 1 or tmp_size < 0){
		fprintf(stderr, "Wrong input!\n");
		abort();
	}
	size_t array_size = (size_t)tmp_size;
	int array[array_size];
	fill_array(array, array_size);
	reverse_array(array, array_size);
	print_array(array, array_size);
}


void print_array(int *array, size_t size){
	if (NULL == array){
		return;
	}
	for (size_t i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}


void fill_array(int *array, size_t size){
	if (NULL == array){
		return;
	}
	for (size_t i = 0; i < size; i++){
		if (scanf("%d", array + i) != 1){
			fprintf(stderr, "Wrong input!\n");
			abort();
		}
	}	
}


void reverse_array(int *array, size_t size){
	if (NULL == array){
		return;
	}
	for (size_t i = 0; i < size / 2; i++){
		int tmp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = tmp;
	}
}
