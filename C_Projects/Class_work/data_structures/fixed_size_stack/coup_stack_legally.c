#include <iso646.h>


#include "fixed_size_stack.h"
#include "error.h"


void coup(FixedSizeStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL == stack){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    if(NULL != error){
        *error = SUCCESS;
    }
    size_t buffer_size = FixedSizeStack_get_size(stack, error);
    if(NULL != error and SUCCESS != *error){
        return;
    }
    FixedSizeStack *tmp_stack = FixedSizeStack_new(buffer_size, error);
    if(NULL != error and SUCCESS != *error){
        return;
    }

    const size_t iteration = FixedSizeStack_get_size(stack, error);
    if(NULL != error and SUCCESS != *error){
        return;
    }
    for(size_t i = 0; i < iteration; i++){
        size_t box[2];
        box[0] = FixedSizeStack_pop(stack, error);
        if(NULL != error and SUCCESS != *error){
            return;
        }
        for(size_t j = 0; j < iteration - i - 1; j++){
            box[1] = FixedSizeStack_pop(stack, error);
            if(NULL != error and SUCCESS != *error){
                return;
            }
            FixedSizeStack_push(tmp_stack, box[1], error);
            if(NULL != error and SUCCESS != *error){
                return;
            }
        }

        FixedSizeStack_push(stack, box[0], error);
        if(NULL != error and SUCCESS != *error){
            return;
        }
        for(size_t j = 0; j < iteration - i - 1; j++){
            box[1] = FixedSizeStack_pop(tmp_stack, error);
            if(NULL != error and SUCCESS != *error){
                return;
            }
            FixedSizeStack_push(stack, box[1], error);
            if(NULL != error and SUCCESS != *error){
                return;
            }
        }
    }
    FixedSizeStack_delete(&tmp_stack, error);
    if(NULL != error and SUCCESS != *error){
        return;
    }
}