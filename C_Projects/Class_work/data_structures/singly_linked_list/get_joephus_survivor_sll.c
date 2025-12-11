#include <stdlib.h>
#include <iso646.h>
#include <assert.h>

#include "singly_linked_list.h"
#include "error.h"


size_t get_josephus_survivor_sll(size_t participant_count, size_t step_size){
    /* Returns 0 on error
    */
    if (0 == participant_count or 0 == step_size) {
        return 0;
    }
    error_t error;
    SinglyLinkedList *list = SinglyLinkedList_new(&error);
    if (SUCCESS != error) {
        return 0;
    }

    for (size_t i = 0; i < participant_count; i++) {
        SinglyLinkedList_add_back(list, i + 1, &error);
        if (SUCCESS != error) {
            SinglyLinkedList_destruct(&list, &error);
            assert(SUCCESS == error);
            return 0;
        }
    }

    SinglyLinkedListNode *node = SinglyLinkedList_get_head(list, &error);
    assert(SUCCESS == error);
    size_t step_number = 0;
    while (SinglyLinkedList_get_size(list, &error) > 1) {
        step_number++;
        if (step_number == step_size - 1) {
            SinglyLinkedList_remove_next(list, node, &error);
            assert(SUCCESS == error);
            step_number = 0;
        }
        node = SinglyLinkedList_get_next(node, &error);
        assert(SUCCESS == error);
    }
    SinglyLinkedListNode *head = SinglyLinkedList_get_head(list, &error);
    assert(SUCCESS == error);
    int survivor_id = SinglyLinkedList_get_data(head, &error);
    assert(SUCCESS == error);
    SinglyLinkedList_destruct(&list, &error);
    assert(SUCCESS == error);
    return (size_t)survivor_id;
}


int main(void) {
    printf("%zu\n", get_josephus_survivor_sll(5, 3));
}
