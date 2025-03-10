#ifndef STACK_H
#define STACK_H

#define PROTECTION_ON
#define GIVEN_PART(x) ((x)-50)/2

typedef int stack_elem_t;

#ifdef PROTECTION_ON
    #define CANARY_SPECIFIER "%d"
#endif /*PROTECTION_ON*/

#define STACK_SPECIFIER  "%d"

#ifdef PROTECTION_ON
    struct Stack_t
    {
        int           left_canary_protection ;
        stack_elem_t* data                   ;
        int           size                   ;
        int           capacity               ;
        unsigned long hash_sum               ;
        unsigned long etalon_hash_sum        ;
        int           right_canary_protection;
    };
#else
    struct Stack_t
    {
        stack_elem_t* data                   ;
        int           size                   ;
        int           capacity               ;
    };
#endif /*PROTECTION_ON*/

#ifdef PROTECTION_ON
    const stack_elem_t  CANARY_PROTECTION_1  =  666 ;
    const stack_elem_t  CANARY_PROTECTION_2  = -666 ;
    const stack_elem_t  CANARY_PROTECTION_3  =  999 ;
    const stack_elem_t  CANARY_PROTECTION_4  = -999 ;
    const stack_elem_t  POISON               = -333 ;
    const unsigned long INITIAL_HASH_SUM     =  5381;
    const int           INITIAL_CAPACITY     =  10  ; //TODO size_t
    const int           INITIAL_SIZE         =  0   ;
    const int           NUM_CANARY_ARRAY     =  2   ;
    const int           CAPACITY_GROWTH_RATE =  2   ;
#else
    const int           INITIAL_CAPACITY     =  10  ;
    const int           INITIAL_SIZE         =  0   ;
    const int           NUM_CANARY_ARRAY     =  2   ;
    const int           CAPACITY_GROWTH_RATE =  2   ;
#endif /*PROTECTION_ON*/

#endif /*STACK_H*/
