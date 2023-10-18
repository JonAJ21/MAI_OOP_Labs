#include <iostream>
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include <typeinfo>
int main() {
    
    // Figure* figures = new Square({0, 0}, {0, 1}, {1, 1}, {1, 0});
    // std::cout << figures->area() << std::endl;
    Figure** figures = new Figure* [2];
    figures[0] = new Square({0, 0}, {0, 1}, {1, 1}, {1, 0});
    figures[1] = new Rectangle({0, 0}, {0, 2}, {3, 2}, {3, 0});
    // for (int i = 0; i < 2; ++i) {
    //     // std::cout << *figures[0] << std::endl;
    // }
    Square sq = *figures[0];



    return 0;
}  