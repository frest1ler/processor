#include <stdio.h>
#include "stack_functions.h"
#include "read_from_file_comands.h"
#include "working_with_data.h"

int main()
{
    Stack_t*   stack = (Stack_t*)  get_pointer_array(1, sizeof(Stack_t)  );
    Text_info* info  = (Text_info*)get_pointer_array(1, sizeof(Text_info));

    stack_ctor(stack);

    read_from_file_comands(info);

    perform_comands(stack, info);

    free_up_memory_from_text(info);

    stack_destroy(stack);

    return 0;
}

