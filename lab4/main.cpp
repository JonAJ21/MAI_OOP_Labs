#include <iostream>
#include <memory>
#include <array.h>
#include "point2d.h"
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"




int main() {
    // Create and remove figures
    Array<Figure<double>, double> fig_array;
    
    std::cout << "=================================================================" << std::endl;
    std::cout << std::boolalpha << "fig_array is empty: " <<  fig_array.is_empty() << std::endl;
    std::cout << "=================================================================" << std::endl;
    
    std::shared_ptr<Figure<double>> fig_1;
    try {
        fig_1 = std::make_shared<Square<double>>(Square<double>({0,0}, {0, 1}, {1, 1}, {1, 0}));
        fig_array.push_back(fig_1);
    } catch (std::bad_alloc const & exception) {
        throw exception;
    }
    
    std::cout << "fig_array size: " <<  fig_array.size() << std::endl;
    fig_array.print();
    std::cout << "=================================================================" << std::endl;
    std::shared_ptr<Figure<double>> fig_2;
    std::shared_ptr<Figure<double>> fig_3;
    try {
        fig_2 = std::make_shared<Rectangle<double>>(Rectangle<double>({0,0}, {0, 2}, {4, 2}, {4, 0}));
        fig_3 = std::make_shared<Trapezoid<double>>(Trapezoid<double>({0,0}, {4, 0}, {0, 3}, {6, 3}));
        fig_array.insert(fig_2, 0);
        fig_array.insert(fig_3, 1);
    } catch (std::bad_alloc const & exception) {
        throw exception;
    }

    std::cout << "fig_array size: " <<  fig_array.size() << std::endl;
    fig_array.print();
    std::cout << "=================================================================" << std::endl;
    fig_array.remove(1);
    std::cout << "fig_array size: " <<  fig_array.size() << std::endl;
    fig_array.print();
    std::cout << "=================================================================" << std::endl;
    std::cout << "fig_array size: " <<  fig_array.size() << std::endl;
    try {
        fig_array.insert(fig_3, 1);
    } catch (std::bad_alloc const & exception) {
        throw exception;
    }
    fig_array.print();
    std::cout << "=================================================================" << std::endl;

    // Operations with figures
    for (size_t i = 0; i < fig_array.size(); ++i) {
        std::cout << fig_array[i].get() << ' ' << *fig_array[i] << ' ' << fig_array[i]->center().x
        << ' ' << fig_array[i]->center().y << ' ' << static_cast<double>(*fig_array[i]) << std::endl;
    }
    
    std::cout << "=================================================================" << std::endl;

    return 0;
}  