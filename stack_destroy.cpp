#include <stdlib.h>
#include "stack_destroy.h"

void stack_destroy(Stack_t * stack)
{
    if (stack->data - 1 != NULL)
    {
        free(stack->data - 1);
    }
    if (stack != NULL)
    {
        free(stack);
    }
}
