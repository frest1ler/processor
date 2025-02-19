#include <stdio.h>
#include <stdlib.h>
#include "working_with_data.h"
#include "myassert.h"

void check_capacity(Stack_t * stack)
{
    int fill_poison = 0;

    if (stack->size >= stack->capacity)
    {
        stack->capacity *= CAPACITY_GROWTH_RATE;

        fill_poison++;
    }
    else if (stack->size < GIVEN_PART(stack->capacity))
    {
        stack->capacity = GIVEN_PART(stack->capacity);
    }
    else
    {
        return;
    }
    #ifdef  PROTECTION_ON
        stack_elem_t* array = (stack_elem_t*)realloc(stack->data - 1,
                                                     stack->capacity * sizeof(stack_elem_t) +
                                                     NUM_CANARY_ARRAY * sizeof(double));
    #else
        stack_elem_t* array = (stack_elem_t*)realloc(stack->data, stack->capacity * sizeof(stack_elem_t));
    #endif /* PROTECTION_ON*/

    stack->data = array + 1;

    #ifdef PROTECTION_ON
        *(stack->data + stack->capacity) = CANARY_PROTECTION_4;
    #endif /* PROTECTION_ON*/

    #ifdef  PROTECTION_ON
        if (fill_poison)
        {
            pour_poison_into_empty(stack->data, stack->size, stack->capacity);
        }
    #endif /* PROTECTION_ON*/
    verify(ASSERT);
}
#ifdef PROTECTION_ON
    void pour_poison_into_empty(stack_elem_t* data, int size, int capacity)
    {
        for(int i = 0; size + i < capacity; i++)
        {
            data[size + i] = POISON;
        }
    }

    unsigned long hash(void* array, size_t size)
    {
        unsigned long hash = 5381;

        unsigned char* byte_array = (unsigned char*)array;

        for(size_t i = 0; i < size; i++)
        {
            hash = ((hash << 5) + hash) + byte_array[i];
        }
        return hash;
    }
    
#endif /*PROTECTION_ON*/

void free_up_memory_from_text(Info_about_text* info)
{
    if (info->text != NULL)
    {
        free(info->text);
    }
    else
    {
        printf("NULL ptr_text\n");
    }

    if (info->ptr_line != NULL)
    {
        free(info->ptr_line);  
    }
    else
    {
        printf("NULL ptr_line\n");
    }
}