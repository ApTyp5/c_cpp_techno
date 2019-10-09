#pragma once

#include "ret_codes.h"

#include <stddef.h>

/* Находит в массиве arr наибольшую арифметическую 
 * последовательность и выводит её на экран */
int process_data(const int *const arr, size_t len);

size_t longest_arithm_seq(const int **output_seq, 
        const int *const arr, size_t len);
