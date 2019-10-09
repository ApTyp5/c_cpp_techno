#pragma once
#include "colors.h"

#define TEST(exp, suc, fail)    \
    do              \
{                   \
    if (a){         \
        (suc)       \
    }               \
    else{           \
        (fail)      \
    }               \
}                   \
while(0)            \


#define ARRAY_TEST(exp, arr, len)                           \
    TEST(exp,                                               \
    printf(ANSI_COLOR_GREEN "SUCCESS\n" ANSI_COLOR_RESET),  \
    do{                                                     \
        printf(ANSI_COLOR_RED "FAIL\n" ANSI_COLOR_RESET),   \
        arr_output((arr),(len));                            \
    }while(0)                                               \

