#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "write_asm_comands_to_file.h"

void copy_command_name(int* i, char* comands, char* cmd);
int command_argument_check(char* cmd, char* comands, int i);
int encode_command(char* cmd, size_t* ip, stack_elem_t* code, int argument);

void perform_comands(char* comands, size_t* ip, stack_elem_t* code)
{
    int i = 0;
    char cmd[COMMAND_LENGTH] = {};

    copy_command_name(&i, comands, cmd);

    int argument = command_argument_check(cmd, comands, i);

    encode_command(cmd, ip, code, argument);
}

void copy_command_name(int* i, char* comands, char* cmd)
{
    while(comands[*i] != ' ' && comands[*i] != '\0' &&
          comands[*i] != '\r' && *i < COMMAND_LENGTH)
    {
        //printf("i = %d\n", *i);
        
        cmd[*i] = comands[*i];
        (*i)++;
    }

    (*i)++;
}

int command_argument_check(char* cmd, char* comands, int i)
{
    char arg[ARGUMENT_LENGTH] = {};

    if (strcmp(cmd, "push") == 0)
    {
        int num = i;

        while(comands[i] != ' ' && comands[i] != '\0' &&
              comands[i] != '\r' && i < COMMAND_LENGTH)
        {
            arg[i - num] = comands[i];
            i++;
        }
        arg[i] = '\0';
    }
    return atoi(arg);
}

int encode_command(char* cmd, size_t* ip, stack_elem_t* code, int argument)
{
    if (strcmp(cmd, "push") == 0)
    {
        code[*ip] = PUSH;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "pop") == 0)
    {
        code[*ip] = POP;
        (*ip)++;
    }
    else if (strcmp(cmd, "add") == 0)
    {
        code[*ip] = ADD;
        (*ip)++;
    }
    else if (strcmp(cmd, "sub") == 0)
    {
        code[*ip] = SUB;
        (*ip)++;
    }
    else if (strcmp(cmd, "mul") == 0)
    {
        code[*ip] = MUL;
        (*ip)++;
    }
    else if (strcmp(cmd, "div") == 0)
    {
        code[*ip] = DIV;
        (*ip)++;
    }
    else if (strcmp(cmd, "out") == 0)
    {
        code[*ip] = OUT;
        (*ip)++;
    }
    else if (strcmp(cmd, "sqrt_c") == 0)
    {
        code[*ip] = SQRT_C;
        (*ip)++;
    }
    else if (strcmp(cmd, "sin_c") == 0)
    {
        code[*ip] = SIN_C;
        (*ip)++;
    }
    else if (strcmp(cmd, "cos_c") == 0)
    {
        code[*ip] = COS_C;
        (*ip)++;
    }
    else if (strcmp(cmd, "hlt") == 0)
    {
        code[*ip] = HLT;
        (*ip)++;
    }
    else
    {
        printf("%s", cmd);
        printf("%s : there is no such command\n", cmd);

        return 1;
    }
    printf("%s", cmd);

    return 0;    
}