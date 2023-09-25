#include <iostream>

int main() {
    
    int* px = new int;
    *px = 1;

    int* py = new int;
    *py = 1;


    std::cout << *px << ' ' << px << " | " << *py << ' ' << py << std::endl;

    py = px;

    std::cout << *px << ' ' << px << " | " << *py << ' ' << py << std::endl;


    delete px;
    delete py;

    return 0;
}