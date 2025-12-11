#include <assert.h>


#include "Unlimited_size_queue.h"
#include "Unlimited_size_queue.c"
#include "error.h"

#define ARR_SIZE 5


int main(){
    error_t error;
    int test_arr[ARR_SIZE] = {1, 2, 3, 4, 5};
    UnlimitedSizeQueue *queue = UnlimitedSizeQueue_new(&error);
    assert(SUCCESS == error);
    assert(NULL != queue -> list);

    for(int i = 0; i < ARR_SIZE; i++){
        UnlimitedSizeQueue_enqueue(queue, test_arr[i], &error);
        assert(SUCCESS == error);
        assert(NULL != queue);
    }

    printf("start: ");
    UnlimitedSizeQueue_print(queue, &error);
    assert(SUCCESS == error);
    assert(NULL != queue);
    printf(" end\n");

    int element = UnlimitedSizeQueue_dequeue(queue, &error);
    assert(SUCCESS == error);
    assert(NULL != queue);
    assert(test_arr[0] == element);
    printf("first element: %d\n", element);

    printf("start: ");
    UnlimitedSizeQueue_print(queue, &error);
    assert(SUCCESS == error);
    assert(NULL != queue);
    printf(" end\n");

    size_t size = UnlimitedSizeQueue_get_size(queue, &error);
    assert(SUCCESS == error);
    assert(NULL != queue);
    assert(4 == size);
    printf("size queue %d\n", size);

    bool empty = UnlimitedSizeQueue_is_empty(queue, &error);
    if(0 == empty){
        printf("false\n");
    }
    else{
        printf("true\n");
    }
    assert(SUCCESS == error);
    assert(NULL != queue);

    for(int i = 1; i < ARR_SIZE; i++){
        int element = UnlimitedSizeQueue_dequeue(queue, &error);
        assert(SUCCESS == error);
        assert(NULL != queue);
    }

    empty = UnlimitedSizeQueue_is_empty(queue, &error);
    if(0 == empty){
        printf("false\n");
    }
    else{
        printf("true\n");
    }
    assert(SUCCESS == error);
    assert(NULL != queue);

    UnlimitedSizeQueue_dequeue(queue, &error);
    assert(COLLECTION_IS_EMPTY_ERROR == error);
    error = SUCCESS;
    assert(NULL != queue);

    UnlimitedSizeQueue_peek(queue, &error);
    assert(COLLECTION_IS_EMPTY_ERROR == error);
    error = SUCCESS;
    assert(NULL != queue);

    size = UnlimitedSizeQueue_get_size(queue, &error);
    assert(0 == size);
    assert(SUCCESS == error);
    assert(NULL != queue);

    UnlimitedSizeQueue_print(queue, &error);
    assert(COLLECTION_IS_EMPTY_ERROR == error);
    error = SUCCESS;
    assert(NULL != queue);


    UnlimitedSizeQueue_destruct(&queue, &error);
    assert(SUCCESS == error);
    assert(NULL == queue);

    printf("Works great!\n");
    return 0;
}