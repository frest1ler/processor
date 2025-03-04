#include <stdio.h>
#include "stack_functions.h"
#include "read_from_file_comands.h"
#include "working_with_data.h"

int main()
{
    Stack_t*   stack = (Stack_t*) get_pointer_array(1, sizeof(Stack_t));
    Spu*       info  = (Spu*)     get_pointer_array(1, sizeof(Spu)    );

    stack_ctor(stack);

    read_from_file_comands(info);

    perform_commands(stack, info);

    free_up_memory_from_text(info);

    stack_destroy(stack);

    return 0;
}

