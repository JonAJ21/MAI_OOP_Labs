#include <iostream>
#include "point2d.h"
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

int main() {
    
    Point2D<int> p_1 {1, 2};
    // ASSERT_TRUE(p_1.x == 1 && p_1.y == 2);
    
    Point2D<double> p_2 {1.3, 4.5};
    // ASSERT_TRUE(p_2.x == 1.3 && p_2.y == 4.5);

    std::cout << are_equal(p_2.x, p_2.x, 1e-6);

    return 0;
}  