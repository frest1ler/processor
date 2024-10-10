#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "working_with_data.h"
#include "stack_ctor.h"
#include "myassert.h"

Stack_t* get_poiter_stack()
{
    Stack_t* stack = (Stack_t*)calloc(1, sizeof(Stack_t*));

    return stack;
}

void stack_ctor(Stack_t * stack)
{
    assert(stack);

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

    verify(ASSERT); //TODO myassert is macro define not func
}
