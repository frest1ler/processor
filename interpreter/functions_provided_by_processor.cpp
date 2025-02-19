#include <stdio.h>
#include <math.h>
#include "working_with_data.h"
#include "functions_provided_by_processor.h"
#include "stack_functions.h"
#include "myassert.h"

void add(Stack_t * stack)
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

void sub(Stack_t * stack)
{
    verify(ASSERT);

    if (stack->size < 2)
    {
        printf("There are not enough elements");

        return;
    }

    stack_elem_t first  = stack_pop(stack);
    stack_elem_t second = stack_pop(stack); //also

    stack_push(stack, first - second);

    verify(ASSERT);
}

void mul(Stack_t * stack)
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

void div(Stack_t * stack)
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

void out(Stack_t * stack)
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

void sqrt_c(Stack_t * stack)
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

void sin_c(Stack_t * stack)
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

void cos_c(Stack_t * stack)
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

void hlt(Stack_t * stack)
{
    stack_destroy(stack);

    exit(EXIT_FAILURE);
}
