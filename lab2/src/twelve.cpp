#include "twelve.h"

//----------------------------------------------
// The rule of five
Twelve::Twelve() : _sz(0), _number(nullptr) {
    std::cout << "Default constructor" << std::endl; 
}

Twelve::Twelve(const std::initializer_list<unsigned char>& init_list) : _sz(init_list.size()) {
    std::cout << "Initializer list constructor" << std::endl;
    try {
        _number = new unsigned char[_sz + 1];
    } catch (std::bad_alloc& exception) {
        throw exception;
    }
    size_t i = 0;
    for (auto ch : init_list) {
        _number[i++] = ch;
    }
    _number[_sz] = '\0';
}

Twelve::Twelve(const std::string& str) : _sz(str.size()) {
    std::cout << "Copy string constructor" << std::endl;
    try {
        _number = new unsigned char[_sz + 1];
    } catch (std::bad_alloc& exception) {
        throw exception;
    }
    for (size_t i = 0; i < _sz; ++i) {
        _number[i] = str[i];
    }
    _number[_sz] = '\0';
}

Twelve::Twelve(const Twelve& other) : _sz(other._sz) {
    std::cout << "Copy constructor" << std::endl;
    try {
        _number = new unsigned char[_sz + 1];
    } catch (std::bad_alloc& exception) {
        throw exception;
    }
    for (size_t i = 0; i < _sz; ++i) {
        _number[i] = other._number[i];
    }
    _number[_sz] = '\0';
}

Twelve::Twelve(Twelve&& other) noexcept : _sz(other._sz), _number(other._number) {
    std::cout << "Move constructor" << std::endl;
    other._sz = 0;
    other._number = nullptr;
}

// ????????????????????????
Twelve& Twelve::operator=(Twelve&& other) {
    //TODO
}

Twelve::~Twelve() noexcept {
    _sz = 0;
    delete[] _number;
    _number = nullptr;
}  

//----------------------------------------------
// Methods

Twelve Twelve::add(Twelve& other) {
    unsigned char alphabet[] = "0123456789AB";
}
