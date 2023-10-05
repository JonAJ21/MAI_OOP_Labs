#include <iostream>
#include "twelve.h"

int main() {

    Twelve x {"bbb"};
    Twelve y {"bba"};
    Twelve z = x.substract(y);

    std::cout << x << ' ' << y  << ' ' << z << std::endl;
    // std::cout << std::boolalpha << x.is_bigger(y) << std::endl;
    // std::cout << std::boolalpha << x.is_smaller(y) << std::endl;
    // std::cout << std::boolalpha << x.is_equal(y) << std::endl;

    x.~Twelve();
    y.~Twelve();
    z.~Twelve();
    return 0;
}