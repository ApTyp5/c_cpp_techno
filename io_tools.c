#include "io_tools.h"



int arr_input(int *arr[], size_t *len)
{
    if (len == NULL)
        if ( !(len = malloc(sizeof(size_t))) )
            return ALLOC_ERR;

	if (scanf("%zu", len) != 1) return INPUT_ERR;
	if ((*arr = malloc(*len * sizeof(int))) == NULL) return ALLOC_ERR;

	for (size_t i = 0; i < *len; i++)
	{
		if (scanf("%d", *arr + i) != 1) return INPUT_ERR;
	}

	return EXIT_SUCCESS;
}


int arr_output(const int *const arr, size_t len)
{
	if (arr == NULL && len != 0) return NULL_GIVEN;

	printf("%zu\n", len);
	for (size_t i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}


int user_input(int *arr[], size_t *len)
{
	printf("Введите длину вводимого массива натуральное число:");
	if (scanf("%zu", len) != 1) return INPUT_ERR;
	if (*len == 0) return EXIT_FAILURE;
	if ((*arr = malloc(*len * sizeof(int))) == NULL) return ALLOC_ERR;

	printf("Введите %zu элементов массива (целые числа):", *len);
	for (size_t i = 0; i < *len; i++)
	{
		if (scanf("%d", *arr + i) != 1) return INPUT_ERR;
	}

	return EXIT_SUCCESS;
}

int show_arr(const char *invit, const int *const arr, size_t len)
{
	if (arr == NULL) return NULL_GIVEN;

	printf("%s", invit);
	printf("[ ");
	for (size_t i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("]\n");

	return EXIT_SUCCESS;
}

