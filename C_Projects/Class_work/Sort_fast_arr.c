#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iso646.h>


void merge (int *arr, size_t left, size_t middle, size_t right);



int main(){
    int arr[8] = {1, 1, 5, 7, 1, 2, 4, 6};
    merge(arr, 0, 3, 7);
    for(size_t i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    getchar();
}


void merge (int *arr, size_t left, size_t middle, size_t right){
    assert (arr != NULL);

    size_t left_size = middle - left +1;
    size_t right_size = right - middle;

    int *left_subarray = (int *)malloc(sizeof(int) * left_size);
    if (NULL == left_subarray){
        abort();
    } 
    int *right_subarray = (int *)malloc(sizeof(int) * right_size);
    if (NULL == right_subarray){
        abort();
    }

    for (size_t i = 0; i < left_size; i++){
        left_subarray[i] = arr[left + i];
    }
    for (size_t i = 0; i < right_size; i++){
        right_subarray[i] = arr[middle + i + 1];
    }
    
    size_t l = 0;
    size_t r = 0;
    size_t i = 0;

    while(l < left_size and r < right_size){
        if (left_subarray[l] <= right_subarray[r]){
            arr[i] = left_subarray[l];
            l++;
        }
        else {
            arr[i] = right_subarray[r];
            r++;
        }
        i++;
    }
    while (l < left_size){
        arr[i] = left_subarray[l];
        i++;
        l++;
    }
    while (r < right_size){
        arr[i] = right_subarray[r];
        r++;
        i++;
    }

    free(left_subarray);
    free(right_subarray);
}