



#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <assert.h>


void read_int(int *value, const int MIN, const int MAX);
void fill_arr(int *arr, size_t size, const int MIN, const int MAX);
void print_arr(int *arr, size_t size);


int main(){
    const int ARR_SIZE_MIN = 1, ARR_SIZE_MAX = 100;
    int arr_size;
    printf("Enter the sequence size from %d to %d\n", ARR_SIZE_MIN, ARR_SIZE_MAX);
    read_int(&arr_size, ARR_SIZE_MIN, ARR_SIZE_MAX);

    const int ARR_SHIFT_MIN = -100, ARR_SHIFT_MAX = 100;
    int arr_shift;
    printf("Enter a number between %d and %d by which the sequence will be shifted\n",
    		ARR_SHIFT_MIN, ARR_SHIFT_MAX);
    read_int(&arr_shift, ARR_SHIFT_MIN, ARR_SHIFT_MAX);
	assert(arr_size > 0);
    arr_shift %= arr_size;
    if (arr_shift < 0){
    	arr_shift += arr_size;
    }

	int *arr = (int *)malloc(sizeof(int) * arr_size);
	if (NULL == arr){
		fprintf(stderr, "Not enough memory!\n");
		abort();
	}
	const int NUM_MIN = 0, NUM_MAX = 100;
	printf("Enter %d numbers from %d to %d\n", arr_size, NUM_MIN, NUM_MAX);
	fill_arr(arr + arr_shift, arr_size - arr_shift, NUM_MIN, NUM_MAX);
	fill_arr(arr, arr_shift, NUM_MIN, NUM_MAX);
	print_arr(arr, arr_size);
}


void read_int(int *value, const int MIN, const int MAX){
	if (NULL == value){
		fprintf(stderr, "NULL pointer error!\n");
		abort();
	}
	if (scanf("%d", value) != 1 or *value < MIN or *value > MAX){
		printf("You had to enter a number from %d to %d\n", MIN, MAX);
		abort();
	}
}



void fill_arr(int *arr, size_t size, const int MIN, const int MAX){
    if (NULL == arr){
        return;
    }
    for (size_t i = 0; i < size; i++){
        read_int(arr + i, MIN, MAX);
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
