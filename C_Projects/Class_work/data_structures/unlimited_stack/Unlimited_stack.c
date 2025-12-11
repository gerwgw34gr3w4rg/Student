#include "Unlimited_stack.h"

UnlimitedStack *UnlimitedStack_new(error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    UnlimitedStack *new_stack = (UnlimitedStack *)malloc(sizeof(UnlimitedStack));
    if(NULL == new_stack){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return NULL;
    }
    new_stack -> list = SinglyLinkedList_new(error);
    if(NULL != error and SUCCESS != *error){
        free(new_stack);
        new_stack = NULL;
        return NULL;
    }
    return new_stack;
}

void UnlimitedStack_delete(UnlimitedStack **stack_pointer, error_t *error){
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
    SinglyLinkedList_delete(&((*stack_pointer) -> list), error);
    free(*stack_pointer);
    *stack_pointer = NULL;
}

void UnlimitedStack_push(UnlimitedStack *stack, int data, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    assert(NULL != stack -> list);
    SinglyLinkedList_add_front(stack -> list, data, error);
    assert(SUCCESS == *error);

}

int UnlimitedStack_pop(UnlimitedStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    assert(NULL != stack -> list);
    SinglyLinkedListNode *head = SinglyLinkedList_get_head(stack -> list, error);
    assert(SUCCESS == *error);
    int data = SinglyLinkedList_get_data(head, error);
    assert(SUCCESS == *error);
    SinglyLinkedListNode *tail = SinglyLinkedList_get_tail(stack -> list, error);
    assert(SUCCESS == *error);
    SinglyLinkedList_remove_next(stack -> list, tail, error);
    assert(SUCCESS == *error);
    return data;
}

int UnlimitedStack_peek(const UnlimitedStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    assert(NULL != stack -> list);
    SinglyLinkedListNode *head = SinglyLinkedList_get_head(stack -> list, error);
    assert(SUCCESS == *error);
    int data = SinglyLinkedList_get_data(head, error);
    assert(SUCCESS == *error);
    return data;
}

size_t UnlimitedStack_get_size(const UnlimitedStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    assert(NULL != stack -> list);
    size_t size = SinglyLinkedList_get_size(stack -> list, error);
    assert(SUCCESS == *error);
    return size;
}

bool UnlimitedStack_is_empty(const UnlimitedStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    assert(NULL != stack -> list);
    size_t size = SinglyLinkedList_get_size(stack -> list, error);
    assert(SUCCESS == *error);
    return 0 == size;
    //return false;
}

void UnlimitedStack_print(const UnlimitedStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    assert(NULL != stack -> list);
    SinglyLinkedList_print(stack -> list, error);

}