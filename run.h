#ifndef RUN_H
#define RUN_H

#include "stack.h"

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

void run(Stack_t* stack);

#endif /*RUN_H*/
