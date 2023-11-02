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
    // int sz = 10;
    // std::shared_ptr<std::shared_ptr<Figure<double>>[]> figures = std::make_shared< std::shared_ptr<Figure<double>>[] >(sz);
    // figures[0] = std::make_shared<Square<double>>(Square<double>({0,0}, {0, 1}, {1, 1}, {1, 0}));
    // figures[1] = std::make_shared<Rectangle<double>>(Rectangle<double>({0,0}, {0, 2}, {4, 2}, {4, 0}));
    // figures[2] = std::make_shared<Rectangle<double>>(Rectangle<double>({0,0}, {0, 2}, {4, 2}, {4, 0}));
    // std::cout << typeid(*figures[0]).name() << std::endl;
    // std::cout << typeid(*figures[1]).name() << std::endl;
    // std::cout << typeid(*figures[2]).name() << std::endl;
    // std::cout << (typeid(*figures[2]) == typeid(Rectangle<double>)) << std::endl;


    // std::cout << "Area 0: " << (double) *figures[0] << std::endl;
    // std::cout << "Area 1: " << figures[1]->area() << std::endl;

    auto fig_1 = std::make_shared<Square<double>>(Square<double>({0,0}, {0, 1}, {1, 1}, {1, 0}));
    auto fig_2 = std::make_shared<Rectangle<double>>(Rectangle<double>({0,0}, {0, 2}, {4, 2}, {4, 0}));

    Array<double> array_1 {fig_1, fig_2};
    array_1.print();

    Array<double> array_2;
    array_2 = std::move(array_1);
    
    array_2.print();

    return 0;
}  