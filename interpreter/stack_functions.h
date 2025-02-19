#ifndef STACK_FUNCTION_H
#define STACK_FUNCTION_H

#include "stack.h"

int          stack_push      (Stack_t * stack, stack_elem_t added_value);
void         stack_ctor      (Stack_t * stack);
void         stack_destroy   (Stack_t * stack);
stack_elem_t stack_pop       (Stack_t * stack);
Stack_t*     get_pointer_stack();

#endif /*STACK_FUNCTION_H*/
