



#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>


int main()
{
	const int MIN_NUMBER = 0;
	const int MAX_NUMBER = 100;
	const int SEQUENCE_SIZE = 10; 

    printf("Enter %d integers from %d to %d, separated by spaces.\n",
    		SEQUENCE_SIZE, MIN_NUMBER, MAX_NUMBER);
	
    int custom_number;
	int check_number = 0;
    int counter = 0;
    while(counter < SEQUENCE_SIZE){
        if(scanf("%d", &custom_number) != 1
       			or custom_number < MIN_NUMBER or custom_number > MAX_NUMBER){
            printf("You had to enter a number from %d to %d\n", MIN_NUMBER, MAX_NUMBER);
            abort();
        }
        if (custom_number >= check_number){
            check_number = custom_number;
        }
        else {
            printf("Unsorted\n");
            return 0;
        }
        
        counter = counter + 1;
    }
    printf("Sorted\n");


    return 0;
}
