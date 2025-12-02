#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <clocale>
FILE* open_file(const char* path);
FILE* close_file(FILE* file);
bool test_check(FILE* Print_comands, FILE* gdt, char num_test);