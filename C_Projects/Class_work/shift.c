



#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>

//hw3_arrays Exercise №2


int main(){
    const int MIN_ARR = 1, MAX_ARR = 100;
    int size_arr;
    printf("Enter the size (quantity) of sequence from %d to %d\n",
    		MIN_ARR, MAX_ARR);
    if (scanf("%d", &size_arr) != 1 or size_arr < MIN_ARR or size_arr > MAX_ARR){
        printf("It was necessary to enter one number from %d to %d, "
               "this would be a limitation on the number "
               "of subsequent numbers entered\n", MIN_ARR, MAX_ARR);
        abort();
    }
    int arr[size_arr];
    const int MIN_NUMBER = 0, MAX_NUMBER = 100;
    printf("Enter %d numbers from %d to %d\n", size_arr, MIN_NUMBER, MAX_NUMBER);
    for (int i = 1; i < size_arr; i++){
        if (scanf("%d", &arr[i]) != 1
        		or arr[i] < MIN_NUMBER or arr[i] > MAX_NUMBER){
            printf("You had to enter %d numbers from %d to %d\n",
            		size_arr, MIN_NUMBER, MAX_NUMBER);
            abort();
        }
    }
    if (scanf("%d", &arr[0]) != 1 or arr[0] < MIN_NUMBER or arr[0] > MAX_NUMBER){
        printf("You had to enter %d numbers from %d to %d\n",
        		size_arr, MIN_NUMBER, MAX_NUMBER);
        abort();
    }
    for (int i = 0; i < size_arr; i++){
        printf("%d ", arr[i]);
    }
}
