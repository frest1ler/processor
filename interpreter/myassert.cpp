#include <stdio.h>
#include <assert.h>
#include "myassert.h"
#include "working_with_data.h"
#include "stack_functions.h"
#include "dump.h"

const char* const RED = "\033[1;31m";

int  collect_error(Stack_t * stack);
void display_error(Stack_t * stack, int error, const char* file, int line);

void verify(Stack_t * stack, const char* file, int line) //TODO add macro preti function
{
    #ifdef PROTECTION_ON
        int error = collect_error(stack);

        if (!error)
        {
            return;
        }

        display_error(stack, error, file, line);

        stack_destroy(stack);
    #endif /*PROTECTION_ON*/

    return;
}
int collect_error(Stack_t * stack)
{
    int error = 0;
    #ifdef PROTECTION_ON
        assert(stack);

        #define CHECK_ERROR_(error_value, error_condition) \
        do                                                 \
        {                                                  \
            if (error_condition)                           \
            {                                              \
                error += error_value;                      \
            }                                              \
        } while(0)

        CHECK_ERROR_(INCORRECT_VALUE_LEFT_CANARY_STRUCT , stack->left_canary_protection != CANARY_PROTECTION_1   );
        CHECK_ERROR_(NULL_POINTER_DATA                  , stack->data == NULL                                    );
        CHECK_ERROR_(NEGATIVE_CAPACITY                  , stack->capacity <= 0                                   );
        CHECK_ERROR_(INCORRECT_VALUE_RIGHT_CANARY_STRUCT, stack->right_canary_protection != CANARY_PROTECTION_2  );
        CHECK_ERROR_(NEGATIVE_SIZE                      , stack->size < 0                                        );
        CHECK_ERROR_(INCORRECT_VALUE_LEFT_CANARY_ARRAY  , *(stack->data - 1) != CANARY_PROTECTION_3              );
        CHECK_ERROR_(INCORRECT_VALUE_RIGHT_CANARY_ARRAY , *(stack->data + stack->capacity) != CANARY_PROTECTION_4);

        stack->hash_sum = hash(stack->data, stack->size);

        CHECK_ERROR_(HASH_AMOUNT_MISMATCH               , stack->hash_sum != stack->etalon_hash_sum              );

        #undef CHECK_ERROR_
    #endif /*PROTECTION_ON*/

    return error;
}

void display_error(Stack_t * stack, int error, const char* file, int line)
{
    #ifdef PROTECTION_ON
        assert(error);

        printf("file: %s; line: %d\n", file, line);

        #define OUTPUT_ERROR_(error_value, output_error) \
        do                                               \
        {                                                \
            if (error & error_value)                     \
            {                                            \
                printf(output_error, RED);               \
            }                                            \
        } while(0)

        OUTPUT_ERROR_(INCORRECT_VALUE_LEFT_CANARY_STRUCT , "%sleft_canary_protection != CANARY_PROTECTION_1\n%s" );
        OUTPUT_ERROR_(NULL_POINTER_DATA                  , "%sstack->data == NULL\n%s"                           );
        OUTPUT_ERROR_(NEGATIVE_CAPACITY                  , "%sstack->capacity <= 0\n%s"                          );
        OUTPUT_ERROR_(INCORRECT_VALUE_RIGHT_CANARY_STRUCT, "%sright_canary_protection != CANARY_PROTECTION_2\n%s");
        OUTPUT_ERROR_(NEGATIVE_SIZE                      , "%sstack->size < 0\n%s"                               );
        OUTPUT_ERROR_(INCORRECT_VALUE_LEFT_CANARY_ARRAY  , "%s *(stack->data - 1) != CANARY_PROTECTION_3\n%s"    );
        OUTPUT_ERROR_(INCORRECT_VALUE_RIGHT_CANARY_ARRAY , "%sdata[capacity + 1] != CANARY_PROTECTION_4\n* %s"   );
        OUTPUT_ERROR_(HASH_AMOUNT_MISMATCH               , "%sstack->hash_sum != stack->expected_hash_sum\n%s"   );

        for(int i = 1; stack->size + i < stack->capacity; i++)
        {
            if (stack->data[stack->size + i] != POISON)
            {
                printf("file: %s; line: %d\n"
                       "stack->data[%d] != POISON\n"
                       "stack->data[%d] = " STACK_SPECIFIER"\n",
                       file, line, stack->size + i, stack->size + i, stack->data[stack->size + i]);
            }
        }

        dump(stack);

        #undef OUTPUT_ERROR_
    #endif /*PROTECTION_ON*/
}


