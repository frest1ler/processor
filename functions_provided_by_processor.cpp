#include <stdio.h>
#include <math.h>
#include "functions_provided_by_processor.h"
#include "stack_pop.h"
#include "stack_push.h"
#include "stack_destroy.h"
#include "myassert.h"

void add_last_two_elements(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 2)
    {
        printf("There are not enough elements");

        return;
    }

    stack_elem_t first  = stack_pop(stack); // TODO i make it only for int, need will made for double
    stack_elem_t second = stack_pop(stack);

    stack_push(stack, first + second);

    verify(ASSERT);
}

void subtract_penultimate_from_last(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 2)
    {
        printf("There are not enough elements");

        return;
    }

    stack_elem_t first  = stack_pop(stack);
    stack_elem_t second = stack_pop(stack); //also

    stack_push(stack, first - second);\

    verify(ASSERT);
}

void multiply_last_two(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 2)
    {
        printf("There are not enough elements");

        return;
    }

    stack_elem_t first  = stack_pop(stack);
    stack_elem_t second = stack_pop(stack);

    stack_push(stack, first * second);

    verify(ASSERT);
}

void divide_last_by_penultimate(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 2)
    {
        printf("There are not enough elements");

        return;
    }

    stack_elem_t first  = stack_pop(stack);
    stack_elem_t second = stack_pop(stack);

    stack_push(stack, first / second);

    verify(ASSERT);
}

void output_last(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 1)
    {
        printf("There are no elements\n");

        return;
    }

    printf("last element = " STACK_SPECIFIER"\n", stack->data[stack->size - 1]);

    verify(ASSERT);
}

void sqrt_calculate(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 1)
    {
        printf("There are no elements\n");

        return;
    }

    stack_elem_t a = stack_pop(stack);

    a = sqrt(a);

    stack_push(stack, a);

    verify(ASSERT);
}

void sin_calculate(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 1)
    {
        printf("There are no elements\n");

        return;
    }

    stack_elem_t a = stack_pop(stack);

    a = sin(a);

    stack_push(stack, a);

    verify(ASSERT);
}

void cos_calculate(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 1)
    {
        printf("There are no elements\n");

        return;
    }
    stack_elem_t a = stack_pop(stack);

    a = cos(a);

    stack_push(stack, a);

    verify(ASSERT);
}
