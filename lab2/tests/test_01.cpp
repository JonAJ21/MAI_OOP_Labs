#include <gtest/gtest.h>

// TEST(test_01, basic_test_set)
// {
//     char* res = to_bin_32(0);
//     ASSERT_TRUE(strcmp(res, "00000000000000000000000000000000") == 0);
//     delete[] res;
// }

// TEST(test_02, basic_test_set)
// {
//     char* res = to_bin_32(UINT32_MAX);
//     ASSERT_TRUE(strcmp(res, "11111111111111111111111111111111") == 0);
//     delete[] res;
// }

// TEST(test_03, basic_test_set)
// {
//     char* res = to_bin_32(4627884);
//     ASSERT_TRUE(strcmp(res, "00000000010001101001110110101100") == 0);
//     delete[] res;
// }

// TEST(test_04, basic_test_set)
// {
//     char* res = to_bin_32(79828742);
//     ASSERT_TRUE(strcmp(res, "00000100110000100001011100000110") == 0);
//     delete[] res;
// }

// TEST(test_05, basic_test_set)
// {
//     char* res = to_bin_32(10000);
//     ASSERT_TRUE(strcmp(res, "00000000000000000010011100010000") == 0);
//     delete[] res;
// }


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}