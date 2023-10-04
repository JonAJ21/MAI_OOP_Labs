#include "twelve.h"
#include <cstring>

//----------------------------------------------
// Static

char const Twelve::ALPHABET[] = "0123456789AB";

//----------------------------------------------
// The rule of five
Twelve::Twelve() : _sz(0), _number(nullptr) {
    std::cout << "Default constructor" << std::endl; 
}

Twelve::Twelve(const std::initializer_list<unsigned char>& init_list) : _sz(init_list.size()) {
    std::cout << "Initializer list constructor" << std::endl;
    _number = new unsigned char[_sz + 1];
    size_t i = _sz;
    for (auto ch : init_list) {
        _number[--i] = toupper(ch);
        if (strchr(ALPHABET, _number[i]) == nullptr) {
            std::cout << "Error: incorrect value of type Twelve" << std::endl;
            throw "Error: incorrect value of type Twelve";
        }
    }
    _number[_sz] = '\0';
}

Twelve::Twelve(const std::string& str) : _sz(str.size()) {
    std::cout << "Copy string constructor" << std::endl;
    _number = new unsigned char[_sz + 1];
    for (size_t i = 0; i < _sz; ++i) {
        _number[_sz - i - 1] = toupper(str[i]);
        if (strchr(ALPHABET, _number[_sz - i - 1]) == nullptr) {
            std::cout << "Error: incorrect value of type Twelve" << std::endl;
            throw "Error: incorrect value of type Twelve";
        }
    }
    _number[_sz] = '\0';
}

Twelve::Twelve(const Twelve& other) : _sz(other._sz) {
    std::cout << "Copy constructor" << std::endl;
    _number = new unsigned char[_sz + 1];
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
    delete[] _number;
    _number = nullptr;
}  

//----------------------------------------------
// Methods TODO

bool Twelve::is_equal(Twelve const & other) const {
    size_t sz = _sz > other._sz ? _sz : other._sz;
    if (memcmp(_number, other._number, sz) == 0) {
        return true;
    }
    return false;
}


bool Twelve::is_bigger(Twelve const & other) const {
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

bool Twelve::is_smaller(Twelve const & other) const {
    return !(this->is_equal(other) || this->is_bigger(other));
}

Twelve Twelve::add(Twelve const & other) const {
    Twelve result;
    size_t sz = _sz > other._sz ? _sz : other._sz;
    unsigned char* number = new unsigned char[sz + 1];
    int digit_1;
    int digit_2;
    int carry = 0;
    std::cout << "sz: "<< sz << std::endl;
    for (size_t i = 0; i < sz; ++i) {
        if (i < _sz) {
            digit_1 = isdigit(_number[i]) ? _number[i] - '0' : _number[i] - 'A' + 10;
        } else {
            digit_1 = 0;
        }
        if (i < other._sz) {
            digit_2 = isdigit(other._number[i]) ? other._number[i] - '0' : other._number[i] - 'A' + 10;
        } else {
            digit_2 = 0;
        }
        int sum = digit_1 + digit_2 + carry;
        number[i] = ALPHABET[sum % (sizeof(ALPHABET) - 1)];
        carry = sum / (sizeof(ALPHABET) - 1);
        std::cout << i << ' ' << sum << ' ' << carry << std::endl;
    }
    
    // if (carry == 0) {
    //     result._number = new unsigned char[sz + 1];
    // } else {
    //     std::cout << "Carry" << std::endl;
    //     ++sz;
    //     result._number = new unsigned char[sz + 1];
    //     result._number[sz - 1] = ALPHABET[carry];
    //     std::cout << "resnum: "<<  result._number[sz - 1] << std::endl;
    // }
    // result._sz = sz;
    // for (size_t i = 0; i < sz; ++i) {
    //     result._number[i] = number[i];
    // }

    // for (int i = 0; i < sz; ++i) {
    //     std::cout << result._number[i] << std::endl;
    // }
    if (carry == 0) {
        result._number = new unsigned char[sz + 1];
    } else {
        std::cout << "Carry" << std::endl;
        result._number = new unsigned char[++sz + 1];
        result._number[sz - 1] = ALPHABET[carry];
    }
    result._sz = sz;
    for (size_t i = 0; i < sz - carry; ++i) {
        result._number[i] = number[i];
    }

    result._number[sz] = '\0';
    delete[] number;
    return result;
}


// Friend

std::ostream& operator<<(std::ostream& os, Twelve const & t) {
    for (size_t i = 0; i < t._sz; ++i) {
        os << t._number[t._sz - i - 1];
    }
    return os; 
}
