#include "proc_tools.h"

int process_data(int arr[], size_t len)
{
	if ((len = longest_arithm_seq(&arr, len)) == 0)
	{
		return NO_ARITHM_SEQ;
	}

	show_arr("Самая длинная арифметическая последовательнoсть: ", 
			arr, len);

	return HAPPY_END;
}


void try_inc_seq(size_t &max_seq_len, int (*arr)[], 
		size_t seq_len, int *init_arr, size_t active)
{
	if (seq_len > *max_seq_len)
	{
		*max_seq_len = seq_len;
		*arr = init_arr + active - seq_len ;
	}
}

int longest_arithm_seq(int (*arr)[], size_t len)
{
	if (arr == NULL || *arr == NULL 
		|| len == 0 || len  == 1)
	{
		return 0;
	}

	if (len == 2) 
	{
		return 2;
	}

	size_t seq_len = 1;
	int *init_arr = *arr;
	size_t max_seq_len = 0;
	int delta = init_arr[1] - init_arr[0];

	for (size_t first = 1; first < len - 1; first++)
	{
		size_t second = first + 1;
		int cur_delta = init_arr[second] - init_arr[first];

		if (cur_delta == delta)
		{
			++seq_len;
		}
		else
		{
			try_inc_seq(&max_seq_len, arr, seq_len, init_arr, first);
			delta = cur_delta;
			seq_len = 1;
		}
	}

	try_inc_seq(&max_seq_len, arr, seq_len, init_arr, len - 1);

	return max_seq_len;
}
