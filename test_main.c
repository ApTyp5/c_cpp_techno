#include "proc_tools.h"
#include "io_tools.h"

int main()
{
	int *arr = NULL;
	size_t arr_len = 0;

	arr_input(&arr, &arr_len);
	arr_len = longest_arithm_seq(&arr, arr_len);
	arr_output(arr, arr_len);
	
	return 0;
}
