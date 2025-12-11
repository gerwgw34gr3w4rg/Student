#ifndef UNLIMITED_STACK_H
#define UNLIMITED_STACK_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>

#include "singly_linked_list.h"
#include "error.h"


typedef struct {
    SinglyLinkedList *list;
} UnlimitedStack;


UnlimitedStack *UnlimitedStack_new(error_t *error);
void UnlimitedStack_delete(UnlimitedStack **stack_pointer, error_t *error);

void UnlimitedStack_push(UnlimitedStack *stack, int data, error_t *error);
int UnlimitedStack_pop(UnlimitedStack *stack, error_t *error);
int UnlimitedStack_peek(const UnlimitedStack *stack, error_t *error);
size_t UnlimitedStack_get_size(const UnlimitedStack *stack, error_t *error);
bool UnlimitedStack_is_empty(const UnlimitedStack *stack, error_t *error);

void UnlimitedStack_print(const UnlimitedStack *stack, error_t *error);


#endif // UnlimitedStack_H