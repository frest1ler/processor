#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "write_comands_to_file.h"

void perform_comands(char* comands, size_t* ip, stack_elem_t* code)
{
    int argument = 0;
    int i        = 0;
    // int size_commands = next_comands - comands;
    // printf("size_com=%d", size_commands);
    //int *array;

    //array = (int*)calloc(size_commands, sizeof(int));
    //char* a = (char*)calloc(size_commands, sizeof(char));
    char cmd[50] = {};
    char arg[50] = {};

    while(comands[i] != ' ' && comands[i] != '\0' && comands[i] != '\r' && i < 49)
    {
        cmd[i] = comands[i];
        i++;
    }

    i++;
    int num = i;

    if (strcmp(cmd, "push") == 0)
    {
        while(comands[i] != ' ' && comands[i] != '\0' && comands[i] != '\r' && i < 49)
        {
            arg[i - num] = comands[i];
            i++;
        }
        arg[i] = '\0';
        argument = atoi(arg);
    }

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

        //hlt(stack);
    }
    printf("%s", cmd);
}
