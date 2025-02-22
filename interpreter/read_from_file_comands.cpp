#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include "read_from_file_comands.h"

static void search_new_line(Info_about_text* info);
static void count_number_lines(Info_about_text* info);
static void check_empty_lines(int* line_element, Info_about_text* info);
void        calculate_array_size(Info_about_text *info, char* fname);

void read_from_file_comands(Info_about_text* info)
{
    assert(info);

    char* fname = "CODE_AS.txt";

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
        printf("ERROR: fread didn't read enough chars\n",
               "info->size_text = %d\n",
               "number_successfully_read_chars = %d\n",
               info->size_text, number_successfully_read_chars);

        exit(EXIT_FAILURE);
    }
    fclose(point_to_file);

    info->text[info->size_text - 1] = '\0';

    printf("\nnumber_successfully_read_chars=%d\n", number_successfully_read_chars);
    for(int i = 0; i < number_successfully_read_chars; i++)
    {
        printf("%d ", info->text[i]);
    }

    return;
}

void locate_and_save_newlines(Info_about_text* info)
{
    assert(info);

    count_number_lines(info);

    search_new_line(info);
}

void calculate_array_size(Info_about_text *info, char* fname)
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
    if (!info){
        printf("structure transfer error\n");
        exit(EXIT_FAILURE);
    }

    assert(info->text);

    if (info->max_number_line > 0){
        info->ptr_line = (char**)calloc(info->max_number_line, sizeof(char*));\
    }
    else{
        printf("info->max_number_line = %d", info->max_number_line);
        exit(EXIT_FAILURE);
    }
    
    if (info->ptr_line == NULL){
        printf("info->ptr_line == NULL\n");
        exit(EXIT_FAILURE);
    }

    char symbol         = 0;
    size_t line_element = 0;
    size_t number_line  = 1;

    info->ptr_line[0] = info->text;

    while((symbol = info->text[line_element]) != EOF)
    {
        line_element++;

        if (symbol == '\0')
        {
            info->ptr_line[number_line] = (char*)(info->text + line_element);

            line_element++;
            number_line++;

        }
    }
}

static void count_number_lines(Info_about_text* info)
{
    assert(info);

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

static void check_empty_lines(int* line_element, Info_about_text* info)
{
    assert(info);
    assert(line_element);
    assert(info->text);

    while(info->text[*line_element + 1] == '\n')
    {
        *line_element++;
    }
}
