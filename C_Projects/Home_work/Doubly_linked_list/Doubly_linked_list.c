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
int32_t data;


Doubly_linked_list* start_node = NULL;
Doubly_linked_list* current_node = NULL;
Doubly_linked_list* last_node = NULL;

void Doubly_linked_list_new(); // создать узел
void Doubly_linked_list_delete(); // удалить текущий узел
void Doubly_linked_list_push(int32_t data);// ввести данные в текущий узел
void Doubly_linked_list_peek(); // посмотреть данные в текущем узле
void Doubly_linked_list_next(); // перейти на следующий узел
void Doubly_linked_list_back(); // перейти на предыдущий узел
void Doubly_linked_list_start(); // перейти на первый узел
void Doubly_linked_list_last(); // перейти на последний узел
void Doubly_linked_list_print(); // вывести номера всех узлов и их содержимое


int main(){
    //test start
    data = 5;
    Doubly_linked_list_delete();
    Doubly_linked_list_push(data);
    Doubly_linked_list_peek();
    Doubly_linked_list_next();
    Doubly_linked_list_back();
    Doubly_linked_list_start();
    Doubly_linked_list_last();
    Doubly_linked_list_print();


    data = 15;
    Doubly_linked_list_new();
    Doubly_linked_list_next();
    Doubly_linked_list_push(data);

    data = 25;
    Doubly_linked_list_new();
    Doubly_linked_list_next();
    Doubly_linked_list_push(data);

    Doubly_linked_list_print();

    data = 35;
    Doubly_linked_list_new();
    Doubly_linked_list_next();
    Doubly_linked_list_push(data);

    data = 45;
    Doubly_linked_list_new();
    Doubly_linked_list_next();
    Doubly_linked_list_push(data);

    data = 55;
    Doubly_linked_list_new();
    Doubly_linked_list_next();
    Doubly_linked_list_push(data);

    Doubly_linked_list_print();


    Doubly_linked_list_back();
    Doubly_linked_list_back();
    Doubly_linked_list_delete();

    Doubly_linked_list_print();
    Doubly_linked_list_peek();

    //test end

end:
    for (; NULL != current_node;) {
        Doubly_linked_list_delete();
    }
    printf("\n------------------------------------Success------------------------------------\n\n");
}


// создать узел
void Doubly_linked_list_new(){
	Doubly_linked_list* node = NULL;
    node = (Doubly_linked_list*)malloc(sizeof(Doubly_linked_list));
    if(NULL == node) {
		printf("Warning - failed to create node, not enough memory\n");
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
        printf("Warning - current node points to nothing, deletion failed\n");
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

// ввести данные в текущий узел
void Doubly_linked_list_push(int32_t data) {
    if (NULL == current_node) {
        printf("Warning: current node points to nowhere, "
                "no data was placed into the node\n");
        return;
    }
    current_node->data = data;
}

// посмотреть данные в текущем узле
void Doubly_linked_list_peek() {
    if (NULL == current_node) {
        printf("Warning: current node points to nowhere, "
                "data cannot be viewed\n");
        return;
    }
    printf("data current node - %d\n", current_node->data);
}

// перейти на следующий узел
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

// перейти на предыдущий узел
void Doubly_linked_list_back() {
    if (NULL == current_node) {
        printf("Warning - current node = NULL, the transition has been cancelled\n");
        return;
    }
    else if (NULL == current_node->back) {
        printf("Warning - back node = NULL, the transition has been cancelled\n");
        return;
    }
    current_node = current_node->back;
}

// перейти на первый узел
void Doubly_linked_list_start() {
    if (NULL == start_node) {
        printf("Warning - start node = NULL, the transition has been cancelled\n");
        return;
    }
    current_node = start_node;
}

// перейти на последний узел
void Doubly_linked_list_last() {
    if (NULL == last_node) {
        printf("Warning - last node = NULL, the transition has been cancelled\n");
        return;
    }
    current_node = last_node;
}

// вывести номера всех узлов и их содержимое
void Doubly_linked_list_print() {
    if (NULL == start_node) {
        printf("No nodes\n");
        return;
    }
    Doubly_linked_list* tmp = start_node;
    int32_t i = 1;
    do {
        printf("node %d, data = %d\n", i, tmp->data);
        tmp = tmp->next;
        i++;
    } while (start_node != tmp);
    printf("\n");
}