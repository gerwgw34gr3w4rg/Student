#include "func_Sort_Main.c"

int main() {
	setlocale(LC_CTYPE, "Russian");
	stack_t* stack1 = NULL;
	stack_t* stack2 = NULL;
	stack_t* stack3 = NULL;
	const int8_t MAX_AMOUNT_OF_NUMBERS_IN_BYTES = 40; // максимальное количество чисел в байтах. 40 байт - 10 чисел по 4 байта
	const int8_t MAX_NUMBERS_IN_STACK = 10; // максимальное количество чисел в стеке
	stack1 = (stack_t*)new_memory(sizeof(stack_t)); // выделение памяти дял стека
	stack1 -> num = (int32_t*)new_memory(MAX_AMOUNT_OF_NUMBERS_IN_BYTES); // выделение памяти дял 10 чисел в стеке
	stack1 -> size_max = (stack1 -> num) + 9;
	stack1 -> size_min = stack1 -> num;
	stack2 = (stack_t*)new_memory(sizeof(stack_t)); // выделение памяти дял стека
	stack2 -> num = (int32_t*)new_memory(MAX_AMOUNT_OF_NUMBERS_IN_BYTES); // выделение памяти дял 10 чисел в стеке
	stack3 = (stack_t*)new_memory(sizeof(stack_t)); // выделение памяти дял стека
	stack3 -> num = (int32_t*)new_memory(MAX_AMOUNT_OF_NUMBERS_IN_BYTES); // выделение памяти дял 10 чисел в стеке
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
	//"ввод других символов или неверной последовательности знаков - и (пробел) приведёт к неизвестным последствиям!\n");
	tmp_box[MAX_BYTE_ELEMENT - 1] = '\n';
	uint8_t i = 0;
	char command;
	do {
		command = fgetc(stdin);
		tmp_box[i] = command;
		i++;
	} while (i <= MAX_BYTE_ELEMENT - 1 and '\n' != command and EOF != command); // проверка колличества введённых символов
	if ('\n' != tmp_box[MAX_BYTE_ELEMENT - 1] and 'я' != tmp_box[MAX_BYTE_ELEMENT - 1]) {
		printf("Слишком много данных\nПрограмма не была выполнена\n");
	}
	else {
		change_char_to_int32(stack1, tmp_box); // тут запуск функции чтобы все числа char преобразовать в int32_t и записать в стек
	}

	tmp_box = (char*)free_memory(tmp_box);
	stack1 -> num = (int32_t*)free_memory(stack1 -> num);
	stack1 = (stack_t*)free_memory(stack1);
	stack2 -> num = (int32_t*)free_memory(stack2 -> num);
	stack2 = (stack_t*)free_memory(stack2);
	stack3 -> num = (int32_t*)free_memory(stack3 -> num);
	stack3 = (stack_t*)free_memory(stack3);
	return 0;
}


