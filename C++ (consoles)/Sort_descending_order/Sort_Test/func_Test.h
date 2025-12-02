#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <clocale>


FILE* open_file(const char* path);
FILE* close_file(FILE* file);
bool test_check(FILE* Print_comands, FILE* gdt, char num_test);



bool test_check(FILE* Print_comands, FILE* gdt, char num_test) {
	if (NULL == Print_comands) {
		Print_comands = open_file("D:\\K2\\Programs\\Student\\C++ (consoles)\\Sort_descending_order\\Print_comands.txt");
		if (NULL == Print_comands) {
			return 1;
		}
	}
	if (NULL == gdt) {
		gdt = open_file("D:\\K2\\Programs\\Student\\C++ (consoles)\\Sort_descending_order\\gdt.txt");
		if (NULL == gdt) {
			close_file(Print_comands);
			return 1;
		}
	}
	bool result = false;
	int test_gdt;
	int test_Print_comands;
	int start_read;
	if ('1' == num_test) {
		start_read = 40; // байтовый сдвиг чтения в файле

	}
	else if ('2' == num_test) {
		start_read = 0; // байтовый сдвиг чтения в файле
	}
	else if ('3' == num_test) {
		start_read = 0; // байтовый сдвиг чтения в файле
	}
	else if ('4' == num_test) {
		start_read = 0; // байтовый сдвиг чтения в файле
	}
	else if ('5' == num_test) {
		start_read = 0; // байтовый сдвиг чтения в файле
	}
	else if ('6' == num_test) {
		start_read = 0; // байтовый сдвиг чтения в файле
	}
	else if ('7' == num_test) {
		start_read = 0; // байтовый сдвиг чтения в файле
	}
	else if ('8' == num_test) {
		start_read = 0; // байтовый сдвиг чтения в файле
	}
	else if ('9' == num_test) {
		start_read = 0; // байтовый сдвиг чтения в файле
	}
	else {
		printf("Ошибка выбора теста\n");
		return false;
	}

	fseek(gdt, start_read, SEEK_SET); // изменяет начальный байт для чтения файла, 0 == первый символ файла
	for (; ;) {
		test_gdt = fgetc(gdt);
		printf("%c\n", test_gdt); // удалить в релизе
		test_Print_comands = fgetc(Print_comands);
		printf("%c\n", test_Print_comands); // удалить в релизе
		if (EOF == test_gdt or EOF == test_Print_comands) {
			result = true;
			break;
		}
		if (test_gdt != test_Print_comands) {
			break;
		}

	}

	return result;
}

FILE* open_file(const char* path) {
	FILE* file = fopen(path, "rb");
	if (NULL == file) {
		printf("Ошибка открытия файла, файл не найден %s\n", path);
		return NULL;
	}
	return file;
}

FILE* close_file(FILE* file) {
	if (NULL == file) {
		printf("Предупреждение - память не была очищена потомучто был подан NULL\n");
		return NULL;
	}
	else {
		fclose(file);
	}
	return NULL;
}