//
// Created by arthur on 18.10.2019.
//
#include "errcodes.h"
#include "parallelAvg.h"
#include "simpleAvg.h"

#include <gtest/gtest.h>
#include <random>
#include <cstddef>
#include <ctime>

// Генерация рандомного значения векторной переменной
Vector_lt random_Vector_lt(Vector_lt min, Vector_lt max) {
    srand(time(NULL));
    return (static_cast<Vector_lt>(rand()) * (max - min) / RAND_MAX)  + min;
}

littleVector_t *create_test_vector_arr(size_t size){
    auto res = (littleVector_t *)malloc(sizeof(littleVector_t) * size);
    // Проверяю успешность malloc таким образом, так как функция тепличная,
    // используется только в тесках
    assert(res);
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < VecSize; j++)
            res[i][j] = random_Vector_lt(-1000, 1000);

    return res;
}

littleVector_t *copy_test_vector_arr(littleVector_t *arr1, size_t size){
    auto res = (littleVector_t *)malloc(sizeof(littleVector_t) * size);
    assert(res);
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < VecSize; j++)
            res[i][j] = arr1[i][j];

    return res;
}

TEST(compareTest, sizes_10_10000){
    for (size_t size = 10; size < 10001; size *= 10){
        littleVector_t ans1, ans2;
        littleVector_t *arr1 = create_test_vector_arr(size);
        littleVector_t *arr2 = copy_test_vector_arr(arr1, size);

        simpleAvgVector(ans1, arr1, size);
        parallelAvgVector(ans2, arr2, size);
        for (size_t i = 0; i<VecSize; i++){
            ASSERT_FLOAT_EQ(ans1[i], ans2[i]);
        }

        free(arr1);
        free(arr2);
    }
}

TEST(AvgTest, vectors_NULL){
    littleVector_t *vectors = NULL;
    littleVector_t avg_vector = {0};
    size_t size = 1;

    int ret_code = simpleAvgVector(avg_vector, vectors, size);
    ASSERT_EQ(ret_code, EXIT_NULL_REC);

    ret_code = parallelAvgVector(avg_vector, vectors, size);
    ASSERT_EQ(ret_code, EXIT_NULL_REC);
}

TEST(AvgTest, size_0){
    littleVector_t *vectors = create_test_vector_arr(1);
    littleVector_t avg_vector = {0};
    size_t size = 0;

    int ret_code = simpleAvgVector(avg_vector, vectors, size);
    ASSERT_EQ(ret_code, EXIT_ZERO_SIZ);

    ret_code = parallelAvgVector(avg_vector, vectors, size);
    ASSERT_EQ(ret_code, EXIT_ZERO_SIZ);

    free(vectors);
}



int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

