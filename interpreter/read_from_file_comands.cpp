#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include "read_from_file_comands.h"

void calculate_array_size(Info_about_text *info, char* fname);

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

    int number_successfully_read_chars = fread(info->text, sizeof(int), info->size_text, point_to_file);
    printf("\nnumber_successfully_read_chars=%d\n", number_successfully_read_chars);
    if (number_successfully_read_chars != info->size_text)
    {
        printf("ERROR: fread didn't read enough elements\n",
               "info->size_text = %d\n",
               "number_successfully_read_chars = %d\n",
               info->size_text, number_successfully_read_chars);

        exit(EXIT_FAILURE);
    }
    fclose(point_to_file);

    printf("\nnumber_successfully_read_chars=%d\n", number_successfully_read_chars);
    for(int i = 0; i < number_successfully_read_chars; i++)
    {
        printf("%d ", info->text[i]);
    }

    return;
}

void calculate_array_size(Info_about_text *info, char* fname)
{
    assert(info);
    assert(fname);

    struct stat data_for_file = {};

    stat(fname, &data_for_file);

    info->size_text = data_for_file.st_size / sizeof(int);

    if (!info->size_text)
    {
        printf("size_text = 0\n");

        exit(EXIT_FAILURE);
    }
    info->text = (int*)calloc(info->size_text, sizeof(int));

    if (info->text == NULL)
    {
        printf("ERROR: calculate_array_size; text = NULL\n");

        exit(EXIT_FAILURE);
    }
}


