#ifndef FIXED_SIZE_QUEUE_H
#define FIXED_SIZE_QUEUE_H


#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


#include "fixed_size_stack.h"
#include "error.h"

typedef struct {
    FixedSizeStack *out;
    FixedSizeStack *in;
} FixedSizeQueue;


FixedSizeQueue *FixedSizeQueue_new(size_t limit, error_t *error); // создать очередь
void FixedSizeQueue_delete(FixedSizeQueue **queue_pointer, error_t *error); // удалить очередь

void FixedSizeQueue_enqueue(FixedSizeQueue *queue, int data, error_t *error); // положить элемент в конец очереди
int FixedSizeQueue_dequeue(FixedSizeQueue *queue, error_t *error); // взять элемент из начала очереди
int FixedSizeQueue_peek(FixedSizeQueue *queue, error_t *error); // посмотерть элемент в начале очереди
size_t FixedSizeQueue_get_size(const FixedSizeQueue *queue, error_t *error); // колличество элементов в очереди
bool FixedSizeQueue_is_empty(const FixedSizeQueue *queue, error_t *error); // проверка пустая очередь или нет

void FixedSizeQueue_print(const FixedSizeQueue *queue, error_t *error); // распечатать очередь

#endif
