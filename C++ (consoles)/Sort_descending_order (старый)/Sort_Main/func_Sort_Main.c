#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cstdint>
#include <cassert>


struct stack_t {
	int32_t* size_max; // size_max = num + 36 байт (максимальный размер стека)
	int32_t* size_min; // size_max = num (минимальный размер стека)
	int32_t* num; // 40 байт памяти это 10 int32_t
} ;

void* new_memory(size_t size) {
	void* pointer = NULL;
	pointer = (void*)malloc(size);
	if (NULL == pointer) {
		printf("Ошибка выделения памяти в функции new_memory\n");
	}
	return pointer;
}

void* free_memory(void* ptr){
	if (NULL == ptr) {
		printf("Предупреждение - функция free_memory получила NULL, память не будет очищена\n");
		return NULL;
	}
	free(ptr);
	return NULL;
}

void push(stack_t* stack, int32_t num) { // кладёт на вершину стека

}

void change_char_to_int32(stack_t* stack, char* tmp_box) { // функция превращает char в int32_t и кладёт их в стек
	bool denialovo = false; // знак (отрицалово)
	int8_t overflow = 0;
	const int8_t OVERFLOW_MAX_POSITIVE = 10; // переполнение длинны символов int32_t
	const int8_t OVERFLOW_MAX_NEGATIVE = 11; // переполнение длинны символов -int32_t
	char symbol = 'y';
	int32_t tmp_num = 0;

	for (int8_t i = 0; symbol != '\n' and symbol != EOF; i++) {
		symbol = tmp_box[i];
		if ('0' == symbol) { // в начале незначащий 0, его просто пропустить
			continue;
		}
		if ('-' == symbol) {
			denialovo = true; // знак (отрицалово)
			continue;
		}
		for (; '0' <= symbol and '9' >= symbol;) { // если цифра то надо записать
			i++;
			tmp_num = tmp_num + (int32_t)(symbol - '0'); // char в int32_t
			symbol = tmp_box[i];
			if ('0' <= symbol and '9' >= symbol) {
				tmp_num = tmp_num * 10;
			}
			else {
				if (true == denialovo) {
					tmp_num = tmp_num * -1;
				}

				//здесь буду класться элементы на стек команда push
				tmp_num = tmp_num ^ tmp_num; // xor детка!
				break;
			}
		}
		denialovo = false; // знак (отрицалово)
	}

}
