#include <stdio.h>
#include "dump.h"

void dump(Stack_t * stack)
{
    #ifdef PROTECTION_ON
        printf("\n\n\nstack->capacity = %d\nstack->size = %d\n"
               "stack->hash_sum = %lu\nstack->expected_hash_sum = %lu\n"
               "stack->left_canary_protection = " CANARY_SPECIFIER" \n"
               "stack->right_canary_protection = " CANARY_SPECIFIER" \n"
               "*(stack->data - 1) = " CANARY_SPECIFIER"\n*(stack->data + stack->capacity) = " CANARY_SPECIFIER"\n\n"
               , stack->capacity, stack->size, stack->hash_sum, stack->etalon_hash_sum,
               stack->left_canary_protection, stack->right_canary_protection,
               *(stack->data - 1), *(stack->data + stack->capacity));

        printf("" CANARY_SPECIFIER"(%d) ", *(stack->data - 1), 0);

        for(int j = 0; j < stack->capacity; j++)
        {
            printf("" STACK_SPECIFIER"(%d) ", *(stack->data + j), j + 1);
        }

        printf("" CANARY_SPECIFIER"(%d) ", *(stack->data + stack->capacity), stack->capacity + 1);
    #else
    printf("\n\n\nstack->capacity = %d\nstack->size = %d\n"
           , stack->capacity, stack->size);

        for(int j = 0; j < stack->capacity; j++)
        {
            printf("" STACK_SPECIFIER"(%d) ", *(stack->data + j), j + 1);
        }
        
    #endif /*PROTECTION_ON*/
}
