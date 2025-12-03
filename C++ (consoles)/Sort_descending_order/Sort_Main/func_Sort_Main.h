#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <clocale>
#include <stdint.h>




void* new_memory(size_t size) {
	void* pointer = NULL;
	pointer = (void*)malloc(size);
	if (NULL == pointer) {
		printf("Ошибка выделения памяти в функции new_memory\n");
	}
	return pointer;
}

void* free_memory(void* ptr) {
	if (NULL == ptr) {
		printf("Предупреждение - функция free_memory получила NULL, память не будет очищена\n");
		return NULL;
	}
	free(ptr);
	return NULL;
}