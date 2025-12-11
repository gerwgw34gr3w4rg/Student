/*
    Numbers in the range from 0 to 100 mixed with non-numbers are received at the input through a space.
    If 0 comes, all numbers must be printed in reverse order and the program terminated.
    If a non-number comes, all numbers that came must be printed in reverse order.
    It is known that there will be no more than 10 entities (numbers and non-numbers) at the input.
*/


#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>


#include "ascii_to_uint64.c"


#define BUFFER (size_t)4 * 1000
#define STACK_SIZE (size_t)10


void print_stack(const uint64_t *stack, size_t stack_pointer);


int main(){
    printf("Hello\n");
    const uint64_t MIN = (uint64_t)0;
    const uint64_t MAX = (uint64_t)100;

    bool is_convertion_valid;
    uint64_t number;
    char digits[BUFFER] = {0}; // В совокупности с scanf() это говнокод
    uint64_t stack[STACK_SIZE];
    size_t stack_pointer = (size_t)0;
    for(;;){
        if(scanf("%s", digits) != 1){
            fprintf(stderr, "Input error\n");
            abort();
        }
        ascii_to_uint64((const char *)digits, &number, &is_convertion_valid);
        if(is_convertion_valid and (number < MIN or number > MAX)){
            fprintf(stderr, "Input error\n");
            abort();
        }
        else if(is_convertion_valid and 0 == number){
            print_stack((const uint64_t *)stack, stack_pointer);
            return 0;
        }
        else if(is_convertion_valid){
            stack[stack_pointer++] = number;
        }
        else if(not is_convertion_valid){
            print_stack((const uint64_t *)stack, stack_pointer);
        }
        else{
            fprintf(stderr, "fix this bug\n");
            abort();
        }

    }
}


void print_stack(const uint64_t *stack, size_t stack_pointer){
    if(NULL == stack){
        fprintf(stderr, "Null pointer at %s: %d line\n", __FUNCTION__, __LINE__ - 1);
        abort();
    }
    for(size_t i = stack_pointer - 1; i < stack_pointer; i--){
        printf("%" PRIu64 " ", stack[i]);
    }
    printf("\n");
}