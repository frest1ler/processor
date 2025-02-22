#include "read_from_file_comands.h"
#include "write_asm_comands_to_file.h"

int main()
{
    Info_about_text info = {};

    read_from_file_comands(&info);

    initialize_pointer_array(&info);

    stack_elem_t* code = code_ctor(&info);

    encode_data_to_asm(&info, code);

    code_dtor(code);

    return 0;
}