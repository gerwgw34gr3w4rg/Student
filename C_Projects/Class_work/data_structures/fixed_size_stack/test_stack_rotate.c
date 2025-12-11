#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "fixed_size_stack.h"
#include "error.h"


typedef struct{
    int *data;
    size_t size;
} TestCase;


void stack_rotate(FixedSizeStack *stack, error_t *error);


int main(void){
    int inputs[3][10] = {
        {1, 2, 3},
        {5. -2. -101},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    };
    TestCase test_cases[3];
    test_cases[0].data = (int *)malloc(sizeof(int) * 3);
    assert(NULL != test_cases[0].data);
    test_cases[0].size = 3;

    test_cases[1].data = (int *)malloc(sizeof(int) * 3);
    assert(NULL != test_cases[0].data);
    test_cases[1].size = 3;

    test_cases[2].data = (int *)malloc(sizeof(int) * 10);
    assert(NULL != test_cases[0].data);
    test_cases[2].size = 10;


    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < test_cases[i].size; j++){
            test_cases[i].data[j] = inputs[i][j];
        }
    }

    for(size_t i = 0; i <3; i++){
        error_t error;
        FixedSizeStack *stack = FixedSizeStack_new(test_cases[i].size, &error);
        assert(SUCCESS == error);

        for(size_t j = 0; j < test_cases[i].size; j++){
            FixedSizeStack_push(stack, test_cases[i].data[j], &error);
            assert(SUCCESS == error);
        }

        FixedSizeStack_print(stack, &error);
        assert(SUCCESS == error);

        stack_rotate(stack, &error);
        assert(SUCCESS == error);

        FixedSizeStack_print(stack, &error);
        assert(SUCCESS == error);

        for(size_t k = 0; k < test_cases[i].size; k++){
            assert(FixedSizeStack_pop(stack, &error) == inputs[i][k]);
            assert(SUCCESS == error);
        }

        FixedSizeStack_delete(&stack, &error);
        assert(SUCCESS == error);
    } 

    for(size_t i = 0; i < 3; i++){
        free(test_cases[i].data);
    }
    return 0;
}