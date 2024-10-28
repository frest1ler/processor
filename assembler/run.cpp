#include <stdio.h>
//#include <assert.h>
#include <stdlib.h>
#include "run.h"
#include "read_from_file_comands.h"
#include "write_comands_to_file.h"

void run_code(Info_about_text* info, stack_elem_t* code);
void code_destroy(stack_elem_t* code);
stack_elem_t* code_ctor();

void run()
{
    Info_about_text info = {};

    read_from_file_comands(&info);

    initialize_pointer_array(&info);

    stack_elem_t code[10] = {};

    run_code(&info, code);

    code_destroy(code);
}

void run_code(Info_about_text* info, stack_elem_t* code)
{

    printf("ncom = %d\n", info->max_number_line);

    int ip = 0;

    for(int number_comand = 0; number_comand < info->max_number_line; number_comand++)
    {
        perform_comands(info->ptr_line[number_comand], &ip, code);
    }
    for(int k = 0; k < 10; k++)
    {
        printf("%d", code[k]);
    }

    char* fname = "CODE.txt";

    FILE * point_to_file = fopen(fname, "rb");

    if (!point_to_file)
    {
        printf("The file does not open\n");

        exit(EXIT_FAILURE);
    }

    fwrite(code, ip, sizeof(stack_elem_t), point_to_file);

    fclose(point_to_file);
}

void code_destroy(stack_elem_t* code)
{
    if (code != NULL)
    {
        free(code);
    }
}

// stack_elem_t* code_ctor()
// {
//     printf("Hello\n");
//     stack_elem_t* code = (stack_elem_t*)calloc(10, sizeof(stack_elem_t));
//     printf("%p\n", code);
//     return code;
// }
