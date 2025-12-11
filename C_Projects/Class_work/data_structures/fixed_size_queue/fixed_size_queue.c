#include <stdlib.h>

#include "fixed_size_queue.h"

FixedSizeQueue *FixedSizeQueue_new(size_t limit, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(0 == limit){
        if(NULL != error){
            *error = WRONG_LIMITS_ERROR;
        }
        return NULL;
    }

    FixedSizeQueue *queue = (FixedSizeQueue *)malloc(sizeof(FixedSizeQueue));
    if(NULL == queue){
        if(NULL != error){
            *error = NOT_ENOUGH_MEMORY_ERROR;
        }
        return NULL;
    }

    queue -> out = FixedSizeStack_new(limit, error);
    if(SUCCESS != *error){
        free(queue);
        return NULL;
    }
    queue -> in = FixedSizeStack_new(limit, error);
    if(SUCCESS != *error){
        FixedSizeStack_delete(&(queue -> out), error);
        assert(SUCCESS == *error);
        free(queue);
        return NULL;
    }


    return queue;
}

void FixedSizeQueue_delete(FixedSizeQueue **queue_pointer, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue_pointer or NULL == *queue_pointer){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }

    FixedSizeStack_delete(&((*queue_pointer) -> out), error);
    assert(SUCCESS == *error);
    FixedSizeStack_delete(&((*queue_pointer) -> in), error);
    assert(SUCCESS == *error);
    free(*queue_pointer);
    *queue_pointer = NULL;
    assert(NULL == *queue_pointer);

    return;
}

void FixedSizeQueue_enqueue(FixedSizeQueue *queue, int data, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }

    FixedSizeStack_push(queue -> in, data, error);
    assert(SUCCESS == *error);
    return;
}

void __transfer_data_between_stacks(FixedSizeQueue *queue, error_t *error){
    bool is_empty;
    bool is_out_empty = FixedSizeStack_is_empty(queue -> out, error);
    assert(SUCCESS == *error);
    int data;
    if(is_out_empty){
        is_empty = FixedSizeStack_is_empty(queue -> in, error);
        assert(SUCCESS == *error);
        if(is_empty){
            if(NULL != error){
                *error = COLLECTION_IS_EMPTY_ERROR;
            }
            return;
        }
        while(not is_empty){
            data = FixedSizeStack_pop(queue -> in, error);
            assert(SUCCESS == *error);
            FixedSizeStack_push(queue -> out, data, error);
            assert(SUCCESS == *error);
            is_empty = FixedSizeStack_is_empty(queue -> in, error);
            assert(SUCCESS == *error);
        }
    }
}

int FixedSizeQueue_dequeue(FixedSizeQueue *queue, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }

    __transfer_data_between_stacks(queue, error);
    
    int data = FixedSizeStack_pop(queue -> out, error);
    assert(SUCCESS == *error);
    return data;
}

int FixedSizeQueue_peek(FixedSizeQueue *queue, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }

    __transfer_data_between_stacks(queue, error);
    
    int data = FixedSizeStack_peek(queue -> out, error);
    assert(SUCCESS == *error);
    return data;
}

size_t FixedSizeQueue_get_size(const FixedSizeQueue *queue, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    size_t queue_size = FixedSizeStack_get_size(queue -> in, error);
    assert(SUCCESS == *error);
    queue_size += FixedSizeStack_get_size(queue -> out, error);
    assert(SUCCESS == *error);
    return queue_size;
}

bool FixedSizeQueue_is_empty(const FixedSizeQueue *queue, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return false;
    }

    size_t size = FixedSizeQueue_get_size(queue, error);
    assert(SUCCESS == *error);

    return 0 == size;
}

void FixedSizeQueue_print(const FixedSizeQueue *queue, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }

    FixedSizeStack_reverse_print(queue -> out, error);
    assert(SUCCESS == *error);

    FixedSizeStack_print(queue -> in, error);
    assert(SUCCESS == *error);
    printf("\n");
    return;
}
