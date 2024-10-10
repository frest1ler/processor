#include <stdio.h>
#include "stack.h"
#include "stack_functions.h"
#include "functions_provided_by_processor.h"

int main()
{
    Stack_t stack = *get_poiter_stack();

    stack_ctor(&stack);

//     for(int i = 1; i <= 300; i++)
//     {
//         stack_push(&stack, i);
//         printf("\nstack: capacity: %d; size: %d\n", stack.capacity, stack.size);
//         //printf("stack.expected_hash_sum = %lf\nstack.hash_sum = %lf", stack.expected_hash_sum, stack.hash_sum);
//     }
//
//     for(int i = 1; i <= 302; i++)
//     {
//         stack_pop(&stack);
//         printf("\nstack: capacity: %d; size: %d\n", stack.capacity, stack.size);
//         //printf("stack.expected_hash_sum = %lf\nstack.hash_sum = %lf", stack.expected_hash_sum, stack.hash_sum);
//     }
    stack_push(&stack, 60);
    stack_push(&stack, 80);
    subtract_penultimate_from_last(&stack);
    stack_push(&stack, 30);
    stack_push(&stack, 70);
    add_last_two_elements(&stack);
    divide_last_by_penultimate(&stack);
    sqrt_calculate(&stack);

    stack_destroy(&stack);

    return 0;
}

