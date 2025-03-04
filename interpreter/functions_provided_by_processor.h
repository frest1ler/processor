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
void input (Stack_t * stack);

void jmp   (Spu* info                 );
void ja    (Spu* info, Stack_t * stack);
void jae   (Spu* info, Stack_t * stack);
void jb    (Spu* info, Stack_t * stack);
void jbe   (Spu* info, Stack_t * stack);
void je    (Spu* info, Stack_t * stack);
void jne   (Spu* info, Stack_t * stack);

#endif /*FUNCTIONS_PROVIDED_BY_PROCESSOR_H*/
