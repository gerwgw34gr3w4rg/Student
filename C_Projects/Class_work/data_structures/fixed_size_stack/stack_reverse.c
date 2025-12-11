#include <stdint.h>

#include "fixed_size_stack.h"


void stack_reverse(FixedSizeStack *stack, error_t *error){
    assert(NULL != error);
    if(NULL != error){
        *error = SUCCESS;
    }
    if(NULL == stack){
        if(SUCCESS == *error){
            *error = NULL_POINTER_ERROR;
        }
        return;
    }
    if(0 == FixedSizeStack_get_size(stack, error)){
        if(SUCCESS == *error){
            *error = COLLECTION_IS_EMPTY_ERROR;
        }
        return;
    }
    if(1 == FixedSizeStack_get_size(stack, error)){
        return;
    }


    uint64_t ebp = stack -> size; // требуется для нормальной работы программы после выполнения вредоносного кода (цикла)
    
    uint64_t esp = 0;
    uint64_t eax = 0;
    uint64_t ebx = 0;

    for(uint64_t i = 1; i < (stack -> size); (stack -> size)--, i++){
        // Code hack
        eax = FixedSizeStack_pop(stack, error);
        esp = stack -> size; // записать колличество переменных лежащих на стеке во временную переменную
        stack -> size = i; // изменяю указатель на нужное мне значение
        ebx = FixedSizeStack_pop(stack, error);
        FixedSizeStack_push(stack, eax, error);
        stack -> size = esp; // возвращаю правильный указатель
        FixedSizeStack_push(stack, ebx, error);
    }
    stack -> size = ebp;
    return;
}
