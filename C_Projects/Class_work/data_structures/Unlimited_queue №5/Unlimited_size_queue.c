#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdio.h>

#include "Unlimited_size_queue.h"
#include "singly_linked_list.h"


struct UnlimitedSizeQueue{
    SinglyLinkedList *list;
};


UnlimitedSizeQueue *UnlimitedSizeQueue_new(error_t *error){ // создать очередь
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }

    UnlimitedSizeQueue *queue = (UnlimitedSizeQueue *)malloc(sizeof(UnlimitedSizeQueue));
    if(NULL == queue){
        if(NULL != error){
            *error = NOT_ENOUGH_MEMORY_ERROR;
        }
        return NULL;
    }
    
    queue -> list = SinglyLinkedList_new(error);
    if(NULL != error and SUCCESS != *error){
        free(queue);
        return NULL;
    }

    return queue;
}

void UnlimitedSizeQueue_destruct(UnlimitedSizeQueue **queue_pointer, error_t *error){ // удалить очередь
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

    SinglyLinkedList_destruct(&((*queue_pointer) -> list), error);
    if(NULL != error){
        if(SUCCESS != *error){
            return;
        }
    }
    free(*queue_pointer);
    *queue_pointer = NULL;
}

void UnlimitedSizeQueue_enqueue(UnlimitedSizeQueue *queue, int data, error_t *error){ // положить элемент в конец очереди
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

    SinglyLinkedList_add_back(queue -> list, data, error);
    assert(SUCCESS == *error);
}

int UnlimitedSizeQueue_dequeue(UnlimitedSizeQueue *queue, error_t *error){ // взять элемент из начала очереди
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue or NULL == queue -> list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }

    bool size = UnlimitedSizeQueue_is_empty(queue, error);
    if(true == size){
        *error = COLLECTION_IS_EMPTY_ERROR;
        return 1;
    }
    SinglyLinkedListNode *first_node = SinglyLinkedList_get_head(queue -> list, error); // получить указатель на первый узел
    int data = SinglyLinkedList_get_data(first_node, error); // посмотреть данные узла
    SinglyLinkedListNode *last_node = SinglyLinkedList_get_tail(queue -> list, error);
    SinglyLinkedList_remove_next(queue -> list, last_node, error);
    return data;

}

int UnlimitedSizeQueue_peek(UnlimitedSizeQueue *queue, error_t *error){ // посмотерть элемент в начале очереди
    assert(NULL != error);
    if(NULL != error){
       *error = SUCCESS;
    }
    if(NULL == queue or NULL == queue -> list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }

    bool size = UnlimitedSizeQueue_is_empty(queue, error);
    if(true == size){
        *error = COLLECTION_IS_EMPTY_ERROR;
        return 1;
    }
    SinglyLinkedListNode *first_node = SinglyLinkedList_get_head(queue -> list, error); // получить указатель на первый узел
    int data = SinglyLinkedList_get_data(first_node, error); // посмотреть данные узла
    return data;
}

size_t UnlimitedSizeQueue_get_size(const UnlimitedSizeQueue *queue, error_t *error){ // колличество элементов в очереди
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == queue or NULL == queue -> list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }

    size_t size = SinglyLinkedList_get_size(queue -> list, error);
    return size;
}

bool UnlimitedSizeQueue_is_empty(const UnlimitedSizeQueue *queue, error_t *error){ // проверка пустая очередь или нет
    assert(NULL != error);
    if(NULL != error){
       *error = SUCCESS;
    }
    if(NULL == queue or NULL == queue -> list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }

    size_t size = SinglyLinkedList_get_size(queue -> list, error);
    if(0 == size){
        return 1;
    }

    return 0;
}

void UnlimitedSizeQueue_print(UnlimitedSizeQueue *queue, error_t *error){ // распечатать очередь
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

    bool size = UnlimitedSizeQueue_is_empty(queue, error);
    if(true == size){
        *error = COLLECTION_IS_EMPTY_ERROR;
        return;
    }
    SinglyLinkedList_print(queue -> list, error);
    assert(SUCCESS == *error);
}
