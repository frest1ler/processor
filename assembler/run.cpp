#include <stdio.h>
//#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "run.h"
#include "read_from_file_comands.h"
#include "write_comands_to_file.h"

void run_code(Info_about_text* info, stack_elem_t* code);
//void code_destroy(stack_elem_t* code);
//stack_elem_t* code_ctor();
void write_byte_to_file(stack_elem_t* code, size_t ip);
void free_up_memory_from_text(Info_about_text* info);

void run()
{
    Info_about_text info = {};

    read_from_file_comands(&info);

    initialize_pointer_array(&info);

    stack_elem_t code[10] = {};

    run_code(&info, code);

    //code_destroy(code);
}

void run_code(Info_about_text* info, stack_elem_t* code)
{
    size_t ip = 0;

    for(int number_comand = 0; number_comand < info->max_number_line - 1; number_comand++)
    {
        perform_comands(info->ptr_line[number_comand], &ip, code);
    }

    free_up_memory_from_text(info);

    write_byte_to_file(code, ip);
}

// void code_destroy(stack_elem_t* code)
// {
//     if (code != NULL)
//     {
//         free(code);
//     }
// }

// stack_elem_t* code_ctor()
// {
//     printf("Hello\n");
//     stack_elem_t* code = (stack_elem_t*)calloc(10, sizeof(stack_elem_t));
//     printf("%p\n", code);
//     return code;
// }

void write_byte_to_file(stack_elem_t* code, size_t ip)
{
    const char* fname = "CODE_AS.txt";

    FILE * point_to_file = fopen(fname, "ab");

    if (!point_to_file)
    {
        printf("The file does not open\n");

        exit(EXIT_FAILURE);
    }

    printf("ip=%ld\n", ip);

    for(int k = 0; k < 10; k++)
    {
        printf("%d", code[k]);
    }
    
    size_t elements_written = fwrite(code, sizeof(stack_elem_t), ip, point_to_file);

    if (elements_written != ip)
    {
        printf("Error writing to the file.\n");

        fclose(point_to_file);

        exit(EXIT_FAILURE);
    }

    fclose(point_to_file);
}

void free_up_memory_from_text(Info_about_text* info)
{
    if (info->text != NULL)
    {
        free(info->text);
    }
    else
    {
        printf("NULL ptr_text\n");
    }

    if (info->ptr_line != NULL)
    {
        free(info->ptr_line);  
    }
    else
    {
        printf("NULL ptr_line\n");
    }
}