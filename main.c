#include "ret_codes.h"


int main()
{
	int *arr = NULL;
	int arr_len = 0;

	int rc = user_input(&arr, &arr_len);
	if (!rc) rc = process_data(arr, arr_len);
	if (rc) show_message(rc);
	
	return rc;
}
