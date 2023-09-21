#include <iostream>
#include "to_bin_32.h"

int main() {
    uint32_t num;
    std::cin >> num;
    
    char* res = to_bin_32(num);
    std::cout << res << std::endl;
    
    delete[] res;
    
    return 0;
}