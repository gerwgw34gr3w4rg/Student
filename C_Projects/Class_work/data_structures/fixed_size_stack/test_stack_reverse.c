#include <assert.h>
#include <stdio.h>


#include "fixed_size_stack.h"
#include "error.h"


void stack_reverse(FixedSizeStack *stack, error_t *error);


int main(){
    size_t buffer_size = 100;
    error_t error;

    FixedSizeStack *stack = FixedSizeStack_new(buffer_size, &error);
    assert(NULL != stack);
    assert(SUCCESS == error);
    assert(NULL != stack -> buffer);
    assert(buffer_size == stack -> buffer_size);
    assert(0 == stack -> size);

    for(size_t i = 0; i < 10; i++){
        FixedSizeStack_push(stack, ((i * 10) + 10), &error);
        FixedSizeStack_print(stack, &error);
    }

    printf("====================  reversal  ====================\n");
    stack_reverse(stack, &error);
    
    for(size_t i = 0; i < stack -> size;){
        FixedSizeStack_print(stack, &error);
        FixedSizeStack_pop(stack, &error); // я не знаю куда оно возвращает, надеюсь ты мне расскажешь (на низком и высоком уровнях)
    }

    
    printf("\nSUCCESS!\n");
    return 0;
}
