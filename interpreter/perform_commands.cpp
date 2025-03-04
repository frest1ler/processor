#include <stdio.h>
#include <limits.h>
#include "perform_commands.h"
#include "stack_functions.h"
#include "functions_provided_by_processor.h"

void perform_commands(Stack_t* stack, Spu* info)
{
    while(info->ip < info->size_text)
    {
        if ((info->text[info->ip] & REMOVE_MASK) == PUSH)
        {
            (info->ip)++;
            int argument = info->text[info->ip];

            if (info->text[info->ip - 1] == PUSH){
                stack_push(stack, argument);    
            }
            else{
                stack_push(stack, info->registers[argument - 1]);        
            }
        }
        else if ((info->text[info->ip] & REMOVE_MASK) == POP)
        {
            int argument = stack_pop(stack);

            if (info->text[info->ip] != POP)
            {
                (info->ip)++;

                int n_reg = info->text[info->ip];

                info->registers[n_reg - 1] = argument;
            }
        }
        else if (info->text[info->ip] == ADD){
            add(stack);
        }
        else if (info->text[info->ip] == SUB){
            sub(stack);
        }
        else if (info->text[info->ip] == MUL){
            mul(stack);
        }
        else if (info->text[info->ip] == DIV){
            div(stack);
        }
        else if (info->text[info->ip] == OUT){
            out(stack);
        }
        else if (info->text[info->ip] == SQRT_C){
            sqrt_c(stack);
        }
        else if (info->text[info->ip] == SIN_C){
            sin_c(stack);
        }
        else if (info->text[info->ip] == COS_C){
            cos_c(stack);
        }
        else if (info->text[info->ip] == HLT){    
            hlt(stack);
        }
        else if(info->text[info->ip] == JMP){
            jmp(info);
        }
        else if(info->text[info->ip] == JA){
            ja(info, stack);
        }
        else if(info->text[info->ip] == JB){
            jb(info, stack);
        }
        else if(info->text[info->ip] == JBE){
            jbe(info, stack);
        }
        else if(info->text[info->ip] == JE){
            je(info, stack);
        }
        else if(info->text[info->ip] == JNE){
            jne(info, stack);
        }
        else if(info->text[info->ip] == IN){
            input(stack);
        }
        else
        {
            printf("\n%d : there is no such command\n", info->text[info->ip]);

            hlt(stack);
        }
        (info->ip)++;
    }
    printf("in programm was missed the hlt");

    hlt(stack);
}