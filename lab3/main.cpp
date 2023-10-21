#include <iostream>
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

int main() {
    Figure** figures = nullptr;
    size_t sz = 0;
    double total_area = 0;
    while(std::cin) {
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Add figure" << std::endl; 
        std::cout << "2. Delete figure by index" << std::endl;
        std::cout << "3. Print figures (their coordinates)" << std::endl;
        std::cout << "4. Print areas" << std::endl;
        std::cout << "5. Print total area" << std::endl;
        std::cout << "6. Print centers" << std::endl;
        int action = 0;
        int fig = 0;
        std::cin >> action;
        switch (action)
        {
        case 1:
            // Add figure
            if (sz == 0) {
                figures = (Figure**) malloc(sizeof(Figure*));
                figures[sz] = nullptr;
                ++sz;
            } else {
                figures = (Figure**) realloc(figures, ++sz * sizeof(Figure*));
                figures[sz - 1] = nullptr;
            }
            std::cout << "What figure do you want to add?" << std::endl;
            std::cout << "1. Square" << std::endl; 
            std::cout << "2. Rectangle" << std::endl;
            std::cout << "3. Trapezoid" << std::endl;
            std::cin >> fig;
            switch (fig)
            {
            case 1:
                std::cout << "Enter coordinates" << std::endl;
                figures[sz - 1] = new Square();
                std::cin >> *figures[sz - 1];
                break;
            case 2:
                std::cout << "Enter coordinates" << std::endl;
                figures[sz - 1] = new Rectangle();
                std::cin >> *figures[sz - 1];
                break;
            case 3:
                std::cout << "Enter coordinates" << std::endl;
                figures[sz - 1] = new Trapezoid();
                std::cin >> *figures[sz - 1];
                break;
            default:
                std::cout << "Incorrect value" << std::endl;
                break;
            }
            break;
        case 2:
            // Delete figure by index
            std::cout << "Enter index" << std::endl;
            size_t idx;
            std::cin >> idx;
            delete figures[idx];
            figures[idx] = nullptr;
            for (size_t i = idx; i < sz - 1; ++i) {
                figures[i] = figures[i + 1];
            }
            figures = (Figure**) realloc(figures, --sz * sizeof(Figure*));
            break;
        case 3:
            // Print figures
            std::cout << "Your figures:" << std::endl;
            for (size_t i = 0; i < sz; ++i) {
                std::cout << *figures[i] << std::endl;
            }
            break;
        case 4:
            // Print areas
            std::cout << "Areas:" << std::endl;
            for (size_t i = 0; i < sz; ++i) {
                std::cout << (double) *figures[i] << std::endl;
            }
            break;
        case 5:
            // Print total area
            std::cout << "Total area:" << std::endl;
            total_area = 0;
            for (size_t i = 0; i < sz; ++i) {
                total_area += (double) *figures[i];
            }
            std::cout << total_area << std::endl;
            break;
        case 6:
            // Prints centers
            std::cout << "Centers:" << std::endl;
            for (size_t i = 0; i < sz; ++i) {
                std::cout << figures[i]->center().x << ' ' << figures[i]->center().y << std::endl;
            }
            break;
        default:
            std::cout << "Wrong value" << std::endl;
            break;   
        }
    }
    std::cout << "END" << std::endl;

    for (size_t i = 0; i < sz; ++i) {
        delete figures[i];
    }
    free(figures);
    return 0;
}  