




#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


#define SEQUENCE_SIZE 10
#define MAX_LIMIT 9


int main(){

    int subsequence_max_size = 1;
	
    int current;
    if (scanf("%d", &current) != 1){
       printf("Wrong input!\n");
       abort();
    }
    if (current < 0 or current > MAX_LIMIT){
        printf("Out of range!\n");
        abort();
    }

	int current_size = 1;
    int i = 1;
    while (i < SEQUENCE_SIZE){
    	int previous = current;
	    if (scanf("%d", &current) != 1){
	       printf("Wrong input!\n");
	       abort();
	    }
	    if (current < 0 or current > MAX_LIMIT){
	        printf("Out of range!\n");
	        abort();
	    }
		if (current >= previous){
			current_size++;
			if (current_size > subsequence_max_size){
				subsequence_max_size = current_size;
			}
		}
		else {
			current_size = 1;
		}
		    
	    i++;
	}
    printf("%d\n", subsequence_max_size);
}
