#include <iostream>
#include "twelve.h"

int main() {

    Twelve x {"3224ba"};
    Twelve y {'3', '2', '2', '4', 'b', 'b'};

    x.print(std::cout) << std::endl;
    y.print(std::cout) << std::endl;


    std::cout << std::boolalpha << x.is_bigger(y) << std::endl;
    std::cout << std::boolalpha << x.is_smaller(y) << std::endl;
    std::cout << std::boolalpha << x.is_equal(y) << std::endl;

    x.~Twelve();
    y.~Twelve();
    return 0;
}