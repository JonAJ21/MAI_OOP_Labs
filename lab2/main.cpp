#include <iostream>
#include "twelve.h"

int main() {

    Twelve x {"9a38b"};
    Twelve y {"69a77"};
    Twelve z = x.add(y);

    std::cout << x << ' ' << y  << ' ' << z << std::endl;
    // std::cout << std::boolalpha << x.is_bigger(y) << std::endl;
    // std::cout << std::boolalpha << x.is_smaller(y) << std::endl;
    // std::cout << std::boolalpha << x.is_equal(y) << std::endl;

    x.~Twelve();
    y.~Twelve();
    return 0;
}