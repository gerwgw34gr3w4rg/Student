/*
    Программа для хранения данных типа int32_t через узлы.
    В одном узле одно поле data, для хранения одного значения типа int32_t
    При создание узла поле data = 0
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Doubly_linked_list {
    int32_t data : 32;
    struct Doubly_linked_list* next;
    struct Doubly_linked_list* back;
} Doubly_linked_list;
int32_t total_nodes = 0; // колличество узлов


Doubly_linked_list* start_node = NULL;
Doubly_linked_list* current_node = NULL;
Doubly_linked_list* last_node = NULL;

void Doubly_linked_list_new(); // создать узел
void Doubly_linked_list_delete(); // удалить текущий узел
void Doubly_linked_list_next(); // следующий узел
void Doubly_linked_list_back(); // предыдущий узел


int main(){

    Doubly_linked_list_new();

    Doubly_linked_list_next();

    Doubly_linked_list_back();


end:
    for (; NULL != current_node;) {
        Doubly_linked_list_delete();
    }
    printf("------------------------------------Success------------------------------------\n");
}


// создать узел
void Doubly_linked_list_new(){
	Doubly_linked_list* node = NULL;
    node = (Doubly_linked_list*)malloc(sizeof(Doubly_linked_list));
    if(NULL == node) {
		printf("Error: Failed to allocate memory, not enough memory\n");
        return;
	}
    if (NULL == last_node) {
        last_node = node;
        start_node = node;
        current_node = node;
        node->next = node;
        node->back = node;
        current_node->data = 0;
    }
    else {
        node->next = start_node;
        node->back = last_node;
        last_node->next = node;
        last_node = node;
        start_node->back = last_node;
        last_node->data = 0;
    }
    total_nodes++;
}

// удалить текущий узел
void Doubly_linked_list_delete() {
    if (NULL == current_node) {
        printf("Warning - current_node = NULL");
        return;
    }
    bool end = false;
    if (start_node == last_node) {
        end = true;
    }
    Doubly_linked_list* tmp_right = current_node;
    Doubly_linked_list* tmp_left = current_node;
    tmp_right = tmp_right->next;
    tmp_left = tmp_left->back;
    tmp_left->next = tmp_right;
    tmp_right->back = tmp_left;
    if (start_node == current_node) {
        start_node = start_node->next;
    }
    if (last_node == current_node) {
        last_node = last_node->back;
    }
    free(current_node);

    current_node = tmp_left;

    if (end) {
        start_node = NULL;
        last_node = NULL;
        current_node = NULL;
    }
    total_nodes--;
}

// следующий узел
void Doubly_linked_list_next() {
    if (NULL == current_node) {
		printf("Warning - current node = NULL, the transition has been cancelled\n");
		return;
    }
    else if (NULL == current_node->next) {
        printf("Warning - next node = NULL, the transition has been cancelled\n");
        return;
    }
	current_node = current_node->next;
}

// предыдущий узел
void Doubly_linked_list_back() {
    if (NULL == current_node) {
        printf("Warning - current node = NULL, the transition has been cancelled");
        return;
    }
    else if (NULL == current_node->back) {
        printf("Warning - back node = NULL, the transition has been cancelled");
        return;
    }
    current_node = current_node->back;
}