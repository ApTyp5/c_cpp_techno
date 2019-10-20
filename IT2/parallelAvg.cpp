//
// Created by arthur on 18.10.2019.
//



#include "parallelAvg.h"

typedef struct summerArgs summerArgs;
struct summerArgs{
    littleVector_t *vectors;
    size_t size;
    bigVector_t sum;
};

void *summer(void *sumArgs) {
    auto *summerArgs_ptr    = (summerArgs *)sumArgs;
    littleVector_t *vectors = summerArgs_ptr->vectors;
    size_t size             = summerArgs_ptr->size;

    bigVector_t sum = {0};
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < VecSize; j++)
            sum[j] += vectors[i][j];

    for (size_t j = 0; j < VecSize; j++){
        summerArgs_ptr->sum[j] = sum[j];
    }

    pthread_exit(nullptr);
}

size_t find_core_num(){
    /*
    size_t core_num = system("cat /proc/cpuinfo | grep processor | wc -l");
    */
    size_t core_num = 4;
    assert(core_num < MAX_CORES);

    return core_num;
}

inline void start_all_threads(summerArgs args[], pthread_t threads[],
                              littleVector_t vectors[], size_t core_num,
                              size_t el_per_core, size_t size){

    for (size_t i = 0; i < core_num - 1; i++){
        args[i] = {vectors + i * el_per_core, el_per_core};
        pthread_create(threads + i, nullptr, summer, args + i);
    }

    size_t last_i = core_num - 1;
    size_t elements_processed = el_per_core * last_i;
    args[last_i] = {vectors + elements_processed,size - elements_processed};
    pthread_create(threads + last_i, nullptr, summer, args + last_i);
}

inline void wait_all_threads(pthread_t threads[], size_t core_num){
    for (size_t i = 0; i < core_num; i++){
        pthread_join(threads[i], nullptr);
    }
}

inline void count_answer(littleVector_t avg_vector, summerArgs args[],
                        size_t core_num, size_t size){
    bigVector_t sum = {0};
    for (size_t i = 0; i < core_num; i++)
        for (size_t j = 0; j < VecSize; j++)
            sum[j] += args[i].sum[j];

    for (size_t j = 0; j < VecSize; j++){
        sum[j] /= size;
        avg_vector[j] = (Vector_lt) sum[j];
    }
}

int parallelAvgVector(littleVector_t avg_vector, littleVector_t vectors[], size_t size)
{

    if (unlikely((avg_vector == nullptr)
                       || vectors == nullptr)) return EXIT_NULL_REC;

    if (unlikely(size == 0)) return EXIT_ZERO_SIZ;

    // Считаем клоличество логических ядер процессра
    size_t core_num = find_core_num();
    if (core_num <= 0) return EXIT_FAILURE;

    // Почему бы и не воспользоваться массивами переменной длины,
    // количество ядер мало когда будет меньше ста
    pthread_t threads[core_num];
    summerArgs args[core_num];
    size_t el_per_core = size / core_num;

    start_all_threads(args, threads, vectors,core_num, el_per_core, size);
    wait_all_threads(threads, core_num);
    count_answer(avg_vector, args, core_num, size);
    return EXIT_SUCCESS;
}
