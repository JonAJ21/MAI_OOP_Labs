#include <iostream>
#include <memory>
#include <array.h>
#include "point2d.h"
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

#include <typeinfo>

int main() {
    // auto fig_1 = std::make_shared<Square<double>>(Square<double>({0,0}, {0, 1}, {1, 1}, {1, 0}));
    // auto fig_2 = std::make_shared<Rectangle<double>>(Rectangle<double>({0,0}, {0, 2}, {4, 2}, {4, 0}));
    // auto fig_3 = std::make_shared<Rectangle<double>>(Rectangle<double>({0,0}, {0, 2}, {4, 2}, {4, 0}));
    // auto fig_4 = std::make_shared<Square<double>>(Square<double>({0,0}, {0, 1}, {1, 1}, {1, 0}));
    // auto fig_5 = std::make_shared<Square<double>>(Square<double>({0,0}, {0, 1}, {1, 1}, {1, 0}));
    
    std::cout << "What type of points do you want to store in the array?" << std::endl;
    std::cout << "1. int" << std::endl;
    std::cout << "2. double" << std::endl;
    int type_num = 0;
    std::cin >> type_num;
    
    



    return 0;
}  