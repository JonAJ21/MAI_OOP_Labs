#include <gtest/gtest.h>
#include <limits>
#include "to_bin_32.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(to_bin_32(0) == "00000000000000000000000000000000");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(to_bin_32(UINT32_MAX) == "11111111111111111111111111111111");
}


TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(to_bin_32(4627884) == "00000000010001101001110110101100");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(to_bin_32(79828742) == "00000100110000100001011100000110");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(to_bin_32(10000) == "00000000000000000010011100010000");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}