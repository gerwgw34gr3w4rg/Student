#include "fixed_size_stack.h"
#include <iso646.h>


struct FixedSizeStack {
    int *buffer;
    size_t buffer_size; // максимальное количество элементов
    size_t size; // текущее количество элементов
};

FixedSizeStack *FixedSizeStack_new(size_t buffer_size, error_t *error){
    
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    FixedSizeStack *new_stack = (FixedSizeStack *)malloc(sizeof(FixedSizeStack));
    if(NULL == new_stack){
        if(NULL != error){
            *error = NOT_ENOUGH_MEMORY_ERROR;
        }
        return NULL;
    }
    new_stack -> buffer = (int *)malloc(sizeof(int) * buffer_size);
    if(NULL == new_stack -> buffer){
        if(NULL != error){
            *error = NOT_ENOUGH_MEMORY_ERROR;
        }
        free(new_stack);
        return NULL;
    }
    new_stack -> buffer_size = buffer_size;
    new_stack -> size = 0;
    return new_stack;
}

void FixedSizeStack_delete(FixedSizeStack **stack_pointer, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack_pointer or NULL == *stack_pointer){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    free((*stack_pointer) -> buffer);
    (*stack_pointer) -> buffer = NULL;
    free(*stack_pointer);
    *stack_pointer = NULL;
}


void FixedSizeStack_push(FixedSizeStack *stack, int data, error_t *error){
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
    if(stack -> size >= stack -> buffer_size){
        if(NULL != error){
            *error = BUFFER_OVERFLOW_ERROR;
        }
        return;
    }
    stack -> buffer[stack -> size] = data;
    (stack -> size)++;
    
}

int FixedSizeStack_pop(FixedSizeStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack or NULL == stack -> buffer){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    if(0 == stack -> size){
        if(NULL != error){
            *error = COLLECTION_IS_EMPTY_ERROR;
        }
        return 0;
    }
    if(stack -> size > stack -> buffer_size){
        if(NULL != error){
            *error = BUFFER_OVERFLOW_ERROR;
        }
        return 0;
    }
    (stack -> size)--;
    return stack -> buffer[stack -> size];
}

int FixedSizeStack_peek(FixedSizeStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack or NULL == stack -> buffer){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    if(0 == stack -> size){
        if(NULL != error){
            *error = COLLECTION_IS_EMPTY_ERROR;
        }
        return 0;
    }
    if(stack -> size > stack -> buffer_size){
        if(NULL != error){
            *error = BUFFER_OVERFLOW_ERROR;
        }
        return 0;
    }
    return stack -> buffer[stack -> size - 1];
}

size_t FixedSizeStack_get_size(FixedSizeStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack or NULL == stack -> buffer){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    return stack -> size;
}

bool FixedSizeStack_is_empty(const FixedSizeStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack or NULL == stack -> buffer){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return false;
    }

    return 0 == stack -> size;
}

void FixedSizeStack_print(const FixedSizeStack *stack, error_t *error){
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
    if(stack -> size > stack -> buffer_size){
        if(NULL != error){
            *error = BUFFER_OVERFLOW_ERROR;
        }
        return;
    }

    printf("bottom| ");
    for(size_t i = 0; i < stack -> size; i++){
        printf("%d, ", stack -> buffer[i]);
    }
    printf("| top\n");
}

void FixedSizeStack_reverse_print(const FixedSizeStack *stack, error_t *error){
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
    if(stack -> size > stack -> buffer_size){
        if(NULL != error){
            *error = BUFFER_OVERFLOW_ERROR;
        }
        return;
    }
    
    printf("top| ");
    for(size_t i = 0; i < stack -> size; i++){
        printf("%d, ", stack -> buffer[stack -> size - i - 1]);
    }
    printf(" |bottom\n");

}
