//
// Created by arthur on 18.10.2019.
//
#include "parallelAvg.h"
#include "simpleAvg.h"

#include <gtest/gtest.h>
#include <random>
#include <cstddef>

Vector_lt random_Vector_lt(Vector_lt min, Vector_lt max) {

    return (static_cast<Vector_lt>(rand()) / RAND_MAX) * (max - min) + min;
}

littleVector_t *create_test_vector_arr(size_t size){
    auto *res = new littleVector_t[size];
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < VecSize; j++)
            res[i][j] = random_Vector_lt(-MAXFLOAT, MAXFLOAT);

    return res;
}

littleVector_t *copy_test_vector_arr(littleVector_t *arr1, size_t size){
    auto *res = new littleVector_t[size];
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < VecSize; j++)
            res[i][j] = arr1[i][j];

    return res;
}
/*
TEST(compareTest, size5){
    size_t size = 5;
    littleVector_t ans1;
    littleVector_t ans2;
    littleVector_t *arr1 = create_test_vector_arr(size);
    littleVector_t *arr2 = copy_test_vector_arr(arr1, size);
    simpleAvgVector(ans1, arr1, size);
    parallelAvgVector(ans2, arr2, size);
    for (size_t i = 0; i < VecSize; i++){
        ASSERT_EQ(ans1[i], ans2[i]);
    }
}
*/


int main(int argc, char *argv[]){
    /*
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    */

    size_t size = 5;
    littleVector_t ans1;
    littleVector_t ans2;
    littleVector_t *arr1 = create_test_vector_arr(size);
    littleVector_t *arr2 = copy_test_vector_arr(arr1, size);
    simpleAvgVector(ans1, arr1, size);
    parallelAvgVector(ans2, arr2, size);
}


