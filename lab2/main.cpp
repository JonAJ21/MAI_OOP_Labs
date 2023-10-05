#include <iostream>
#include "twelve.h"

int main() {
    
    Twelve a {"31b41aa"};
    Twelve b {"3baba"};
    Twelve c = a;
    Twelve d = a.substract(b);
    Twelve e = a.substract(c);
    Twelve f = a.add(b);
    Twelve g = a.add(a);
    
    std::cout << &a << ' ' << &b << ' ' << &c << std::endl;
    std::cout << a << " - " << b << " = " << d << std::endl;
    std::cout << a << " - " << c << " = " << e << std::endl;
    std::cout << a << " + " << b << " = " << f << std::endl;
    std::cout << a << " + " << c << " = " << g << std::endl;
    std::cout << e << std::endl;
    
    a.~Twelve();
    b.~Twelve();
    c.~Twelve();
    d.~Twelve();
    e.~Twelve();
    f.~Twelve();
    g.~Twelve();
    return 0;
}