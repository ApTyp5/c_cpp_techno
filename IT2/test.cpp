//
// Created by arthur on 18.10.2019.
//
#include "errcodes.h"
#include "parallel_avg.h"
#include "simple_avg.h"

#include <gtest/gtest.h>
#include <random>
#include <cstddef>
#include <ctime>

// Генерация рандомного значения векторной переменной
my_vector_lt random_vector_lt(my_vector_lt min, my_vector_lt max) {
    srand(time(NULL));
    return ((my_vector_lt)(rand()) * (max - min) / RAND_MAX)  + min;
}

little_vector_t *create_test_vector_arr(size_t size){
    auto res = (little_vector_t *)malloc(sizeof(little_vector_t) * size);
    // Проверяю успешность malloc таким образом, так как функция тепличная,
    // используется только в тесках
    assert(res);
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < vec_size; j++)
            res[i][j] = random_vector_lt(-1000, 1000);

    return res;
}

TEST(compareTest, sizes_10_1000){
    for (size_t size = 10; size < 10001; size *= 10){
        little_vector_t ans1, ans2;
        little_vector_t *arr = create_test_vector_arr(size);

        simple_avg_vector(ans1, arr, size);
        parallel_avg_vector(ans2, arr, size);
        for (size_t i = 0; i < vec_size; i++){
            ASSERT_FLOAT_EQ(ans1[i], ans2[i]);
        }

        free(arr);
    }
}

TEST(avg_test, vectors_NULL){
    little_vector_t *vectors = NULL;
    little_vector_t avg_vector = {0};
    size_t size = 1;

    int ret_code = simple_avg_vector(avg_vector, vectors, size);
    EXPECT_EQ(ret_code, EXIT_NULL_REC);

    ret_code = parallel_avg_vector(avg_vector, vectors, size);
    EXPECT_EQ(ret_code, EXIT_NULL_REC);
}

TEST(avg_test, size_0){
    little_vector_t *vectors = create_test_vector_arr(1);
    little_vector_t avg_vector = {0};
    size_t size = 0;

    int ret_code = simple_avg_vector(avg_vector, vectors, size);
    EXPECT_EQ(ret_code, EXIT_ZERO_SIZ);

    ret_code = parallel_avg_vector(avg_vector, vectors, size);
    EXPECT_EQ(ret_code, EXIT_ZERO_SIZ);

    free(vectors);
}



int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


