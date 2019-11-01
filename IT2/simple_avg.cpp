#include "simple_avg.h"

int simple_avg_vector(little_vector_t avg_vector,
                      const little_vector_t *vectors, size_t size) {
  if (unlikely((avg_vector == NULL)
                   || vectors == NULL))
    return EXIT_NULL_REC;

  if (unlikely(size == 0)) return EXIT_ZERO_SIZ;

  my_vector_bt sum[vec_size] = {0};

  for (size_t i = 0; i < size; i++)
    for (size_t j = 0; j < vec_size; j++)
      sum[j] += vectors[i][j];

  for (size_t j = 0; j < vec_size; j++) {
    sum[j] /= size;
    avg_vector[j] = (my_vector_lt) sum[j];
  }

  return EXIT_SUCCESS;
}
