#include "twelve.h"
#include <cstring>

//----------------------------------------------

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
    size_t i = _sz;
    for (auto ch : init_list) {
        if (strchr(ALPHABET, toupper(ch)) != nullptr) {
            _number[--i] = toupper(ch);
        } else {
            std::cout << "Error: incorrect value of type Twelve" << std::endl;
            throw "Error: incorrect value of type Twelve";
        }
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
        if (strchr(ALPHABET, toupper(str[i])) != nullptr) {
            _number[_sz - i - 1] = toupper(str[i]);
        } else {
            std::cout << "Error: incorrect value of type Twelve" << std::endl;
            throw "Error: incorrect value of type Twelve";
        }
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
// Twelve& Twelve::operator=(Twelve&& other) {
//     //TODO
// }

Twelve::~Twelve() noexcept {
    _sz = 0;
    delete[] _number;
    _number = nullptr;
}  

//----------------------------------------------
// Methods TODO

std::ostream& Twelve::print(std::ostream& os) {
    for (size_t i = 0; i < _sz; ++i) {
        os << _number[_sz - i - 1];
    }
    return os;
}

bool Twelve::is_bigger(Twelve& other) {
    if (_sz > other._sz) {
        return true;
    } else if (_sz < other._sz) {
        return false;
    } else {
        for (size_t i = 0; i < _sz; ++i) {
            char lhs_ch = _number[_sz - i - 1];
            char rhs_ch = other._number[_sz - i - 1];
            if (lhs_ch > rhs_ch) {
                return true;
            }
            if (lhs_ch < rhs_ch) {
                return false;
            }
        }
        return false;
    }
}

bool Twelve::is_smaller(Twelve& other) {
    if (_sz < other._sz) {
        return true;
    } else if (_sz < other._sz) {
        return false;
    } else {
        for (size_t i = 0; i < _sz; ++i) {
            char lhs_ch = _number[_sz - i - 1];
            char rhs_ch = other._number[_sz - i - 1];
            if (lhs_ch < rhs_ch) {
                return true;
            }
            if (lhs_ch > rhs_ch) {
                return false;
            }
        }
        return false;
    }
}

bool Twelve::is_equal(Twelve& other) {
    if (_sz != other._sz) {
        return false;
    }
    for (size_t i = 0; i < _sz; ++i) {
        if (_number[i] != other._number[i]) {
            return false;
        }
    }
    return true;
}

// Twelve Twelve::add(Twelve& other) {

// }