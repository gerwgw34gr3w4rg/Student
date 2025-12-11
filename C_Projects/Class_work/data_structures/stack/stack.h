#ifndef STACK_H
#define STACK_H

#include <inttypes.h>
#include <stdlib.h>


/* Fixed size stack */
typedef struct{
    int64_t *__data;  // Pointer to stack data
    size_t __stack_pointer;  // Current stack fullness level
    const size_t __size;  // Fixed stack size
} Stack;


// Error codes
#define SUCCESS 0
#define NULL_POINTER 1
#define NOT_ENOUTH_MEMORY 2
#define WONG_STACK_SIZE 3


int Stack_init(Stack **stack, const size_t size);
int Stack_push(Stack *stack, int64_t value);
int Stack_pop(Stack *stack, int64_t *value);
int Stack_peek(Stack *stack, int64_t *value);
int Stack_delete(Stack **stack, int *error_number);










#endif  // STACK_H
