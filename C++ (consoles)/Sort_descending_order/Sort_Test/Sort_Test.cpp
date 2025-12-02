#include "func_Test.h"


//после выполнения теста в файле должен быть мусор!
int main(){
	setlocale(LC_CTYPE, "Russian");
	FILE* Print_comands = NULL;
	FILE* gdt = NULL; // готовые домашние тесты
	bool test_result = false;
	printf("Памятка\nВходные данные:\n");
	printf("test 1 - 1 2 3\n");
	printf("test 2 - 3 4 1 2\n");
	printf("test 3 - 0 0 1 2\n");
	printf("test 4 - -10 -3 4 0\n");
	printf("test 5 - 0 0 0 0 0 0 0 0 0 0\n");
	printf("test 6 - 0\n");
	printf("test 7 - -2147483648\n");
	printf("test 8 - 3 2 1\n");
	printf("test 9 - 3 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n");
	printf("Какой тест запустить ? ( от 1 до 9). Любой другой символ завершит программу\nТест ");
	char num_test = fgetc(stdin);
	for (; '0' < num_test and num_test <= '9';) {
		getchar(); // очистка буфера от \n
		test_result = test_check(Print_comands, gdt, num_test);
		if (true == test_result) {
			printf("Тест %c выполнен успешно\n", num_test);
			test_result = false;
		}
		else {
			printf("Тест %c выполнен провально\n", num_test);
		}
		Print_comands = close_file(Print_comands);
		gdt = close_file(gdt);
		printf("Какой тест запустить ? ( от 1 до 9). Любой другой символ завершит программу\nТест ");
		num_test = fgetc(stdin);
	}


	//Print_comands = close_file(Print_comands);
	//gdt = close_file(gdt);
	return 0;
}



