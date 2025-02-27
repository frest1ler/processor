#include <string.h>
#include <stdlib.h>
#include "write_to_file.h"

void write_byte_to_file(stack_elem_t* code, size_t ip);
void free_up_memory_from_text(Info_about_text* info);
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

    if (strcmp(cmd, "push") == 0 || 
        strcmp(cmd,  "jmp") == 0 ||
        strcmp(cmd,   "ja") == 0 ||
        strcmp(cmd,  "jae") == 0 ||
        strcmp(cmd,   "jb") == 0 ||
        strcmp(cmd,  "jbe") == 0 ||
        strcmp(cmd,   "je") == 0 ||
        strcmp(cmd,  "jne") == 0   )
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
    if (strcmp(cmd, "push") == 0)//TODO codegen
    {
        code[*ip] = PUSH;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "pop") == 0){
        code[*ip] = POP;
        (*ip)++;
    }
    else if (strcmp(cmd, "add") == 0){
        code[*ip] = ADD;
        (*ip)++;
    }
    else if (strcmp(cmd, "sub") == 0){
        code[*ip] = SUB;
        (*ip)++;
    }
    else if (strcmp(cmd, "mul") == 0){
        code[*ip] = MUL;
        (*ip)++;
    }
    else if (strcmp(cmd, "div") == 0){
        code[*ip] = DIV;
        (*ip)++;
    }
    else if (strcmp(cmd, "out") == 0){
        code[*ip] = OUT;
        (*ip)++;
    }
    else if (strcmp(cmd, "sqrt_c") == 0){
        code[*ip] = SQRT_C;
        (*ip)++;
    }
    else if (strcmp(cmd, "sin_c") == 0){
        code[*ip] = SIN_C;
        (*ip)++;
    }
    else if (strcmp(cmd, "cos_c") == 0){
        code[*ip] = COS_C;
        (*ip)++;
    }
    else if (strcmp(cmd, "jmp") == 0)
    {
        code[*ip] = JMP;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "ja") == 0)
    {
        code[*ip] = JA;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "jae") == 0)
    {
        code[*ip] = JAE;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "jb") == 0)
    {
        code[*ip] = JB;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "jbe") == 0)
    {
        code[*ip] = JBE;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "je") == 0)
    {
        code[*ip] = JE;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "jne") == 0)
    {
        code[*ip] = JNE;
        (*ip)++;

        code[*ip] = argument;
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

void encode_to_asm(Info_about_text* info, stack_elem_t* code)
{
    if (info == NULL) {
        printf("ERROR: info = NULL.\n");
        exit(EXIT_FAILURE);
    }

    size_t ip = 0;

    for(int number_comand = 0; number_comand < info->max_number_line - 1; number_comand++)
    {
        perform_comands(info->ptr_line[number_comand], &ip, code);
    }

    free_up_memory_from_text(info);

    write_byte_to_file(code, ip);
}

void write_byte_to_file(stack_elem_t* code, size_t ip)
{
    const char* fname = "CODE_AS.txt";

    FILE * point_to_file = fopen(fname, "ab");

    if (!point_to_file)
    {
        printf("The file does not open\n");
        exit(EXIT_FAILURE);
    }

    printf("ip=%lu\n", ip);

    for(int k = 0; k < 10; k++)
    {
        printf("%d ", code[k]);
    }
    printf("\n");

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