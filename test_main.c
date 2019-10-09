#include "proc_tools.h"
#include "io_tools.h"

int main()
{
	int *arr = NULL;
	size_t arr_len = 0;

    const int *seq = NULL;
    size_t seq_len = 0;

	arr_input(&arr, &arr_len);

	seq_len = longest_arithm_seq(&seq, arr, arr_len);
	arr_output(seq, seq_len);
	free(arr);
	
	return 0;
}
