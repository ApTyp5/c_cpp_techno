#include "io_tools.h"
#include "proc_tools.h"
#include "ret_codes.h"

const char *show_message(int rc);

int main()
{
	int *arr = NULL;
	size_t arr_len = 0;

	int rc = user_input(&arr, &arr_len);
	if (!rc) rc = process_data(arr, arr_len);
	printf("\n%s\n", show_message(rc));
	if (arr) { free(arr); arr = NULL; }
	
	return rc;
}

const char *show_message(const int rc)
{
	switch (rc)
	{
		case NO_ARITHM_SEQ:
			return "В данном массиве слишком мало элементов "
					"для арифметической последовательности.";
			break;

		case INPUT_ERR:
			return"Неверный ввод. Ожидается неотриательная "
					"длина и целочисленные элементы массива.";
			break;

		case ALLOC_ERR:
			return "Ошибка выделения памяти.";
			break;

		case HAPPY_END:
			return "Программа успешно завершилась.";
            break;

		case NULL_GIVEN:
			return "На вход функции поступил нулевой указатель.";
            break;

        default:
            return "Неизвестный код возврата!";
            break;
	}
}

