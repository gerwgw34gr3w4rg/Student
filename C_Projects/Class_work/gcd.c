



#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


int main()
{
    const int MIN_NUM = -1000000, MAX_NUM = 1000000;
    int custom_num_1, custom_num_2;
    printf("Enter two numbers from %d to %d\n", MIN_NUM, MAX_NUM);
    if (scanf("%d %d", &custom_num_1, &custom_num_2) != 2 or
    		custom_num_1 < MIN_NUM or custom_num_1 > MAX_NUM
    		or custom_num_2 < MIN_NUM or custom_num_2 > MAX_NUM){
        printf("It was necessary to enter two numbers from %d to %d\n", MIN_NUM, MAX_NUM);
        abort();
    }

	if (0 == custom_num_1 and 0 == custom_num_2){
		printf("Undefined!\n");
		return 0;
    }
    const char *COMMON_DIVISOR = "Greatest common divisor";
    if (custom_num_1 < 0){
        custom_num_1 = -custom_num_1;
    }
    if (custom_num_2 < 0){
        custom_num_2 = -custom_num_2;
    }
    if (custom_num_1 == 0){
        printf("%s %d\n", COMMON_DIVISOR, custom_num_2);
        return 0;
    }
   	if (custom_num_2 == 0){
        printf("%s %d\n", COMMON_DIVISOR, custom_num_1);
        return 0;
    }
    
    while (custom_num_2 != 0){
    	int tmp = custom_num_2;
    	custom_num_2 = custom_num_1 % custom_num_2;
    	custom_num_1 = tmp;
    }
    printf("%d\n", custom_num_1);
}




