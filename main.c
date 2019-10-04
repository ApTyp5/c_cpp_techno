#include "ret_codes.h"
#include "process_tools.h"
#include "io_tools.h"



void show_message(int rc);

int main()
{
	int *arr = NULL;
	int arr_len = 0;

	int rc = user_input(&arr, &arr_len);
	if (!rc) rc = process_data(arr, arr_len);
	if (rc) show_message(rc);
	
	return rc;
}

void show_message(int rc)
{
	switch (rc)
	{
		case NO_ARITHM_SEQ:
			printf("В данном массиве слишком мало элементов
					для арифметической последовательности.\n");
			break;
		case INPUT_ERR:
			printf("Неверный ввод. Ожидается неотриательная
					длина и целочисленные элеенты массива.\n");
			break;
		case ALLOC_ERR:
			printf("Ошибка выделения памяти.\n");
			break;
		case HAPPY_END:
			printf("Программа успешно завершилась.\n");
	}
}

