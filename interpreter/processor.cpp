#include <stdio.h>
#include "stack.h"
#include "stack_functions.h"
#include "functions_provided_by_processor.h"
#include "run.h"
#include "read_from_file_comands.h"
#include "working_with_data.h"

int main()
{
    Stack_t* stack = get_pointer_stack();

    stack_ctor(stack);

    Info_about_text info = {};

    read_from_file_comands(&info);

    perform_comands(stack, &info);

    free_up_memory_from_text(&info);

    stack_destroy(stack);

    return 0;
}

