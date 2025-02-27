#ifndef READ_FROM_FILE_COMANDS_H
#define READ_FROM_FILE_COMANDS_H

#include "write_to_file.h"

void read_commands(Info_about_text* info);
void init_pointer_array(Info_about_text* info);
void code_dtor(stack_elem_t* code);
stack_elem_t* code_ctor(Info_about_text* info);

#endif /*READ_FROM_FILE_COMANDS_H*/
