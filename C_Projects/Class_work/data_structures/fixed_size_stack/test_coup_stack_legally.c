#include <stddef.h>
#include <stdio.h>
#include <assert.h>


#include "fixed_size_stack.h"
#include "error.h"


void coup(FixedSizeStack *stack, error_t *error); // Лёша, почему без этой стрчоки не работает, объясни возможно и на картинках


int main(){
    size_t buffer_size = 10;
    error_t error;

    FixedSizeStack *stack = FixedSizeStack_new(buffer_size, &error);
    assert(SUCCESS == error);

    for(size_t i = 0; i < buffer_size; i++){
        FixedSizeStack_push(stack, (i * 10 + 10), &error);
        assert(SUCCESS == error);
        FixedSizeStack_print(stack, &error);
        assert(SUCCESS == error);
    }

    printf("\n======================================\n\n");
    coup(stack, &error);
    assert(SUCCESS == error);
    FixedSizeStack_print(stack, &error);
    assert(SUCCESS == error);

    FixedSizeStack_delete(&stack, &error);
    assert(SUCCESS == error);
    printf("stack == %p", stack);
}