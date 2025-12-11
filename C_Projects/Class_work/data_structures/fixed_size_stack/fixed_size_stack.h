#ifndef FIXED_SIZE_STACK_H
#define FIXED_SIZE_STASK_H


#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>
#include <assert.h>

#include "error.h"

typedef struct FixedSizeStack FixedSizeStack;


FixedSizeStack *FixedSizeStack_new(size_t buffer_size, error_t *error); // создание стека
void FixedSizeStack_delete(FixedSizeStack **stack_pointer, error_t *error); // удаление стека

void FixedSizeStack_push(FixedSizeStack *stack, int data, error_t *error); // положить элемент на верхушку стека
int FixedSizeStack_pop(FixedSizeStack *stack, error_t *error); // взять последний положенный элемент со стека
int FixedSizeStack_peek(FixedSizeStack *stack, error_t *error); // посмотерть верхний элемент стека
size_t FixedSizeStack_get_size(FixedSizeStack *stack, error_t *error); // колличество элементов в стеке
bool FixedSizeStack_is_empty(const FixedSizeStack *stack, error_t *error); // проверка пустой стек или нет

void FixedSizeStack_print(const FixedSizeStack *stack, error_t *error);
void FixedSizeStack_reverse_print(const FixedSizeStack *stack, error_t *error);

#endif //FIXED_SIZE_STACK_H
