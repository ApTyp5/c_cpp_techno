#include "errcodes.h"
#include "my_vector.h"
#include "parallel_avg.h"

#include <cstdio>

const char *show_error(int rc);

void print_answer(const little_vector_t answer);

int user_input(little_vector_t *arr[], size_t *n);

int main() {
  size_t n = 0;
  little_vector_t answer;
  little_vector_t *vector_arr = NULL;

  int rc = user_input(&vector_arr, &n);
  if (!rc) rc = parallel_avg_vector(answer, vector_arr, n);

  printf("%s\n", show_error(rc));
  if (!rc) print_answer(answer);

  if (vector_arr != NULL) free(vector_arr);
  return rc;
}

int user_input(little_vector_t *arr[], size_t *n) {
  if (n == NULL || arr == NULL)
    return NULL_GIVEN;

  printf("Enter the number of vectors: ");
  if (scanf("%zu", n) != 1)
    return EXIT_FAILURE;

  if (*n == 0)
    return EXIT_ZERO_SIZ;

  *arr = (little_vector_t *) malloc(*n * sizeof(little_vector_t));
  if (*arr == NULL)
    return EXIT_ALLOC_ERR;

  printf("Enter 3-dimention vector coordinates in next %zu strings:\n", *n);
  for (size_t i = 0; i < *n; i++) {
    if (scanf("%f%f%f", (*arr)[i], (*arr)[i] + 1, (*arr)[i] + 2) != 3)
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

const char *show_error(int rc) {
  switch (rc) {
    case EXIT_FAILURE:
      return "В данном массиве слишком мало элементов "
             "для арифметической последовательности.";
      break;

    case EXIT_ZERO_SIZ:
      return "Неверный ввод. Ожидается неотриательная "
             "длина и целочисленные элементы массива.";
      break;

    case EXIT_ALLOC_ERR:return "Ошибка выделения памяти.";
      break;

    case EXIT_SUCCESS:return "Программа успешно завершилась.";
      break;

    case NULL_GIVEN:return "На вход функции поступил нулевой указатель.";
      break;

    default:return "Неизвестный код возврата!";
      break;
  }
}

void print_answer(const little_vector_t answer) {
  printf("Average vector: (%f, %f, %f)\n", answer[0], answer[1], answer[2]);
}