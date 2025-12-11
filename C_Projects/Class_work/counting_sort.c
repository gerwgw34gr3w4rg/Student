




#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>


#define MIN_NUMBER 0  // Should be positive
#define MAX_NUMBER 9  // Should be positive
#define RANGE MAX_NUMBER - MIN_NUMBER + 1

#define SEQUENCE_SIZE_LIMIT 1000


void fill_arr(int *arr, size_t size);
void print_arr(int *arr, size_t size);
void counting_sort(int *arr, const size_t size, const size_t limit);

 
int main(){
	int sequence_size;
	if (scanf("%d", &sequence_size) != 1
			or sequence_size < 0 or sequence_size > SEQUENCE_SIZE_LIMIT){
		printf("Wrong input!\n");
		abort();
	}
	int *arr = (int *)malloc(sizeof(int) * sequence_size);
	if (NULL == arr){
		printf("Not enough meory\n");
		abort();
	}

	fill_arr(arr, sequence_size);
	counting_sort(arr, sequence_size, RANGE);
	print_arr(arr, sequence_size);
	free(arr);
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


void counting_sort(int *arr, const size_t size, const size_t limit){
	if (NULL == arr){
        return;
    }
    unsigned counters[limit];
    for (size_t i = 0; i < limit; i++){
    	counters[i] = 0;
    }
    for (size_t i = 0; i < size; i++){
    	if (arr[i] < MIN_NUMBER or arr[i] > MAX_NUMBER){
    		return;
    	}
    	counters[arr[i]]++;
    }
    size_t k = 0;
    for (size_t i = 0; i < limit; i++){
    	for (unsigned j = 0; j < counters[i]; j++){
    		arr[k++] = (int)i;
    	}
    }
}
