#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H


#include <stdlib.h>
#include <inttypes.h>


typedef struct DoublyLinkedListNode {
    int32_t data : 32;  // Не нужно указывать ширину поля
    struct Doubly_linked_list* next;
    struct Doubly_linked_list* back;
} DoublyLinkedListNode;


typedef struct DoublyLinkedList {
	DoublyLinkedListNode *head;
	size_t size;
} DoublyLinkedList;

// Добавить следующие функции:

// Конструктор
// Деструктор
// get_data - получить данные узла
// get_next - перейти к следующему узлу
// ... остальное додумай сам


void DoublyLinkedListNode_new(int32_t data); // создать узел
void Doubly_linked_list_delete(); // удалить текущий узел
void Doubly_linked_list_другое_название(int32_t data);// ввести данные в текущий узел
void Doubly_linked_list_get_data(); // посмотреть данные в текущем узле
void Doubly_linked_list_next(); // перейти на следующий узел
void Doubly_linked_list_back(); // перейти на предыдущий узел
void Doubly_linked_list_get_head(); // перейти на первый узел
void Doubly_linked_list_get_last(); // перейти на последний узел
void Doubly_linked_list_print(); // вывести номера всех узлов и их содержимое


#endif  // DOUBLY_LINKED_LIST_H
