#include "proc_tools.h"
#include "io_tools.h"

int process_data(const int *const arr, size_t len)
{
    const int *output_seq = NULL;
    size_t seq_len = 0;

	if ((seq_len = longest_arithm_seq(&output_seq, arr, len)) == 0)
	{
		return NO_ARITHM_SEQ;
	}

	show_arr("Aрифметическая последовательнoсть"
			 " с наибольшей длиной:\n", output_seq, seq_len);

	return HAPPY_END;
}


void try_inc_seq(size_t *max_seq_len, const int **arr, size_t seq_len, 
        const int *const init_arr, size_t active)
{
	if (seq_len > *max_seq_len)
	{
		*max_seq_len = seq_len;
		*arr = init_arr + active - seq_len + 1 ;
	}
}

size_t longest_arithm_seq(const int **output_seq, 
        const int *const init_arr, size_t len)
{
	if (output_seq == NULL || init_arr == NULL || len < 2)
	{
		return 0;
	}

	size_t seq_len = 2;
	const int *seq_ptr = init_arr;
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
			try_inc_seq(&max_seq_len, &seq_ptr, seq_len, init_arr, first);
			delta = cur_delta;
			seq_len = 2;
		}
	}

	try_inc_seq(&max_seq_len, &seq_ptr, seq_len, init_arr, len - 1);
    *output_seq = seq_ptr;

	return max_seq_len;
}
