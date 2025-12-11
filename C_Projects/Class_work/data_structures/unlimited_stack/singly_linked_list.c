#include "singly_linked_list.h"


SinglyLinkedList *SinglyLinkedList_new(error_t *error){
    assert (NULL != error);
    if (NULL != error){
        *error = SUCCESS;
    }
    SinglyLinkedList *new_list = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    if(NULL == new_list){
        if(NULL != error){
            *error = NOT_ENOUGH_MEMORY_ERROR;
        }
        return NULL;
    }
    new_list -> head = NULL;
    new_list -> tail = NULL;
    new_list -> size = (size_t)0;
    return new_list;
}


void SinglyLinkedList_delete(SinglyLinkedList **list_pointer, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == list_pointer or NULL == *list_pointer){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    SinglyLinkedList *list = *list_pointer;
    if(NULL != list -> head){
        SinglyLinkedListNode *current = list -> head -> next;
        while(current != list -> head){
            SinglyLinkedListNode *next = current -> next;
            free(current);
            current = next;
        }
        free(list -> head);
    }
    free(list);
    *list_pointer = NULL;
}

size_t SinglyLinkedList_get_size(const SinglyLinkedList *list, error_t *error){
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    return list -> size;
}

SinglyLinkedListNode *SinglyLinkedList_get_head(SinglyLinkedList *list, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return NULL;
    }
    if(0 == list -> size or NULL == list -> head){
        if(NULL != error){
            *error = COLLECTION_IS_EMPTY_ERROR;
        }
        return NULL;
    }

    assert(NULL != list -> tail);
    assert(list -> tail -> next == list -> head);

    return list -> head;
}

SinglyLinkedListNode *SinglyLinkedList_get_tail(SinglyLinkedList *list, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return NULL;
    }
    if(0 == list -> size or NULL == list -> head){
        if(NULL != error){
            *error = COLLECTION_IS_EMPTY_ERROR;
        }
        return NULL;
    }

    assert(NULL != list -> tail);
    assert(list -> tail -> next == list -> head);

    return list -> tail;
}

SinglyLinkedListNode *SinglyLinkedList_get_next(SinglyLinkedListNode *node, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL != node){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return NULL;
    }
    assert(NULL != node -> next);
    return node -> next;
}


void SinglyLinkedList_add_front(SinglyLinkedList *list, int data, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        error = SUCCESS;
    }
    if(NULL == list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    if(NULL != error){
        *error = SUCCESS;
    }

    SinglyLinkedListNode *new_node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    if(NULL == new_node){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    new_node -> data = data;
    if (NULL == list -> head){
        new_node -> next = new_node;
        list -> head = new_node;
        list -> tail = new_node;
    }
    else {
        new_node -> next = list -> head;
        list -> head = new_node;
        list -> tail -> next = new_node;
    }
    (list -> size)++;
    return;
}


void SinglyLinkedList_add_back(SinglyLinkedList *list, int data, error_t *error){
    assert(NULL != error);
    if(NULL == list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    if(NULL != error){
        *error = SUCCESS;
    }
    SinglyLinkedListNode *new_node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    if(NULL == new_node){
        if(NULL != error){
            *error = NOT_ENOUGH_MEMORY_ERROR;
        }
        return;
    }
    new_node -> data = data;
    if (NULL == list -> head){
        new_node -> next = new_node;
        list -> head = new_node;
        list -> tail = new_node;
    }
    else {
        new_node -> next = list -> head;
        list -> tail -> next = new_node;
        list -> tail = new_node;
    }
    (list -> size)++;
}

void SinglyLinkedList_remove_next(SinglyLinkedList *list,
                                SinglyLinkedListNode *node, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == list or NULL == node){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    assert(NULL != node -> next);
    SinglyLinkedListNode *remove_node = node -> next;
    if(remove_node == list -> tail){
        list -> tail = node;
    }
    node -> next = node -> next -> next;
    if(remove_node == list -> head){
        list -> head = list -> tail -> next;
    }
    free(remove_node);
    remove_node = NULL;
    list -> size = list -> size - 1;
    assert(list -> size >= 0);
    if(0 == list -> size){
        list -> head = NULL;
        list -> tail = NULL;
    }

}

int SinglyLinkedList_get_data(const SinglyLinkedListNode *node, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == node){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return 0;
    }
    return node -> data;
}
void SinglyLinkedList_print(const SinglyLinkedList *list, error_t *error){
    assert(NULL != error);
    if(NULL == list){
        if(NULL != error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == list -> head){
        printf("\n");
        return;
    }
    SinglyLinkedListNode *node = list -> head;
    while (node -> next != list -> head){
        printf("%d,  ", node -> data);
        node = node -> next;
    }
    printf("%d\n", node -> data);
}