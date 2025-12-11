#include <assert.h>
#include <iso646.h>


#include "fixed_size_stack.h"
#include "error.h"

void stack_rotate(FixedSizeStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack or NULL == stack -> buffer){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    if(FixedSizeStack_is_empty(stack, error)){
        return;
    }

    //
    FixedSizeStack *tmp_stack[2];
    size_t tmp_stack_size = FixedSizeStack_get_size(stack, error);
    if(SUCCESS != *error){
        return;
    }

    tmp_stack[0] = FixedSizeStack_new(tmp_stack_size, error);
    if(SUCCESS != *error){
        return;
    }
    tmp_stack[1] = FixedSizeStack_new(tmp_stack_size, error);
    if(SUCCESS != *error){
        return;
    }

    while(not FixedSizeStack_is_empty(stack, error)){
        assert(SUCCESS == *error);
        int data = FixedSizeStack_pop(stack, error);
        assert(SUCCESS == *error);
        FixedSizeStack_push(tmp_stack[0], data, error);
    }
    while(not FixedSizeStack_is_empty(tmp_stack[0], error)){
        assert(SUCCESS == *error);
        int data = FixedSizeStack_pop(tmp_stack[0], error);
        assert(SUCCESS == *error);
        FixedSizeStack_push(tmp_stack[1], data, error);
    }
    while(not FixedSizeStack_is_empty(tmp_stack[1], error)){
        assert(SUCCESS == *error);
        int data = FixedSizeStack_pop(tmp_stack[1], error);
        assert(SUCCESS == *error);
        FixedSizeStack_push(stack, data, error);
    }
}
