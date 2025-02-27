#ifndef RUN_H
#define RUN_H

const int ARGUMENT_LENGTH = 50;
const int COMMAND_LENGTH  = 50;

#include "stack.h"

struct Text_info
{
    int  size_text;
    int* text     ;
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
    JMP    = 11,
    HLT    = -1,
};

void perform_commands(Stack_t* stack, Text_info* info);

#endif /*RUN_H*/
