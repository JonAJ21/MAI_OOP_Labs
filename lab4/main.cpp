#include <iostream>
#include <memory>
#include "point2d.h"
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

int main() {
    
    int sz = 10;
    std::shared_ptr<Figure<double>[]> figures = std::make_shared<Figure<double>[]>(sz);
    figures[0] = new Square({0, 0}, {0, 1}, {1, 1}, {1, 0});
    std::cout << *figures[0] << std::endl;
    // std::shared_ptr<int[]> ptrs = std::make_shared<int[]>(sz);

    

    return 0;
}  