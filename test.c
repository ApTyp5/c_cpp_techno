#include <gtest/gtest.h>

#include "io_tools.h"
#include "proc_tools.h"

/* AUX FUNCTIONS */
void arrcmp(const int *const arr1, size_t len1,
            const int *const arr2, size_t len2){
    ASSERT_EQ(len1, len2);
    for (size_t i = 0; i < len1; i++){
        ASSERT_EQ(arr2[i], arr1[i]);
    }
}

/* PROCESS TOOLS TESTS */

TEST(process_data, negative){
    int *arr = NULL;
    size_t len = 0;

    ASSERT_EQ(EXIT_FAILURE, process_data(arr, len));
}

TEST(process_data, positive){
    int arr[] = {1, 2};
    size_t len = 2;

    ASSERT_EQ(EXIT_SUCCESS, process_data(arr, len));
}

TEST(longest_arithm_seq, negative_len_0){
    int *arr = NULL;
    size_t len = 0;

    const int *out_arr = NULL;
    ASSERT_EQ(longest_arithm_seq(&out_arr, arr, len), 0);
}

TEST(longest_arithm_seq, negative_len_1){
    int arr[] = {1};
    size_t len = 1;

    const int *out_arr = NULL;
    size_t out_len = longest_arithm_seq(&out_arr, arr, len);
    ASSERT_EQ(out_len, 0);
}

TEST(longest_arithm_seq, positive_start_seq){
    int arr[] = {1, 2, 3, 5, 3};
    size_t len = 5;

    const int *out_arr = NULL;
    size_t out_len = longest_arithm_seq(&out_arr, arr, len);

    int right_arr[] = {1, 2, 3};
    size_t right_len = 3;

    ASSERT_EQ(out_len, right_len);
    arrcmp(right_arr, right_len, out_arr, out_len);
}

TEST(longest_arithm_seq, positive_end_seq){
    int arr[] = {-12, 1, 2, 3};
    size_t len = 4;

    const int *out_arr = NULL;
    size_t out_len = longest_arithm_seq(&out_arr, arr, len);

    int right_arr[] = {1, 2, 3};
    size_t right_len = 3;

    arrcmp(right_arr, right_len, out_arr, out_len);
}

TEST(longest_arithm_seq, positive_center_seq){
    int arr[] = {-12, 1, 2, 3, 4, 5, 345, 32};
    size_t len = 8;

    const int *out_arr = NULL;
    size_t out_len = longest_arithm_seq(&out_arr, arr, len);

    int right_arr[] = {1, 2, 3, 4, 5};
    size_t right_len = 5;

    arrcmp(right_arr, right_len, out_arr, out_len);
}

/* IO TOOLS TESTS */



int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}











