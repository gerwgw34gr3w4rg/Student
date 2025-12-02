#include "func_Sort_Main.h"

int main(){
	setlocale(LC_CTYPE, "Russian");

	//int32_t max  2147483647 //10 байт + 1 байт пробел
	//int32_t min -2147483648 //11 байт + 1 байт пробел
	// в конце + 2 байта \n

	//нужно 130 байт
	//int8_t max = 10;
	//int8_t min = 0;
	stack_form* stack1 = NULL;
	stack_form* stack2 = NULL;
	stack_form* stack3 = NULL;

	stack1 = new_stack();
	stack2 = new_stack();
	stack3 = new_stack();

	//код программы

	delete_stack(stack1);
	delete_stack(stack2);
	delete_stack(stack3);
	return 0;
}


stack_form* new_stack() {
	stack_form* pointer = NULL;
	pointer = (stack_form*)malloc(130);
	if (NULL == pointer) {
		printf("Ошибка выделения памяти в функции new_stack\n");
	}
	return pointer;
}
void* delete_stack(stack_form* ptr) {
	if (NULL == ptr) {
		printf("Предупреждение - функция delete_stack получила NULL, память не будет очищена\n");
		return NULL;
	}
	free(ptr);
	return NULL;
}