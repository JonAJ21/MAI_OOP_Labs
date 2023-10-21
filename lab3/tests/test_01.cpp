#include <gtest/gtest.h>
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

TEST(center, All) {
    Square sq {{1, 0}, {0, 1}, {1, 2}, {2, 1}};
    Rectangle rec {{1, 0}, {0, 1}, {2, 3}, {3, 2}};
    Trapezoid tr {{1,0}, {2, 2}, {5, 2}, {6, 0}};
    ASSERT_TRUE(abs(sq.center().x - 1) < 1e-6 && abs(sq.center().y - 1) < 1e-6);
    ASSERT_TRUE(abs(rec.center().x - 1.5) < 1e-6 && abs(rec.center().y - 1.5) < 1e-6);
    ASSERT_TRUE(abs(tr.center().x - 3.5) < 1e-6 && abs(tr.center().y - 1) < 1e-6);
}

TEST(area, All) {
    Square sq {{1, 0}, {0, 1}, {1, 2}, {2, 1}};
    Rectangle rec {{1, 0}, {0, 1}, {2, 3}, {3, 2}};
    Trapezoid tr {{1,0}, {2, 2}, {5, 2}, {6, 0}};
    ASSERT_TRUE(abs(sq.area() - 2) < 1e-6);
    ASSERT_TRUE(abs(rec.area() - 4) < 1e-6);
    ASSERT_TRUE(abs(tr.area() - 8) < 1e-6);

    ASSERT_TRUE(abs((double) sq - 2) < 1e-6);
    ASSERT_TRUE(abs((double) rec - 4) < 1e-6);
    ASSERT_TRUE(abs((double) tr - 8) < 1e-6);
}

TEST(equal, All) {
    Square sq_1 {{1, 0}, {0, 1}, {1, 2}, {2, 1}};
    Square sq_2 = sq_1;
    Square sq_3 {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
    ASSERT_TRUE(sq_1 == sq_2);
    ASSERT_FALSE(sq_2 == sq_3);

    Rectangle rec_1 {{1, 0}, {0, 1}, {2, 3}, {3, 2}};
    Rectangle rec_2 = rec_1;
    Rectangle rec_3 {{0, 0}, {0, 4}, {4, 2}, {0, 2}};
    ASSERT_TRUE(rec_1 == rec_2);
    ASSERT_FALSE(rec_2 == rec_3);

    Trapezoid tr_1 {{1,0}, {2, 2}, {5, 2}, {6, 0}};
    Trapezoid tr_2 = tr_1;
    Trapezoid tr_3 {{1,0}, {2, 3}, {5, 3}, {6, 0}};
    ASSERT_TRUE(tr_1 == tr_2);
    ASSERT_FALSE(tr_2 == tr_3);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}