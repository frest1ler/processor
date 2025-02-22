#ifndef WRITE_ASM_COMANDS_TO_FILE_H
#define WRITE_ASM_COMANDS_TO_FILE_H

#include <stdio.h>

const int COMMAND_LENGTH  = 50;
const int ARGUMENT_LENGTH = 50;

typedef int stack_elem_t;

struct Info_about_text
{
    int    max_number_line;
    int    size_text      ;
    char*  text           ;
    char** ptr_line       ;
};

enum Compare_const
{
    FIRST_CHAR_IS_BIGGER  =  1,
    CHARS_ARE_EQUAL       =  0,
    SECOND_CHAR_IS_BIGGER = -1,
    FIRST_LINE_IS_BIGGER  =  1,
    LINE_ARE_EQUAL        =  0,
    SECOND_LINE_IS_BIGGER = -1,
};

enum Function_identifier
{
    PUSH   = 1,
    POP    = 2,
    ADD    = 3,
    SUB    = 4,
    MUL    = 5,
    DIV    = 6,
    OUT    = 7,
    SQRT_C = 8,
    SIN_C  = 9,
    COS_C  = 10,
    HLT    = -1,
};

void perform_comands(char* comands, size_t* ip, stack_elem_t* code);
void encode_data_to_asm(Info_about_text* info, stack_elem_t* code);

#endif /*WRITE_ASM_COMANDS_TO_FILE_H*/
