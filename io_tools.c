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


int user_input(int *arr[], size_t *len)
{
	printf("Введите длину вводимого массива натуральное число:");
	if (scanf("%zu", len) != 1) return INPUT_ERR;
	if (*len == 0) return NO_ARITHM_SEQ;
	if ((*arr = malloc(*len * sizeof(int))) == NULL) return ALLOC_ERR;

	printf("Введите %zu элементов массива (целые числа):", *len);
	for (size_t i = 0; i < *len; i++)
	{
		if (scanf("%d", *arr + i) != 1) return INPUT_ERR;
	}

	return HAPPY_END;
}

int show_arr(const char *invit, int *arr, size_t len)
{
	if (arr == NULL) return NULL_GIVEN;

	printf("%s", invit);
	printf("[ ");
	for (size_t i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("]\n");

	return HAPPY_END;
}

