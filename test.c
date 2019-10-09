#include "io_tools.h"
#include "proc_tools.h"
#include "test.h"

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


/* proc_tools tests */
int process_data_test_1(){
    int *arr = NULL;
    size_t len = 0;
    TEST(process_data(arr, len) == EXIT_FAILURE,
        printf("\e[31m SUCCESS \e[30m\n"),
        printf("\e[32m FAILURE \e[30m\n");
        deb_arr_output(arr, len));
}
