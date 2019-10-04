#pragma once

#include "ret_codes.h"

#include <stddef.h>

int process_data(int arr[], size_t len);

void try_inc_seq(size_t *max_seq_len, int *arr[], 
		size_t seq_len, int *init_arr, size_t active);

int longest_arithm_seq(int *arr[], size_t len);
