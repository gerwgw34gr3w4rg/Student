#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "singly_linked_list.h"
#include "error.h"


#define LIST_SIZE (size_t)3


bool compare_data(const SinglyLinkedList *list, int *data, size_t data_size);
size_t josephus_survivor_id(size_t participant_count, size_t step_size);
size_t get_josephus_survivor_sll(size_t participant_count, size_t step_size);

int main(){
    int data[LIST_SIZE] = {10, -3, 0};
    error_t error = SUCCESS;
    
    SinglyLinkedList *list = SinglyLinkedList_new(&error);
    //assert(NULL == list -> head);
    //assert(NULL == list -> tail);
    //assert(0 == list -> size);
    assert(SUCCESS == error);

    for(size_t i = 0; i < LIST_SIZE; i++){
        SingleLinkedList_add_front(list, data[LIST_SIZE - i - 1], &error);
        assert(SUCCESS == error);
        //assert(i + 1 == list -> size);
        bool is_data_equal = compare_data(list, data + LIST_SIZE - i - 1, i + 1);
        assert(true == is_data_equal);
        SinglyLinkedList_print((const SinglyLinkedList *)list, &error);
        assert(SUCCESS == error);
    }

    SinglyLinkedList_destruct(&list, &error);
    assert(NULL == list);
    assert(SUCCESS == error);

    list = SinglyLinkedList_new(&error);
    //assert(NULL == list -> head);
    //assert(NULL == list -> tail);
    //assert(0 == list -> size);
    assert(SUCCESS == error);

    for(size_t i = 0; i < LIST_SIZE; i++){
        SinglyLinkedList_add_back(list, data[i], &error);
        assert(SUCCESS == error);
        //assert(i + 1 == list -> size);
        bool is_data_equal = compare_data(list, &data[i], i + 1);
        assert(true == is_data_equal);
        SinglyLinkedList_print((const SinglyLinkedList *)list, &error);
        assert(SUCCESS == error);
    }

    //Test remove node 
    // SinglyLinkedList_remove_next(list, list -> tail, &error);
    // assert(SUCCESS == error);
    // assert(2 == list -> size);
    // assert(list -> tail -> next == list -> head);
    // assert(list -> head -> next == list -> tail);

    SinglyLinkedList_add_back(list, data[LIST_SIZE - 1], &error);
    assert(SUCCESS == error);
    
    SinglyLinkedList_remove_next(list, list -> head, &error);
    assert(SUCCESS == error);
    assert(2 == list -> size);
    assert(list -> tail -> next == list -> head);
    assert(list -> head -> next == list -> tail);

    SinglyLinkedList_add_back(list, data[LIST_SIZE - 1], &error);
    assert(SUCCESS == error);

    SinglyLinkedList_remove_next(list, list -> head -> next, &error);
    assert(SUCCESS == error);
    assert(2 == list -> size);
    assert(list -> tail -> next == list -> head);
    assert(list -> head -> next == list -> tail);
    // Осталось 2 узла в списке

    SinglyLinkedList_remove_next(list, list -> tail, &error);
    assert(SUCCESS == error);
    assert(1 == list -> size);
    assert(list -> tail -> next == list -> head);
    assert(list -> head -> next == list -> tail);

    SinglyLinkedList_add_back(list, data[LIST_SIZE - 1], &error);
    assert(SUCCESS == error);

    SinglyLinkedList_remove_next(list, list -> head, &error);
    assert(SUCCESS == error);
    assert(1 == list -> size);
    assert(list -> tail -> next == list -> head);
    assert(list -> head -> next == list -> tail);
    // Остался 1 узел

    SinglyLinkedList_remove_next(list, list -> head, &error);
    assert(SUCCESS == error);
    assert(0 == list -> size);
    assert(NULL == list -> head);
    assert(NULL == list -> tail);
    // Список пуст

    SinglyLinkedList_remove_next(list, list -> head, &error);
    assert(0 == list -> head);
    assert(NULL_POINTER_ERROR == error);
    //-------------------------------------


    SinglyLinkedList_destruct(&list, &error);
    assert(NULL == list);
    assert(SUCCESS == error);

    size_t participant_count = 5;
    size_t step_size = 3;
    size_t answer = 4;
    size_t survivor_id_simple = josephus_survivor_id(participant_count, step_size);
    printf("%zu %zu %zu\n", participant_count, step_size, survivor_id_simple);
    assert(survivor_id_simple == answer);
    

    participant_count = 15;
    step_size = 7;
    answer = 5;
    survivor_id_simple = josephus_survivor_id(participant_count, step_size);
    printf("%zu %zu %zu\n", participant_count, step_size, survivor_id_simple);
    assert(survivor_id_simple == answer);
    
    size_t survivor_id_sll = get_josephus_survivor_sll(participant_count, step_size);
    printf("%zu %zu %zu\n", participant_count, step_size, survivor_id_simple);
    assert(survivor_id_sll == answer);

    printf("\n%s done!\n", __FILE__);

}


bool compare_data(const SinglyLinkedList *list, int *data, size_t data_size){
    assert(NULL != list);
    assert(NULL != data);
    if(data_size != list -> size){
        return false;
    }
    if(0 == data_size){
        return true;
    }
    assert(NULL != list -> head);
    SinglyLinkedListNode *node = list -> head;
    size_t i = 0;
    while(node != list -> head){
        if (node -> data != data[i]){
            return false;
        }
        
        node = node -> next;
        assert(NULL != node);
        i++;
        assert(i < data_size);
    }
    return true;
}