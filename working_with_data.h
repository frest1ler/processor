#ifndef WORKING_WITH_DATA_H
#define WORKING_WITH_DATA_H

#include "stack.h"

#ifdef PROTECTION_ON
    void          pour_poison_into_empty(stack_elem_t* data, int size, int capacity);
    void          check_capacity(Stack_t * stack);
    void          setTextColor(int color);
    unsigned long hash(void* array, size_t size);
#else
    void          check_capacity(Stack_t * stack);
#endif /*PROTECTION_ON*/
#endif /*WORKING_WITH_DATA_H*/
