#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "unlimited_stack.h"
#include "error.h"


#define DATA_SIZE 4


int main(){
    int data[DATA_SIZE] = {7, 4, -5, 0};
    error_t error;

    UnlimitedStack *stack = NULL;
    stack = UnlimitedStack_new(&error);
    assert(SUCCESS == error);
    assert(NULL != stack);

    size_t size = UnlimitedStack_get_size(stack, &error);
    assert(SUCCESS == error);
    assert(0 == size);

    bool is_empty = UnlimitedStack_is_empty(stack, &error);
    assert(SUCCESS == error);
    assert(is_empty);

    for(size_t i = 0; i < DATA_SIZE; i++){
        UnlimitedStack_push(stack, data[i], &error);
        assert(SUCCESS == error);
        size = UnlimitedStack_get_size(stack, &error);
        assert(SUCCESS == error);
        assert(i + 1 == size);
        is_empty = UnlimitedStack_is_empty(stack, &error);
        assert(SUCCESS == error);
        assert(not is_empty);
    }
    printf("top | ");
    UnlimitedStack_print(stack, &error);
    assert(SUCCESS == error);

    for(size_t i = 0; i < DATA_SIZE; i++){
        int item = UnlimitedStack_pop(stack, &error);
        assert(item == data[DATA_SIZE -i - 1]);
        assert(SUCCESS == error);
        printf("top | ");
        UnlimitedStack_print(stack, &error);
        assert(SUCCESS == error);
    }
    
    is_empty = UnlimitedStack_is_empty(stack, &error);
    assert(SUCCESS == error);
    assert(is_empty);

    UnlimitedStack_delete(&stack, &error);
    assert(SUCCESS == error);
    assert(NULL == stack);

    printf("\n%s done!\n", __FILE__);
    return 0;
}