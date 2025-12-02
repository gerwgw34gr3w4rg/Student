#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <clocale>
#include <stdint.h>



typedef struct {
	int8_t max;
	int8_t min;
	int8_t pointer;
} stack_form;
stack_form* new_stack();
void* delete_stack(stack_form* ptr);