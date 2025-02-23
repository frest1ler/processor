#ifndef WORKING_WITH_DATA_H
#define WORKING_WITH_DATA_H

#include "stack.h"
#include "perform_comands.h"

#ifdef PROTECTION_ON
    void          pour_poison_into_empty(stack_elem_t* data, int size, int capacity);
    void          check_capacity(Stack_t * stack);
    unsigned long hash(void* array, size_t size);
#else
    void          check_capacity(Stack_t * stack);
#endif /*PROTECTION_ON*/

void free_up_memory_from_text(Text_info* info);
void* get_pointer_array(size_t element_count, size_t element_size);
//Stack_t*     get_pointer_stack();

#endif /*WORKING_WITH_DATA_H*/
