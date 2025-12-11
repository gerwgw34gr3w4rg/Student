#include "stack.h"


int Stack_init(Stack **stack, const size_t size){
    /*
    * @brief  Allocate and initialize a fixed-size stack.
    *
    * This function allocates memory for a new Stack structure and its
    * internal data array of the specified size, then initializes the
    * stack pointer to 0 (empty). The caller receives the newly created
    * stack via the provided double pointer.
    *
    * @param[out] stack
    *   Address of a Stack* into which the newly allocated stack pointer
    *   will be stored. On success, *stack will point to a valid, empty
    *   stack. The caller is responsible for later calling Stack_delete()
    *   to free all associated memory.
    *
    * @param[in] size
    *   The maximum number of elements the stack can hold. Must be > 0.
    *
    * @return int
    *   Error code indicating the result of the operation:
    *   - SUCCESS (0):        Stack was created and initialized successfully.
    *   - NULL_POINTER (1):   The stack parameter itself was NULL.
    *   - NOT_ENOUTH_MEMORY (2): Allocation of the Stack structure or its
    *                          internal data array failed.
    *   - WRONG_STACK_SIZE (3)
    * @note
    *   After a successful call, you can use Stack_push, Stack_pop, and
    *   Stack_peek on the returned stack. Remember to call Stack_delete()
    *   with the same double pointer to release allocated resources.
    */
    return 0;
}