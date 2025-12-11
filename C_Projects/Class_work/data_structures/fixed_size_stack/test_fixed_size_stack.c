#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


#include "fixed_size_stack.h"
#include "error.h"


#define DATA_SIZE (size_t)5


int main(){
    const size_t BUFFER_SIZE = (size_t)50;
    const int data[DATA_SIZE] = {5, 8, 1, -55, 14};
    error_t error;

    FixedSizeStack *stack = FixedSizeStack_new(BUFFER_SIZE, &error);
    assert(NULL != stack);
    assert(SUCCESS == error);
    assert(NULL != stack -> buffer);
    assert(BUFFER_SIZE == stack -> buffer_size);
    assert(0 == stack -> size);

    assert(0 == FixedSizeStack_get_size(stack, &error));
    assert(SUCCESS == error);

    FixedSizeStack_peek(stack, &error);
    assert(COLLECTION_IS_EMPTY_ERROR == error);
    assert(0 == stack -> size);

    bool is_stack_empty = FixedSizeStack_is_empty(stack, &error);
    assert(SUCCESS == error);
    assert(true == is_stack_empty);

    for(size_t i = 0; i < DATA_SIZE; i++){
        FixedSizeStack_push(stack, data[i], &error);
        assert(SUCCESS == error);
        assert(stack -> size == i + 1);
        assert(stack -> buffer[stack -> size - 1] == data[i]);
        FixedSizeStack_print(stack, &error);
        assert(SUCCESS == error);
    }

    
    printf("================================================\n");
    assert(DATA_SIZE == FixedSizeStack_get_size(stack, &error));
    assert(SUCCESS == error);
    
    assert(data[DATA_SIZE - 1] == FixedSizeStack_peek(stack, &error));
    assert(SUCCESS == error);
    assert(DATA_SIZE == stack -> size);

    FixedSizeStack_peek(stack, &error);
    assert(SUCCESS == error);

    assert(NULL != stack);
    printf("Last element %u\n", stack -> size);


    is_stack_empty = FixedSizeStack_is_empty(stack, &error);
    assert(SUCCESS == error);
    assert(false == is_stack_empty);

    size_t i = (DATA_SIZE - 1);
    while(not FixedSizeStack_is_empty(stack, &error)){
        assert(SUCCESS == error);
        assert(FixedSizeStack_peek(stack, &error) == data[i]);
        assert(SUCCESS == error);
        assert(i + 1 == stack -> size);
        int item = FixedSizeStack_pop(stack, &error);
        assert(SUCCESS == error);
        assert(data[i] == item);
        assert(stack -> size == i);
        i--;
        
        FixedSizeStack_print(stack, &error);
        assert(SUCCESS == error);
    }

    assert(0 == FixedSizeStack_get_size(stack, &error));
    assert(SUCCESS == error);

    FixedSizeStack_peek(stack, &error);
    assert(COLLECTION_IS_EMPTY_ERROR == error);
    assert(0 == stack -> size);

    FixedSizeStack_delete(&stack, &error);
    assert(SUCCESS == error);
    assert(NULL == stack);

    printf("\n%s done!\n", __FILE__);
}