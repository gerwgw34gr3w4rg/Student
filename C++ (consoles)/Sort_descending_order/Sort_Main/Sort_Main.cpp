#include "func_Sort_Main.h"

int main() {
	setlocale(LC_CTYPE, "Russian");
	int32_t* stack1 = NULL;
	int32_t* stack2 = NULL;
	int32_t* stack3 = NULL;
	const int8_t MAX_NUMBER_OF_NUMBERS_IN_BYTES = 40; // максимальное количество чисел в байтах. 40 байт - 10 чисел по 4 байта
	stack1 = (int32_t*)new_memory(MAX_NUMBER_OF_NUMBERS_IN_BYTES);
	stack2 = (int32_t*)new_memory(MAX_NUMBER_OF_NUMBERS_IN_BYTES);
	stack3 = (int32_t*)new_memory(MAX_NUMBER_OF_NUMBERS_IN_BYTES);
	char* tmp_box = NULL; // Сюда будут складываться элементы что ввёл пользователь
	const uint8_t MAX_BYTE_ELEMENT = 120; // 119 - максимальный объём входных байт + 1 '\n' или EOF
	tmp_box = (char*)new_memory(MAX_BYTE_ELEMENT);
	if (NULL == tmp_box) {
		printf("Ошибка выделения памяти под (tmp_box) временный буфер\nПрограмма завершена\n");
		return 1;
	}
	//printf("вводить числа через пробел. разрешено не более 10 чисел через пробел "
	//"в диапозоне от -2147483648 до 2147483647\n"
	//"после ввода чисел - клавиша ввод (enter)\n"
	//"ввод других символов или неверной последовательности знака - и знака (пробел) приведёт к неизвестным последствиям!\n");
	tmp_box[MAX_BYTE_ELEMENT - 1] = '\n';
	uint8_t i = 0;
	char command;
	do {
		command = fgetc(stdin);
		tmp_box[i] = command;
		i++;
		printf("i = %d\n", i);
		//дописать логику проверку вводимых значний, например последовательность, знак -,
		//игнорирование лишних символов 
	} while (i <= MAX_BYTE_ELEMENT - 1 and '\n' != command and EOF != command); // проверка колличества введённых символов
	if ('\n' != tmp_box[MAX_BYTE_ELEMENT - 1] and 'я' != tmp_box[MAX_BYTE_ELEMENT - 1]) {
		printf("Слишком много данных\nПрограмма не была выполнена\n");
	}
	else {
		//тут запуск функции чтобы все числа char преобразовать в int32_t
	}

	tmp_box = (char*)free_memory(tmp_box);
	stack1 = (int32_t*)free_memory(stack1);
	stack2 = (int32_t*)free_memory(stack2);
	stack3 = (int32_t*)free_memory(stack3);
	return 0;
}
