#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void reverse(int *arr, const size_t size);


int main(){
    size_t size;
    if (scanf("%zu", &size) != 1){
        abort();
    }
    assert (size < 100);
    int arr[size];
    for (size_t i = 0; i < size; i ++){
        if (scanf("%d", arr + i) != 1){
            abort();
        }
    }

    reverse(arr, size);

    for (size_t i = 0; i < size; i ++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    getchar();
}

void reverse(int *arr, const size_t size){
    if (NULL == arr){
        return;
    }

    for (size_t i = 0; i < size / 2; i++){
        int tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}