#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "working_with_data.h"
#include "stack_functions.h"
#include "myassert.h"
#include "dump.h"

int stack_push(Stack_t * stack, stack_elem_t added_value)
{
    verify(ASSERT);

    check_capacity(stack);

    stack->data[stack->size] = added_value;
    stack->size++;

    #ifdef PROTECTION_ON
        stack->etalon_hash_sum = hash(stack->data, stack->size);
    #endif /*PROTECTION_ON*/

    verify(ASSERT);

    dump(stack);

    return 0;
}

stack_elem_t stack_pop (Stack_t * stack)
{
    verify(ASSERT);

    stack_elem_t return_value = 0;

    if (stack->size == 0){
        return return_value;
    }

    check_capacity(stack);

    return_value = stack->data[stack->size - 1];

    #ifdef PROTECTION_ON
        stack->data[stack->size - 1] = POISON;
    #else
        stack->data[stack->size - 1] = 0;
    #endif /*PROTECTION_ON*/

    stack->size--;

    #ifdef PROTECTION_ON
        stack->etalon_hash_sum = hash(stack->data, stack->size);
    #endif /*PROTECTION_ON*/

    verify(ASSERT);

    dump(stack);

    return return_value;
}

void stack_destroy(Stack_t * stack)
{
    #ifdef PROTECTION_ON
        if (stack->data - 1 != NULL){
            free(stack->data - 1);
        }
    #else
        if (stack->data != NULL){
            free(stack->data);
        }
    #endif /*PROTECTION_ON*/

    if (stack != NULL){
        free(stack);
    }
}

void stack_ctor(Stack_t * stack)
{
    assert(stack);
    #ifdef PROTECTION_ON
        stack->capacity                = INITIAL_CAPACITY   ;
        stack->size                    = INITIAL_SIZE       ;
        stack->etalon_hash_sum         = INITIAL_HASH_SUM   ;
        stack->hash_sum                = INITIAL_HASH_SUM   ;
        stack->left_canary_protection  = CANARY_PROTECTION_1;
        stack->right_canary_protection = CANARY_PROTECTION_2;

        stack_elem_t* array = (stack_elem_t*)calloc(stack->capacity * sizeof(stack_elem_t)
                                                    + NUM_CANARY_ARRAY * sizeof(double), 1);

        *array                         = CANARY_PROTECTION_3;
        *(array + stack->capacity + 1) = CANARY_PROTECTION_4;

        stack->data = array + 1;

        pour_poison_into_empty(stack->data, stack->size, stack->capacity);
    #else
        stack->capacity                = INITIAL_CAPACITY   ;
        stack->size                    = INITIAL_SIZE       ;

        stack->data = (stack_elem_t*)calloc(stack->capacity * sizeof(stack_elem_t), 1);
    #endif /*PROTECTION_ON*/

    verify(ASSERT); //TODO myassert is macro define not func
}
