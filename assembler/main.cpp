#include "read_commands.h"
#include "write_to_file.h"

int main()
{
    Info_about_text info = {};

    read_commands(&info);

    init_pointer_array(&info);

    stack_elem_t* code = code_ctor(&info);

    encode_to_asm(&info, code);

    code_dtor(code);

    return 0;
}