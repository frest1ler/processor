#ifndef FUNCTIONS_PROVIDED_BY_PROCESSOR_H
#define FUNCTIONS_PROVIDED_BY_PROCESSOR_H

#include "stack.h"

void add   (Stack_t * stack);
void sub   (Stack_t * stack);
void mul   (Stack_t * stack);
void div   (Stack_t * stack);
void out   (Stack_t * stack);
void sqrt_c(Stack_t * stack);
void sin_c (Stack_t * stack);
void cos_c (Stack_t * stack);
void hlt   (Stack_t * stack);

void jmp   (Text_info* info                 );
void ja    (Text_info* info, Stack_t * stack);
void jae   (Text_info* info, Stack_t * stack);
void jb    (Text_info* info, Stack_t * stack);
void jbe   (Text_info* info, Stack_t * stack);
void je    (Text_info* info, Stack_t * stack);
void jne   (Text_info* info, Stack_t * stack);

#endif /*FUNCTIONS_PROVIDED_BY_PROCESSOR_H*/
