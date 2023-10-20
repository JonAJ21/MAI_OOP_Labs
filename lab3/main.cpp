#include <iostream>
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include <typeinfo>
int main() {
   Square s1 {{0,0}, {1,0}, {1,1}, {0,1}}; 
   Square s2 {{0,0}, {2,0}, {2,2}, {0,2}}; 
   bool x = s1 == s2;
   std::cout << x << std::endl;

    return 0;
}  