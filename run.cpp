#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "run.h"
#include "stack_functions.h"
#include "functions_provided_by_processor.h"
#include "read_from_file_comands.h"

void run_code(Info_about_text* info, Stack_t* stack);
void perform_comands(Stack_t* stack, char* comands);

void run(Stack_t* stack)
{
    Info_about_text info = {};

    read_from_file_comands(&info);

    initialize_pointer_array(&info);

    run_code(&info, stack);

}

void run_code(Info_about_text* info, Stack_t* stack)
{
    printf("ncom = %d\n", info->max_number_line);

    for(int number_comand = 0; number_comand < info->max_number_line; number_comand++)
    {
        perform_comands(stack, info->ptr_line[number_comand]);
    }

}

void perform_comands(Stack_t* stack, char* comands)
{
    stack_elem_t argument = 0;
    int i   = 0;
    int num = 0;
    char cmd[50] = {};
    char arg[50] = {};

    while(comands[i] != ' ' && comands[i] != '\0' && i < 50)
    {
        cmd[i - num] = comands[i];
        i++;
    }
    cmd[i] = '\0';

    i++;
    num = i;

    if (strcmp(cmd, "push") == 0)
    {
        while(comands[i] != ' ' && comands[i] != '\0' && i < 50)
        {
            arg[i - num] = comands[i];
            i++;
        }
        arg[i] = '\0';
        argument = atoi(arg);
    }

    printf("\n%s\n", cmd);

    if (strcmp(cmd, "push") == 0)
    {
        stack_push(stack, argument);
    }
    else if (strcmp(cmd, "pop") == 0)
    {
        stack_pop(stack);
    }
    else if (strcmp(cmd, "add") == 0)
    {
        add(stack);
    }
    else if (strcmp(cmd, "sub") == 0)
    {
        sub(stack);
    }
    else if (strcmp(cmd, "mul") == 0)
    {
        mul(stack);
    }
    else if (strcmp(cmd, "div") == 0)
    {
        div(stack);
    }
    else if (strcmp(cmd, "out") == 0)
    {
        out(stack);
    }
    else if (strcmp(cmd, "sqrt_c") == 0)
    {
        sqrt_c(stack);
    }
    else if (strcmp(cmd, "sin_c") == 0)
    {
        sin_c(stack);
    }
    else if (strcmp(cmd, "cos_c") == 0)
    {
        cos_c(stack);
    }
    else if (strcmp(cmd, "hlt") == 0)
    {
        hlt(stack);
    }
    else
    {
        printf("%s", cmd);
        printf("%s : there is no such command\n", cmd);

        hlt(stack);
    }
}
