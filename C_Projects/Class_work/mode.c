#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>

#define RANGE 10

//Chapter hw3_arrays, task №1

int main()
{
    const int MIN_NUMBER = 0, MAX_NUMBER = 9;
    const int SIZE_ARR_MIN = 1, SIZE_ARR_MAX = 100;
    int size_arr;
    printf("Enter the number of digits from %d to %d"
           "(the number of digits that you will enter after)\n",
            SIZE_ARR_MIN, SIZE_ARR_MAX);
    if (scanf("%d", &size_arr) != 1
    		or size_arr < SIZE_ARR_MIN or size_arr > SIZE_ARR_MAX){
        printf("It was necessary to enter number from %d to %d\n",
        		SIZE_ARR_MIN, SIZE_ARR_MAX);
        abort();
    }    
    printf("Enter %d numbers from %d to %d\n", size_arr, MIN_NUMBER, MAX_NUMBER);
    int counters[RANGE]	= {0};
    for (int i = 0; i < size_arr; i++){
    	int n;
        if (scanf("%d", &n) != 1 or n < MIN_NUMBER or n > MAX_NUMBER){
            printf("It was necessary to enter %d numbers from %d to %d\n",
                    size_arr, MIN_NUMBER, MAX_NUMBER);
            abort ();
        }
        counters[n]++;
    }
    int max = 0;
    for (int i = 1; i < RANGE; i++){
    	if (counters[i] > counters[max]){
    		max = i;
    	}
    }
    printf("Mode is %d\n", max);
}
