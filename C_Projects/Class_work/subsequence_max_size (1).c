





#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


#define SEQUENCE_SIZE 10
#define MAX_LIMIT 9


int main(){

    int current;
    int subsequence_max_size = 0;
	int subsequence_current_size = 0;
	int previous = 0;
    int i = 0;
    while (i < SEQUENCE_SIZE){
	    if (scanf("%d", &current) != 1){
	       printf("Wrong input!\n");
	       abort();
	    }
	    if (current < 0 or current > MAX_LIMIT){
	        printf("Out of range!\n");
	        abort();
	    }
		if (current >= previous){
			subsequence_current_size++;
			if (subsequence_current_size > subsequence_max_size){
				subsequence_max_size = subsequence_current_size;
			}
		}
		else {
			subsequence_current_size = 1;
		}
    	previous = current;
	    i++;
	}
    printf("%d\n", subsequence_max_size);
}
