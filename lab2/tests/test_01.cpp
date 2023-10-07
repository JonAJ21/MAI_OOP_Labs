#include <gtest/gtest.h>
#include "twelve.h"

TEST(assignment_constructors, All) {
    Twelve t_1;

    ASSERT_TRUE(t_1.get_sz() == 0 && t_1.get_number() == nullptr);
    
    Twelve t_2 {'a','b', '9','2'};
    ASSERT_TRUE(t_2.get_sz() == 4);
    ASSERT_TRUE(t_2.get_number()[0] == '2');
    ASSERT_TRUE(t_2.get_number()[1] == '9');
    ASSERT_TRUE(t_2.get_number()[2] == 'B');
    ASSERT_TRUE(t_2.get_number()[3] == 'A');

    Twelve t_3 {"1a6b2"};
    ASSERT_TRUE(t_3.get_sz() == 5);
    ASSERT_TRUE(t_3.get_number()[0] == '2');
    ASSERT_TRUE(t_3.get_number()[1] == 'B');
    ASSERT_TRUE(t_3.get_number()[2] == '6');
    ASSERT_TRUE(t_3.get_number()[3] == 'A');
    ASSERT_TRUE(t_3.get_number()[4] == '1');

    t_1.~Twelve();
    t_2.~Twelve();
    t_3.~Twelve();
}

TEST(copy_constructor, All) {
    Twelve t_1 {"aba3131"};
    Twelve t_2 {t_1};

    ASSERT_TRUE(t_1.is_equal(t_2));
    ASSERT_TRUE(&t_1 != &t_2);
    
    t_1.~Twelve();
    t_2.~Twelve();
}

TEST(move_constructor, All) {
    Twelve t_1 {"90ab7"};
    Twelve t_2 {std::move(t_1)};

    ASSERT_TRUE(t_1.get_sz() == 0 && t_1.get_number() == nullptr);

    ASSERT_TRUE(t_2.get_sz() == 5);
    ASSERT_TRUE(t_2.get_number()[0] == '7');
    ASSERT_TRUE(t_2.get_number()[1] == 'B');
    ASSERT_TRUE(t_2.get_number()[2] == 'A');
    ASSERT_TRUE(t_2.get_number()[3] == '0');
    ASSERT_TRUE(t_2.get_number()[4] == '9');

    t_1.~Twelve();
    t_2.~Twelve();
}


TEST(copy_assigned_operator, All) {
    Twelve t_1 {"90ab7"};
    Twelve t_2;
    t_2 = t_1;

    ASSERT_TRUE(t_1.is_equal(t_2));
    
    t_1.~Twelve();
    t_2.~Twelve();
}

TEST(move_assigned_operator, All) {
    Twelve t_1 {"90ab7"};
    Twelve t_2;
    t_2 = std::move(t_1);

    ASSERT_TRUE(t_2.get_sz() == 5);
    ASSERT_TRUE(t_2.get_number()[0] == '7');
    ASSERT_TRUE(t_2.get_number()[1] == 'B');
    ASSERT_TRUE(t_2.get_number()[2] == 'A');
    ASSERT_TRUE(t_2.get_number()[3] == '0');
    ASSERT_TRUE(t_2.get_number()[4] == '9');
    
    t_1.~Twelve();
    t_2.~Twelve();
}

TEST(comparisons, All) {
    Twelve t_1 {"90ab7"};
    Twelve t_2 {"319000"};
    Twelve t_3 {"90ab7"};

    ASSERT_TRUE(t_1.is_equal(t_2) == false);
    ASSERT_TRUE(t_1.is_equal(t_3) == true);
    ASSERT_TRUE(t_2.is_equal(t_3) == false);

    ASSERT_TRUE(t_1.is_bigger(t_2) == false);
    ASSERT_TRUE(t_1.is_bigger(t_3) == false);
    ASSERT_TRUE(t_2.is_bigger(t_3) == true);

    ASSERT_TRUE(t_1.is_smaller(t_2) == true);
    ASSERT_TRUE(t_1.is_smaller(t_3) == false);
    ASSERT_TRUE(t_2.is_smaller(t_3) == false);

    t_1.~Twelve();
    t_2.~Twelve();
    t_3.~Twelve();
}


TEST(math_operations, All) {
    Twelve t_1 {"90ab7"};
    Twelve t_2 {"319000"};
    Twelve t_3 {"90ab7"};

    Twelve res_1 = {"3a9ab7"};
    Twelve res_2 = {"1619b2"};

    ASSERT_TRUE(t_1.add(t_2).is_equal(res_1));
    ASSERT_TRUE(t_1.add(t_3).is_equal(res_2));
    ASSERT_TRUE(t_2.add(t_3).is_equal(res_1));

    res_1 = {"248105"};
    res_2 = {'0'};

    ASSERT_TRUE(t_2.substract(t_3).is_equal(res_1));
    ASSERT_TRUE(t_1.substract(t_3).is_equal(res_2));

    t_1.~Twelve();
    t_2.~Twelve();
    t_3.~Twelve();
    res_1.~Twelve();
    res_2.~Twelve();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}