#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINCED_LIST_H


#include <stdlib.h>
#include <assert.h>
#include <iso646.h>
#include <stdio.h>

#include "error.h"

typedef struct SinglyLinkedListNode SinglyLinkedListNode;


//Circular singly linked list
typedef struct SinglyLinkedList SinglyLinkedList;


SinglyLinkedList *SinglyLinkedList_new(error_t *error);
void SinglyLinkedList_destruct(SinglyLinkedList **list, error_t *error);

size_t SinglyLinkedList_get_size(const SinglyLinkedList *list, error_t *error);
SinglyLinkedListNode *SinglyLinkedList_get_head(SinglyLinkedList *list, error_t *error);
SinglyLinkedListNode *SinglyLinkedList_get_tail(SinglyLinkedList *list, error_t *error);
SinglyLinkedListNode *SinglyLinkedList_get_next(SinglyLinkedListNode *node, error_t *error);
void SinglyLinkedList_add_front(SinglyLinkedList *list, int data, error_t *error);
void SinglyLinkedList_add_back(SinglyLinkedList *List, int data, error_t *error);
void SinglyLinkedList_remove_next(SinglyLinkedList *list,
                                SinglyLinkedListNode *node, error_t *error);


int SinglyLinkedList_get_data(const SinglyLinkedListNode *node, error_t *error);

void SinglyLinkedList_print(const SinglyLinkedList *list, error_t *error);

#endif  // SINGL_LINKED_LIST_H
