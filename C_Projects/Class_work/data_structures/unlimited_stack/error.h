#ifndef ERROR_H
#define ERROR_H


#include <stdio.h>

typedef enum {
    SUCCESS,
    NULL_POINTER_ERROR,
    NOT_ENOUGH_MEMORY_ERROR,
    BUFFER_OVERFLOW_ERROR,
    WRONG_LIMITS_ERROR,
    COLLECTION_IS_EMPTY_ERROR,
} error_t;



#endif  // ERROR_H
