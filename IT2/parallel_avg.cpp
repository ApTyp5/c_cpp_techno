#include "parallel_avg.h"

typedef struct summerArgs summerArgs;
struct summerArgs {
  const little_vector_t *vectors;
  size_t size;
  little_vector_t ans;
};

// Cумматор
void *summer(void *sumArgs) {
  auto *summerArgs_ptr = (summerArgs *) sumArgs;
  const little_vector_t *vectors = summerArgs_ptr->vectors;
  size_t size = summerArgs_ptr->size;

  simple_avg_vector(summerArgs_ptr->ans, vectors, size);

  pthread_exit(nullptr);
}

// Реализацию всегда можно будет заменить на более сложную,
// находящую реальное кол-во ядер системы
size_t find_core_num() {
  /*
  size_t core_num = system("cat /proc/cpuinfo | grep processor | wc -l");
  */
  size_t core_num = 4;
  assert(core_num < MAX_CORES);

  return core_num;
}

void start_all_threads(summerArgs args[], pthread_t threads[],
                       const little_vector_t *vectors, size_t core_num,
                       size_t el_per_core, size_t size);

void wait_all_threads(pthread_t threads[], size_t core_num);

inline void count_answer(little_vector_t avg_vector, summerArgs args[], size_t core_num);

extern "C" {
int parallel_avg_vector(little_vector_t avg_vector,
                        const little_vector_t *const vectors, size_t size) {
  if (unlikely((avg_vector == nullptr)
                   || vectors == nullptr))
    return EXIT_NULL_REC;

  if (unlikely(size == 0)) return EXIT_ZERO_SIZ;

  // Считаем клоличество логических ядер процессра
  size_t core_num = find_core_num();
  if (core_num <= 0) {
    return EXIT_FAILURE;
  }


  // Почему бы и не воспользоваться массивами переменной длины,
  // количество ядер мало когда будет меньше ста
  pthread_t threads[core_num];
  summerArgs args[core_num];
  size_t el_per_core = size / core_num;

  start_all_threads(args, threads, vectors, core_num, el_per_core, size);
  wait_all_threads(threads, core_num);
  if (unlikely(el_per_core == 0)) {
    // Если У нас мало элементов, то ответ находится в последнем потоке
    for (size_t i = 0; i < vec_size; i++){
      avg_vector[i] = args[core_num - 1].ans[i];
    }
  } else {
    count_answer(avg_vector, args, core_num);
  }

  return EXIT_SUCCESS;
}
}

inline void start_all_threads(summerArgs args[], pthread_t threads[],
                              const little_vector_t *vectors, size_t core_num,
                              size_t el_per_core, size_t size) {

  for (size_t i = 0; i < core_num - 1; i++) {
    args[i] = {vectors + i * el_per_core, el_per_core};
    pthread_create(threads + i, nullptr, summer, args + i);
  }

  // Последний поток должен обработать оставшиеся элементы
  size_t last_i = core_num - 1;
  size_t elements_processed = el_per_core * last_i;
  args[last_i] = {vectors + elements_processed, size - elements_processed};
  pthread_create(threads + last_i, nullptr, summer, args + last_i);
}

inline void wait_all_threads(pthread_t threads[], size_t core_num) {
  for (size_t i = 0; i < core_num; i++) {
    pthread_join(threads[i], nullptr);
  }
}

inline void count_answer(little_vector_t avg_vector, summerArgs args[], size_t core_num) {
  little_vector_t vectors[core_num];

  // Копируем получившиеся векторы в массив
  for (size_t i = 0; i < core_num; i++) {
    for (size_t j = 0; j < vec_size; j++) {
      vectors[i][j] = args[i].ans[j];
    }
  }

  simple_avg_vector(avg_vector, vectors, core_num);
}


