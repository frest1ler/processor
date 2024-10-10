#ifndef MYASSERT_H
#define MYASSERT_H

#include "stack.h"

#define ASSERT stack,__FILE__,__LINE__ //TODO rename

void verify(Stack_t * stack, const char* file, int line);
int stack_error(Stack_t * stack);

enum ERROR_VALUE
{
    INCORRECT_VALUE_LEFT_CANARY_STRUCT  =   1,
    NULL_POINTER_DATA                   =   2,
    NEGATIVE_CAPACITY                   =   4,
    INCORRECT_VALUE_RIGHT_CANARY_STRUCT =   8,
    NEGATIVE_SIZE                       =  16,
    INCORRECT_VALUE_LEFT_CANARY_ARRAY   =  32,
    INCORRECT_VALUE_RIGHT_CANARY_ARRAY  =  64,
    HASH_AMOUNT_MISMATCH                = 128
};

#endif /*MYASSERT_H*/
