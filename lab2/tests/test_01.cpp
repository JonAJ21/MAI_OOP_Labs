#include <gtest/gtest.h>
#include "twelve.h"

// TEST(Twelve, Initializations) {
//     // Twelve t1 = { 'C', 'A', '3' };
//     // Twelve t2 = Twelve(3, 'A');
//     // Twelve t3 = Twelve();
//     // Twelve t4 = Twelve(0, 'A');
    
//     // // ASSERT_TRUE(t3 == t4);

//     // t4 = t2;
//     // ASSERT_TRUE(t4 == t2);

//     // t2 = std::move(t1);
//     // ASSERT_TRUE(t1.is_empty());
//     // ASSERT_TRUE(t4 != t2);

//     // Twelve t5 = Twelve(t4);
//     // Twelve t6 = Twelve(std::move(t4));
//     // ASSERT_TRUE(t4.is_empty());
//     // ASSERT_TRUE(t5 == t6);
// }

// TEST(Twelve, Addition) {
//     Twelve t1 = { '8', 'A' };
//     Twelve t2 = { 'A', 'B' };

//     Twelve t3 = std::string("168");
//     Twelve t4 = t1 + t2;
//     ASSERT_TRUE(t4 == t3);

//     Twelve ta = { 'A' };
//     t1 = { '1' };
//     Twelve tb = { 'B' };
//     ASSERT_TRUE(ta + t1 == tb);
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}