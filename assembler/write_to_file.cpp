#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "write_to_file.h"

void write_byte_to_file      (stack_elem_t* code, size_t ip);
void free_up_memory_from_text(Info_about_text* info);
void copy_command_name       (int* i, char* comands, char* cmd);
void copy_argument_name      (int i, char* comands, char* arg);

int  encode_command          (char* cmd, size_t* ip, stack_elem_t* code, int argument, int n_reg);
int  check_arg               (char* arg);
int  check_mark_indicator    (char* arg, Info_about_text* info);
int  string_cmp              (char* str1, char* str2);

char get_last_el_string      (char* str); 

void perform_comands(char* comands, size_t* ip, stack_elem_t* code, Info_about_text* info)
{   
    int i        = 0;
    int argument = 0;
    int n_reg    = 0;

    char cmd[COMMAND_LENGTH]  = {};
    char arg[ARGUMENT_LENGTH] = {};

    copy_command_name(&i, comands, cmd);

    if (strcmp(cmd, "push") == 0 ||
        strcmp(cmd,  "pop") == 0 ||
        strcmp(cmd, "call") == 0 ||
        strcmp(cmd,  "jmp") == 0 ||
        strcmp(cmd,   "ja") == 0 ||
        strcmp(cmd,  "jae") == 0 ||
        strcmp(cmd,   "jb") == 0 ||
        strcmp(cmd,  "jbe") == 0 ||
        strcmp(cmd,   "je") == 0 ||
        strcmp(cmd,  "jne") == 0   )
    {  
        copy_argument_name(i, comands, arg);

        if (strcmp(cmd, "push") == 0 ||
            strcmp(cmd,  "pop") == 0   )
        { 
            if ((n_reg = check_arg(arg)) == 0){
                argument = atoi(arg);
            }
            else{
                argument = n_reg;
            }
        }
        else 
        {
            argument = check_mark_indicator(arg, info);
            printf("arg=%d\n", argument);
        }
    }
    printf("int argument = %d\n", argument);
    encode_command(cmd, ip, code, argument, n_reg);
}

int check_mark_indicator(char* arg, Info_about_text* info)
{
    char mark[ARGUMENT_LENGTH] = {};

    int  i  = 0;
    int  ip = 0;

    while(arg[i] != '\0')
    {
        mark[i] = arg[i];

        i++;
    }
    mark[i]     = ':' ;

    printf("mark= %s\n", mark);

    char last_el = 0;

    for(int number_line = 0; number_line < info->max_number_line; number_line++)
    {   
        printf("n1 = %s ; n2 = %s ; ip = %d\n", mark, info->ptr_line[number_line], ip);
        if (string_cmp(mark, info->ptr_line[number_line]) == 0)
        {   
            return ip;
        }
        else if (string_cmp(info->ptr_line[number_line], "push") == 0 ||
                 string_cmp(info->ptr_line[number_line],  "pop") == 0 ||
                 string_cmp(info->ptr_line[number_line], "call") == 0 ||
                 string_cmp(info->ptr_line[number_line],  "jmp") == 0 ||
                 string_cmp(info->ptr_line[number_line],   "ja") == 0 ||
                 string_cmp(info->ptr_line[number_line],  "jae") == 0 ||
                 string_cmp(info->ptr_line[number_line],   "jb") == 0 ||
                 string_cmp(info->ptr_line[number_line],  "jbe") == 0 ||
                 string_cmp(info->ptr_line[number_line],   "je") == 0 ||
                 string_cmp(info->ptr_line[number_line],  "jne") == 0   )
        {
            ip += 2;
        }
        else if ((last_el = get_last_el_string(info->ptr_line[number_line])) != ':'){
            ip += 1;
        }
    } 
    return 0;
}

void copy_command_name(int* i, char* comands, char* cmd)
{
    while(comands[*i] != ' ' && comands[*i] != '\0' &&
          comands[*i] != '\r' && *i < COMMAND_LENGTH  ){

        cmd[*i] = comands[*i];
        (*i)++;
    }
    (*i)++;
}
void copy_argument_name(int i, char* comands, char* arg)
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

int encode_command(char* cmd, size_t* ip, stack_elem_t* code, int argument, int n_reg)
{   
    char symbol = 0;

    if (strcmp(cmd, "push") == 0)
    {   
        if (n_reg == 0)
        {
            code[*ip] = PUSH;
            (*ip)++;

            code[*ip] = argument;
            (*ip)++;
        }
        else
        {
            code[*ip] = PUSH + 32;
            (*ip)++;

            code[*ip] = n_reg;
            (*ip)++;    
        }
    }   
    else if (strcmp(cmd, "pop") == 0)
    {
        if (n_reg == 0)
        {
            code[*ip] = POP;
            (*ip)++;
        }
        else
        {
            code[*ip] = POP + 32;
            (*ip)++;
            code[*ip] = n_reg;
            (*ip)++;
        }
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
    else if (strcmp(cmd, "input") == 0){
        code[*ip] = IN;
        (*ip)++;
    }
    else if (strcmp(cmd, "jmp") == 0)
    {
        code[*ip] = JMP;
        (*ip)++;
        printf("jmp_arg = %d", argument);
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
    else if (strcmp(cmd, "call") == 0)
    {
        code[*ip] = CALL;
        (*ip)++;

        code[*ip] = argument;
        (*ip)++;
    }
    else if (strcmp(cmd, "ret") == 0){
        code[*ip] = RET;
        (*ip)++;
    }
    else if (strcmp(cmd, "hlt") == 0){
        code[*ip] = HLT;
        (*ip)++;
    }
    else if ((symbol = get_last_el_string(cmd)) != ':')
    {
        printf("last_el=%c\n", symbol);
        printf("%s : there is no such command\n", cmd);

        return 1;
    }
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
        printf("\n%dcom = %s\n", number_comand, info->ptr_line[number_comand]);
        perform_comands(info->ptr_line[number_comand], &ip, code, info);
    }

    free_up_memory_from_text(info);

    write_byte_to_file(code, ip);
}

void write_byte_to_file(stack_elem_t* code, size_t ip)
{
    const char* fname = "CODE_AS.txt";

    FILE * point_to_file = fopen(fname, "ab");

    if (!point_to_file){
        printf("The file does not open\n");
        exit(EXIT_FAILURE);
    }

    printf("ip=%lu\n", ip);

    for(int k = 0; k < 3; k++)
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
    if (info->text != NULL){
        free(info->text);
    }
    else{
        printf("NULL ptr_text\n");
    }

    if (info->ptr_line != NULL){
        free(info->ptr_line);  
    }
    else{
        printf("NULL ptr_line\n");
    }
}

int check_arg(char* arg)
{
    if (strcmp(arg, "Ax") == 0){
        return 1;
    }
    if (strcmp(arg, "Bx") == 0){
        return 2;
    }
    if (strcmp(arg, "Cx") == 0){
        return 3;
    }
    if (strcmp(arg, "Dx") == 0){
        return 4;
    }
    if (strcmp(arg, "Ex") == 0){
        return 5;
    }
    return 0;
}

int string_cmp(char* str1, char* str2)
{
    int i = 0;

    while(str1[i] != '\n' && str1[i] != '\0' && str1[i] != ' ' && str1[i] != '\r' &&
          str2[i] != '\n' && str2[i] != '\0' && str2[i] != ' ' && str2[i] != '\r'   )
    {   
        if (str1[i] != str2[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

char get_last_el_string(char* str) 
{
    if (str == NULL || str[0] == '\0'){
        return '\0'; 
    }
    
    int length = 0;
    while (str[length] != '\0' && str[length] != '\n' && str[length] != '\r') {
        length++;
    }
    printf("last=[%c]\n", str[length - 1]);
    return str[length - 1];
}