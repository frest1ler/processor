#include <stdio.h>
#include "stack.h"
#include "stack_functions.h"
#include "functions_provided_by_processor.h"
#include "run.h"

int main()
{
    Stack_t* stack = get_pointer_stack();

    stack_ctor(stack);

    run(stack);

    stack_destroy(stack);

    return 0;
}

