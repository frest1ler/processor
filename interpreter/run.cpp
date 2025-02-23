#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "run.h"
#include "stack_functions.h"
#include "functions_provided_by_processor.h"
#include "read_from_file_comands.h"
#include "working_with_data.h"

void perform_comands(Stack_t* stack, Info_about_text* info)
{
    int i   = 0;
    while(info->text[i] != HLT && i < info->size_text)
    {
        if (info->text[i] == PUSH)
        {
            i++;
            int argument = info->text[i];

            stack_push(stack, argument);
        }
        else if (info->text[i] == POP)
        {
            stack_pop(stack);
        }
        else if (info->text[i] == ADD)
        {
            add(stack);
        }
        else if (info->text[i] == SUB)
        {
            sub(stack);
        }
        else if (info->text[i] == MUL)
        {
            mul(stack);
        }
        else if (info->text[i] == DIV)
        {
            div(stack);
        }
        else if (info->text[i] == OUT)
        {
            out(stack);
        }
        else if (info->text[i] == SQRT_C)
        {
            sqrt_c(stack);
        }
        else if (info->text[i] == SIN_C)
        {
            sin_c(stack);
        }
        else if (info->text[i] == COS_C)
        {
            cos_c(stack);
        }
        else if (info->text[i] == HLT)
        {       
            hlt(stack);
        }
        else
        {
            printf("\n%d : there is no such command\n", info->text[i]);

            hlt(stack);
        }
        i++;
    }
}
