//
// Created by arthur on 18.10.2019.
//


#include "simpleAvg.h"

int simpleAvgVector(littleVector_t avg_vector, littleVector_t vectors[], size_t size)
{
    if (unlikely((avg_vector == nullptr)
                ||(vectors == nullptr)))   return EXIT_NULL_REC;

    if (unlikely(size == 0))  return EXIT_ZERO_SIZ;

    Vector_bt sum[VecSize] = {0};

    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < VecSize; j++)
            sum[j] += vectors[i][j];

    for (size_t j = 0; j < VecSize; j++) {
        sum[j] /= size;
        avg_vector[j] = (Vector_lt) sum[j];
    }

    return EXIT_SUCCESS;
}
