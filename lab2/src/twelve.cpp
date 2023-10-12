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

Twelve::Twelve(std::initializer_list<unsigned char> const & init_list) : _sz(init_list.size()) {
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

Twelve::Twelve(std::string const & str) : _sz(str.size()) {
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

Twelve::Twelve(Twelve const & other) : _sz(other._sz) {
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

Twelve& Twelve::operator=(Twelve const & other) {
    _sz = other._sz; 
    _number = new unsigned char[_sz + 1];
    for (size_t i = 0; i < _sz; ++i) {
        _number[i] = other._number[i];
    }
    _number[_sz] = '\0';
    std::cout << "Copy assigned" << std::endl;
    return *this;
}

Twelve& Twelve::operator=(Twelve&& other) noexcept {
    // _number = std::move(other._number);
    // _sz = std::move(other._sz);
    _number = other._number;
    _sz = other._sz;
    other._sz = 0;
    other._number = nullptr;
    std::cout << "Move assigned" << std::endl;
    return *this;
}

Twelve::~Twelve() noexcept {
    delete[] _number;
    _number = nullptr;
}  

//----------------------------------------------
// Methods

size_t Twelve::get_sz() const {
    return this->_sz;
}

unsigned char* Twelve::get_number() const {
    return this->_number;
}


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


Twelve Twelve::add(const Twelve & other) const {
    Twelve num;
    num._sz = _sz > other._sz ? _sz : other._sz;
    num._number = new unsigned char[num._sz + 1];
    int digit_1;
    int digit_2;
    int carry = 0;
    for (size_t i = 0; i < num._sz; ++i) {
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
        num._number[i] = ALPHABET[sum % (sizeof(ALPHABET) - 1)];
        carry = sum / (sizeof(ALPHABET) - 1);
    }
    Twelve res;
    if (carry == 0) {
        res = std::move(num);
        res._number[res._sz] = '\0';
        num.~Twelve();
        return res;
    }
    res._sz = num._sz + 1;
    res._number = new unsigned char[res._sz + 1];
    res._number[res._sz - 1] = ALPHABET[carry];
    for (size_t i = 0; i < res._sz - carry; ++i) {
        res._number[i] = num._number[i];
    }
    res._number[res._sz] = '\0';
    num.~Twelve();
    return res; 
}



Twelve Twelve::substract(Twelve const & other) const {
    if (this->is_smaller(other)) {
        std::cout << "Error: negative answer (lhs < rhs)" << std::endl;
        throw "Error: negative answer";
    }
    if (this->is_equal(other)) {
        Twelve res;
        res._sz = 1;
        res._number = new unsigned char[res._sz + 1];
        res._number[0] = '0';
        res._number[res._sz] = '\0';
        return res;
    }
    Twelve num {*this};
    int carry = 0;
    int digit_1;
    int digit_2;
    for (size_t i = 0; i < other._sz || carry; ++i) {
        if (i < other._sz) {
            digit_2 = isdigit(other._number[i]) ? other._number[i] - '0' : other._number[i] - 'A' + 10;
        } else {
            digit_2 = 0;
        }
        digit_1 = isdigit(num._number[i]) ? num._number[i] - '0' : num._number[i] - 'A' + 10;
        digit_1 -= carry + digit_2;
        num._number[i] = ALPHABET[digit_1];
        carry = digit_1 < 0;
        if (carry) {
            digit_1 += sizeof(ALPHABET) - 1;
            num._number[i] = ALPHABET[digit_1];
        }
    }
    size_t count = 0;
    for (size_t i = 0; i < _sz; ++i) {
        if (num._number[_sz - i - 1] != '0') {
            break;
        }
        ++count;   
    }
    Twelve res;
    res._sz = _sz - count;
    res._number = new unsigned char[res._sz + 1];
    res._number[res._sz] = '\0';
    for (int i = 0; i < res._sz; ++i) {
        res._number[i] = num._number[i];
    }
    num.~Twelve();
    return res;
}

std::ostream& operator<<(std::ostream& os, Twelve const & t) {
    for (size_t i = 0; i < t._sz; ++i) {
        os << t._number[t._sz - i - 1];
    }
    return os; 
}
