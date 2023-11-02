#include <gtest/gtest.h>
#include "point2d.h"
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

TEST(point2d, All) {
    Point2D<int> p_1 {1, 2};
    ASSERT_TRUE(p_1.x == 1 && p_1.y == 2);
    
    Point2D<double> p_2 {1.3, 4.5};
    ASSERT_TRUE(p_2.x == 1.3 && p_2.y == 4.5);

    ASSERT_TRUE(are_equal(p_1.x, p_1.x, 1e-6));
    ASSERT_TRUE(are_equal(p_2.y, p_2.y, 1e-6));
    ASSERT_TRUE(!are_equal(static_cast<double>(p_1.y), p_2.x, 1e-6));

    Point2D<int> p_3 {0, 0};
    Point2D<int> p_4 {0, 2};
    Point2D<int> p_5 {2, 2};
    Point2D<int> p_6 {2, 0};

    ASSERT_TRUE(are_sides_parallel(p_3, p_4, p_5, p_6));
    ASSERT_TRUE(are_sides_parallel(p_3, p_6, p_5, p_4));
    ASSERT_TRUE(!are_sides_parallel(p_3, p_5, p_4, p_6));

    double len_1 = get_len(p_3, p_4);
    ASSERT_TRUE(are_equal(len_1, 2.0, 1e-6));

    double len_2 = get_len(p_3, p_5);
    ASSERT_TRUE(are_equal(len_2, 2 * sqrt(2), 1e-6));

    double len_3 = get_len(p_3, p_6);
    ASSERT_TRUE(!are_equal(len_3, 2 * sqrt(2), 1e-6));
}

TEST(square, All) {
    Square<int> sq {{0, 1}, {1, 2}, {2, 1}, {1, 0}};
    
    int sq_center_x = sq.center().x;
    int sq_center_y = sq.center().y;
    ASSERT_TRUE(are_equal(sq_center_x, 1, 1e-6));
    ASSERT_TRUE(are_equal(sq_center_y, 1, 1e-6));
    
    double sq_area_func = sq.area();
    double sq_area_double = static_cast<double>(sq);
    ASSERT_TRUE(are_equal(sq_area_func, 2.0, 1e-6));
    ASSERT_TRUE(are_equal(sq_area_double, 2.0, 1e-6));

    Square<int> sq_1 = sq;
    Square<int> sq_2;
    sq_2 = sq;
    ASSERT_TRUE(sq_1 == sq_2);
    Square<int> sq_3 {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
    ASSERT_TRUE(!(sq_2 == sq_3));

    bool throwed = 0;
    try {
        Square<int> sq_4 {{1, 1}, {0, 1}, {1, 1}, {1, 0}};
    } catch (const std::invalid_argument& exception) {
        throwed = 1;
    }
    ASSERT_TRUE(throwed);
}

TEST(rectangle, All) {
    Rectangle<double> rec {{1, 0}, {0, 1}, {2, 3}, {3, 2}};
    
    double rec_center_x = rec.center().x;
    double rec_center_y = rec.center().y;
    ASSERT_TRUE(are_equal(rec_center_x, 1.5, 1e-6));
    ASSERT_TRUE(are_equal(rec_center_y, 1.5, 1e-6));
    
    double rec_area_func = rec.area();
    double rec_area_double = static_cast<double>(rec);
    ASSERT_TRUE(are_equal(rec_area_func, 4.0, 1e-6));
    ASSERT_TRUE(are_equal(rec_area_double, 4.0, 1e-6));

    Rectangle<double> rec_1 = rec;
    Rectangle<double> rec_2;
    rec_2 = rec;
    ASSERT_TRUE(rec_1 == rec_2);
    Rectangle<double> rec_3 {{0, 0}, {0, 2}, {4, 2}, {4, 0}};
    ASSERT_TRUE(!(rec_2 == rec_3));

    bool throwed = 0;
    try {
        Rectangle<int> rec_4 {{1, 1}, {0, 1}, {1, 1}, {1, 0}};
    } catch (const std::invalid_argument& exception) {
        throwed = 1;
    }
    ASSERT_TRUE(throwed);
}

TEST(trapezoid, All) {
    Trapezoid<double> tr {{1,0}, {2, 2}, {5, 2}, {6, 0}};

    double tr_center_x = tr.center().x;
    double tr_center_y = tr.center().y;
    ASSERT_TRUE(are_equal(tr_center_x, 3.5, 1e-6));
    ASSERT_TRUE(are_equal(tr_center_y, 1.0, 1e-6));

    double tr_area_func = tr.area();
    double tr_area_double = static_cast<double>(tr);
    ASSERT_TRUE(are_equal(tr_area_func, 8.0, 1e-6));
    ASSERT_TRUE(are_equal(tr_area_double, 8.0, 1e-6));

    Trapezoid<double> tr_1 = tr;
    Trapezoid<double> tr_2;
    tr_2 = tr;
    ASSERT_TRUE(tr_1 == tr_2);
    Trapezoid<double> tr_3 {{1,0}, {2, 3}, {5, 3}, {6, 0}};
    ASSERT_TRUE(!(tr_2 == tr_3));

    bool throwed = 0;
    try {
        Trapezoid<int> tr_4 {{1, 1}, {0, 1}, {1, 1}, {1, 0}};
    } catch (const std::invalid_argument& exception) {
        throwed = 1;
    }
    ASSERT_TRUE(throwed);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}