#ifndef WRITE_ASM_COMANDS_TO_FILE_H
#define WRITE_ASM_COMANDS_TO_FILE_H

const int COMMAND_LENGTH  = 50;
const int ARGUMENT_LENGTH = 50;

#include "run.h"

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

#endif /*WRITE_ASM_COMANDS_TO_FILE_H*/
