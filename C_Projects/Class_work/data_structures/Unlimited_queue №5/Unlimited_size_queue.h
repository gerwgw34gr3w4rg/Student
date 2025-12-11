#ifndef UNLIMITED_SIZE_QUEUE_H
#define UNLIMITED_SIZE_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

#include "error.h"


typedef struct UnlimitedSizeQueue UnlimitedSizeQueue;

UnlimitedSizeQueue *UnlimitedSizeQueue_new(error_t *error); // создать очередь
void UnlimitedSizeQueue_destruct(UnlimitedSizeQueue **queue_pointer, error_t *error); // удалить очередь

void UnlimitedSizeQueue_enqueue(UnlimitedSizeQueue *queue, int data, error_t *error); // положить элемент в конец очереди
int UnlimitedSizeQueue_dequeue(UnlimitedSizeQueue *queue, error_t *error); // взять элемент из начала очереди
int UnlimitedSizeQueue_peek(UnlimitedSizeQueue *queue, error_t *error); // посмотерть элемент в начале очереди
size_t UnlimitedSizeQueue_get_size(const UnlimitedSizeQueue *queue, error_t *error); // колличество элементов в очереди
bool UnlimitedSizeQueue_is_empty(const UnlimitedSizeQueue *queue, error_t *error); // проверка пустая очередь или нет

void UnlimitedSizeQueue_print(UnlimitedSizeQueue *queue, error_t *error); // распечатать очередь



#endif
