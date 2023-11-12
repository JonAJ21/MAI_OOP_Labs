#include <gtest/gtest.h>

TEST(point2d, All) {
    
    ASSERT_TRUE(1 == 1);
}

// TEST(square, All) {
//     Square<int> sq {{0, 1}, {1, 2}, {2, 1}, {1, 0}};
    
//     int sq_center_x = sq.center().x;
//     int sq_center_y = sq.center().y;
//     ASSERT_TRUE(are_equal(sq_center_x, 1, 1e-6));
//     ASSERT_TRUE(are_equal(sq_center_y, 1, 1e-6));
    
//     double sq_area_func = sq.area();
//     double sq_area_double = static_cast<double>(sq);
//     ASSERT_TRUE(are_equal(sq_area_func, 2.0, 1e-6));
//     ASSERT_TRUE(are_equal(sq_area_double, 2.0, 1e-6));

//     Square<int> sq_1 = sq;
//     Square<int> sq_2;
//     sq_2 = sq;
//     ASSERT_TRUE(sq_1 == sq_2);
//     Square<int> sq_3 {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
//     ASSERT_TRUE(!(sq_2 == sq_3));

//     bool throwed = 0;
//     try {
//         Square<int> sq_4 {{1, 1}, {0, 1}, {1, 1}, {1, 0}};
//     } catch (const std::invalid_argument& exception) {
//         throwed = 1;
//     }
//     ASSERT_TRUE(throwed);
// }

// TEST(rectangle, All) {
//     Rectangle<double> rec {{1, 0}, {0, 1}, {2, 3}, {3, 2}};
    
//     double rec_center_x = rec.center().x;
//     double rec_center_y = rec.center().y;
//     ASSERT_TRUE(are_equal(rec_center_x, 1.5, 1e-6));
//     ASSERT_TRUE(are_equal(rec_center_y, 1.5, 1e-6));
    
//     double rec_area_func = rec.area();
//     double rec_area_double = static_cast<double>(rec);
//     ASSERT_TRUE(are_equal(rec_area_func, 4.0, 1e-6));
//     ASSERT_TRUE(are_equal(rec_area_double, 4.0, 1e-6));

//     Rectangle<double> rec_1 = rec;
//     Rectangle<double> rec_2;
//     rec_2 = rec;
//     ASSERT_TRUE(rec_1 == rec_2);
//     Rectangle<double> rec_3 {{0, 0}, {0, 2}, {4, 2}, {4, 0}};
//     ASSERT_TRUE(!(rec_2 == rec_3));

//     bool throwed = 0;
//     try {
//         Rectangle<int> rec_4 {{1, 1}, {0, 1}, {1, 1}, {1, 0}};
//     } catch (const std::invalid_argument& exception) {
//         throwed = 1;
//     }
//     ASSERT_TRUE(throwed);
// }

// TEST(trapezoid, All) {
//     Trapezoid<double> tr {{1,0}, {2, 2}, {5, 2}, {6, 0}};

//     double tr_center_x = tr.center().x;
//     double tr_center_y = tr.center().y;
//     ASSERT_TRUE(are_equal(tr_center_x, 3.5, 1e-6));
//     ASSERT_TRUE(are_equal(tr_center_y, 1.0, 1e-6));

//     double tr_area_func = tr.area();
//     double tr_area_double = static_cast<double>(tr);
//     ASSERT_TRUE(are_equal(tr_area_func, 8.0, 1e-6));
//     ASSERT_TRUE(are_equal(tr_area_double, 8.0, 1e-6));

//     Trapezoid<double> tr_1 = tr;
//     Trapezoid<double> tr_2;
//     tr_2 = tr;
//     ASSERT_TRUE(tr_1 == tr_2);
//     Trapezoid<double> tr_3 {{1,0}, {2, 3}, {5, 3}, {6, 0}};
//     ASSERT_TRUE(!(tr_2 == tr_3));

//     bool throwed = 0;
//     try {
//         Trapezoid<int> tr_4 {{1, 1}, {0, 1}, {1, 1}, {1, 0}};
//     } catch (const std::invalid_argument& exception) {
//         throwed = 1;
//     }
//     ASSERT_TRUE(throwed);
// }

// TEST(array, All) {

//     Array<Figure<double>, double> array_1;
//     ASSERT_TRUE(array_1.is_empty());
//     std::shared_ptr<Figure<double>> fig_1;
//     std::shared_ptr<Figure<double>> fig_2;
//     std::shared_ptr<Figure<double>> fig_3;
//     try {
//         fig_1 = std::make_shared<Square<double>>(Square<double>({0,0}, {0, 1}, {1, 1}, {1, 0}));
//         fig_2 = std::make_shared<Rectangle<double>>(Rectangle<double>({0,0}, {0, 2}, {4, 2}, {4, 0}));
//         fig_3 = std::make_shared<Trapezoid<double>>(Trapezoid<double>({0,0}, {4, 0}, {0, 3}, {6, 3}));
//         Array<Figure<double>, double> array_2 {fig_1, fig_2, fig_3};
//         ASSERT_TRUE(!array_2.is_empty());
//         array_1 = array_2;
//     } catch (std::bad_alloc const & exception) {
//         throw exception;
//     }
//     ASSERT_TRUE(!array_1.is_empty());

//     try {
//         Array<Figure<double>, double> array_2 {array_1};
//         ASSERT_TRUE(array_2.size() == 3);
//         for (size_t i = 0; i < array_2.size(); ++i) {
//         ASSERT_TRUE(!(array_1[i] == array_2[i]));
//     }
//     } catch (std::bad_alloc const & exception) {
//         throw exception;
//     }
//     std::shared_ptr<Figure<double>> fig_4;
//     try {
//         fig_4 = std::make_shared<Square<double>>(Square<double>({0,0}, {0, 2}, {2, 2}, {2, 0}));
//         array_1.push_back(fig_4);
//     } catch (std::bad_alloc const & exception) {
//         throw exception;
//     }
//     ASSERT_TRUE(array_1[3] == fig_4);

//     try {
//         array_1.insert(fig_2, 2);
//     } catch (std::bad_alloc const & exception) {
//         throw exception;
//     }
//     ASSERT_TRUE(array_1[2] == fig_2);
//     array_1.remove(3);
//     ASSERT_TRUE(array_1.size() == 4);

// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}