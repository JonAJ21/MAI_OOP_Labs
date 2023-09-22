#include "to_bin_32.h"

char* to_bin_32(uint32_t num) {
    const int SZ = 32;
    char* str;
    try {
        str = new char[SZ + 1];
    }
    catch (const std::bad_alloc& exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
    }
    for (int i = 0; i < SZ; ++i) {
        str[i] = ((num >> (SZ - i - 1)) & 1) + '0';
    }
    str[SZ] = '\0';
    return str;
}