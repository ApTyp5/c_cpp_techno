#pragma once

#include "ret_codes.h"

#include <stdio.h>
#include <stdlib.h>



int arr_input(int *arr[], size_t *len);

int arr_output(int arr[], size_t len);

int user_input(int *arr[], size_t *len);

int show_arr(const char *invit, int *arr, size_t len);


