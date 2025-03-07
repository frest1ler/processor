#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include "read_commands.h"

static void search_new_line(Info_about_text* info);
static void count_number_lines(Info_about_text* info);
//static void check_empty_lines(int* line_element, Info_about_text* info);
void        calculate_array_size(Info_about_text *info, const char* fname);

void read_commands(Info_about_text* info)
{
    assert(info);

    const char* fname = "COMANDS.txt"; 

    FILE * point_to_file = fopen(fname, "rb");

    if (!point_to_file) 
    {
        printf("The file does not open\n");

        exit(EXIT_FAILURE);
    }

    calculate_array_size(info, fname);

    int number_successfully_read_chars = fread(info->text, 1, info->size_text, point_to_file);

    if (number_successfully_read_chars + 1 != info->size_text)
    {
        printf("ERROR: fread didn't read enough chars\n"
               "info->size_text = %d\n"
               "number_successfully_read_chars = %d\n",
               info->size_text, number_successfully_read_chars);

        exit(EXIT_FAILURE);
    }
    fclose(point_to_file);
    printf("%s\n", info->text);
    info->text[info->size_text - 1] = '\0';

    return;
}

void init_pointer_array(Info_about_text* info)
{
    assert(info);

    count_number_lines(info);

    search_new_line(info);
}

void calculate_array_size(Info_about_text *info, const char* fname)
{
    assert(info);
    assert(fname);

    struct stat data_for_file = {};

    stat(fname, &data_for_file);

    info->size_text = data_for_file.st_size + 1;

    if (!info->size_text)
    {
        printf("size_text = 0\n");

        exit(EXIT_FAILURE);
    }
    info->text = (char*)calloc(info->size_text, sizeof(char));

    if (info->text == NULL)
    {
        printf("ERROR: calculate_array_size; text = NULL\n");

        exit(EXIT_FAILURE);
    }
}

static void search_new_line(Info_about_text* info)
{
    if (!info)
    {
        printf("structure transfer error\n");

        exit(EXIT_FAILURE);
    }
    assert(info->text);

    info->ptr_line = (char**)calloc(info->max_number_line, sizeof(char*));

    char symbol         = 0;
    size_t line_element = 0;
    size_t number_line  = 1;

    info->ptr_line[0] = info->text;
    
    for(int i = 0; i < info->size_text - 1; i++)
    {

        if (info->text[i] == '\0')
        {
            info->ptr_line[number_line] = (info->text + i + 1);

            number_line++;
        }
    }
}

static void count_number_lines(Info_about_text* info)
{
    assert(info);

    info->max_number_line = 1;

    char symbol = 0;

    for(int line_element = 0; (symbol = info->text[line_element]) &&
        line_element < info->size_text; line_element++)
    {
        if (symbol == '\n')
        {
            //check_empty_lines(&line_element, info);
            info->max_number_line++;
            info->text[line_element] = '\0';
        }
    }
}

// static void check_empty_lines(int* line_element, Info_about_text* info)
// {
//     assert(info);
//     assert(line_element);
//     assert(info->text);
//     while(info->text[*line_element + 1] == '\n' || info->text[*line_element + 1] == '\r')
//     {
//         (*line_element)++;
//     }
// }

stack_elem_t* code_ctor(Info_about_text* info)
{
    size_t size = info->size_text;

    if (size == 0) {
        printf("ERROR: size text = 0.\n");
        exit(EXIT_FAILURE);
    }

    stack_elem_t* code = (stack_elem_t*)calloc(size, sizeof(stack_elem_t));
        if (code == NULL) {
            printf("ERROR: Failed to allocate memory for the array code.\n");
            exit(EXIT_FAILURE);
        }

    return code;
}

void code_dtor(stack_elem_t* code)
{
    if (code != NULL){
        free(code);
    }
    else{
        printf("CODE == NULL ptr\n");
    }
}