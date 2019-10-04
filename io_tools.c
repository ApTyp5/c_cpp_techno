#include "io_tools.h"



int arr_input(int *arr[], size_t *len)
{
	if (scanf("%zu", len) != 1) return INPUT_ERR;
	if ((*arr = malloc(*len * sizeof(int))) == NULL) return ALLOC_ERR;

	for (size_t i = 0; i < *len; i++)
	{
		if (scanf("%d", *arr + i) != 1) return INPUT_ERR;
	}

	return HAPPY_END;
}


int arr_output(int arr[], size_t len)
{
	if (arr == NULL) return NULL_GIVEN;

	printf("%zu\n", len);
	for (size_t i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return HAPPY_END;
}

