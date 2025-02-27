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

void jmp(Text_info* info)
{   
    info->ip = info->text[info->ip + 1] - 1;    
}

void ja(Text_info* info, Stack_t * stack)
{
    stack_elem_t a = stack_pop(stack);
    stack_elem_t b = stack_pop(stack);

    if (a > b)
    {
        jmp(info);
    }
}

void jae(Text_info* info, Stack_t * stack)
{
    stack_elem_t a = stack_pop(stack);
    stack_elem_t b = stack_pop(stack);

    if (a >= b)
    {
        jmp(info);
    }
}

void jb(Text_info* info, Stack_t * stack)
{
    stack_elem_t a = stack_pop(stack);
    stack_elem_t b = stack_pop(stack);

    if (a < b)
    {
        jmp(info);
    }
}

void jbe(Text_info* info, Stack_t * stack)
{
    stack_elem_t a = stack_pop(stack);
    stack_elem_t b = stack_pop(stack);

    if (a <= b)
    {
        jmp(info);
    }
}

void je(Text_info* info, Stack_t * stack)
{
    stack_elem_t a = stack_pop(stack);
    stack_elem_t b = stack_pop(stack);

    if (a == b)
    {
        jmp(info);
    }
}

void jne(Text_info* info, Stack_t * stack)
{
    stack_elem_t a = stack_pop(stack);
    stack_elem_t b = stack_pop(stack);

    if (a != b)
    {
        jmp(info);
    }
}

// void pushr(Text_info* info, stack_elem_t argument)
// {

// }