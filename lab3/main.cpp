#include <iostream>
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include <typeinfo>



int main() {


    Figure** figures = nullptr;
    size_t sz = 0;
    while(true) {
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Add figure" << std::endl; 
        std::cout << "2. Delete figure by index" << std::endl;
        std::cout << "3. Print figures (their coordinates)" << std::endl;
        std::cout << "4. Print areas" << std::endl;
        std::cout << "5. Print total area" << std::endl;
        std::cout << "6. Print centers" << std::endl;
        std::cout << "7. Compare two figures" << std::endl;
        int action;
        std::cin >> action;
        switch (action)
        {
        case 1:
        // Add figure
            if (sz == 0) {
                figures = (Figure**) malloc(sizeof(Figure*)); 
                ++sz;
            } else {
                figures = (Figure**) realloc(figures, ++sz * sizeof(Figure*));
            }
            std::cout << "What figure do you want to add?" << std::endl;
            std::cout << "1. Square" << std::endl; 
            std::cout << "2. Rectangle" << std::endl;
            std::cout << "3. Trapezoid" << std::endl;
            int fig;
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
                continue;
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
            figures = (Figure**) realloc(figures,--sz * sizeof(Figure*));
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
            double total = 0;
            for (size_t i = 0; i < sz; ++i) {
                total += (double) *figures[i];
            }
            std::cout << total << std::endl;
            break;
        case 6:
            std::cout << "Centers:" << std::endl;
            for (size_t i = 0; i < sz; ++i) {
                std::cout << figures[i]->center() << std::endl;
            }
            break;
        case 7:
            std::cout << "Enter lhs index: ";
            size_t lhs;
            std::cin >> lhs;
            std::cout << "Enter rhs index: ";
            size_t rhs;
            std::cin >> rhs;

            break;
        default:
            std::cout << "Wrong value" << std::endl;
            continue;        
        }
    }
    std::cout << "END" << std::endl;

    free(figures);
    return 0;
}  