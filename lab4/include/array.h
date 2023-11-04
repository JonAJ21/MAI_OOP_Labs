#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <memory>
#include <typeinfo>
#include "point2d.h"
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"


template<typename T, typename U>
class Array final {
private:
    size_t _capacity;
    size_t _sz;
    std::shared_ptr<std::shared_ptr<T>[]> _figures;
public:
    Array();
    Array(std::initializer_list<std::shared_ptr<T>> const & init_list);
    Array(Array<T, U> const & array);
    Array(Array<T, U>&& array);
    Array<T, U>& operator=(Array<T, U> const & array);
    Array<T, U>& operator=(Array<T, U>&& array);
    ~Array() = default;

    std::shared_ptr<T>& operator[](size_t i);
    Array<T, U>& push_back(std::shared_ptr<T> const & figure_ptr);
    Array<T, U>& insert(std::shared_ptr<T> const & figure_ptr, size_t idx);
    Array<T, U>& remove(size_t idx);
    bool is_empty() const;
    size_t size() const;

    void print() const;
};

template<typename T, typename U>
Array<T, U>::Array() : _sz(0), _capacity(0), _figures(nullptr) {
}

template<typename T, typename U>
Array<T, U>::Array(std::initializer_list<std::shared_ptr<T>> const & init_list) : _sz(init_list.size()), _capacity(init_list.size() * 2) {
    _figures = std::make_shared< std::shared_ptr<T>[] >(_capacity);
    size_t i = 0;
    for (auto figure_ptr : init_list) {
        _figures[i] = figure_ptr;
        ++i;
    }
}

template<typename T, typename U>
Array<T, U>::Array(Array<T, U> const & array) : _sz(array._sz), _capacity(array._capacity) {
    _figures = std::make_shared< std::shared_ptr<T>[] >(_capacity);
    for (size_t i = 0; i < _sz; ++i) {
        if (typeid(*array._figures[i]) == typeid(Square<U>)) {
            std::shared_ptr<Square<U>> square_ptr{std::dynamic_pointer_cast<Square<U>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Square<U>>(Square<U>(*square_ptr));
        } else if (typeid(*array._figures[i]) == typeid(Rectangle<U>)) {
            std::shared_ptr<Rectangle<U>> square_ptr{std::dynamic_pointer_cast<Rectangle<U>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Rectangle<U>>(Rectangle<U>(*square_ptr));

        } else if (typeid(*array._figures[i]) == typeid(Trapezoid<U>)) {
            std::shared_ptr<Trapezoid<U>> square_ptr{std::dynamic_pointer_cast<Trapezoid<U>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Trapezoid<U>>(Trapezoid<U>(*square_ptr));

        } else {
            throw std::invalid_argument("Incorrect type");
        }
    }
}

template<typename T, typename U>
Array<T, U>::Array(Array<T, U>&& array) : _sz(array._sz), _capacity(array._capacity), _figures(array._figures) {
    array._figures = nullptr;
    array._sz = 0;
    array._capacity = 0;
}

template<typename T, typename U>
Array<T, U>& Array<T, U>::operator=(Array<T, U> const & array) {
    _sz = array._sz;
    _capacity = array._capacity;
    _figures = std::make_shared< std::shared_ptr<T>[] >(_capacity);
    for (size_t i = 0; i < _sz; ++i) {
        if (typeid(*array._figures[i]) == typeid(Square<U>)) {
            std::shared_ptr<Square<U>> square_ptr{std::dynamic_pointer_cast<Square<U>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Square<U>>(Square<U>(*square_ptr));
        } else if (typeid(*array._figures[i]) == typeid(Rectangle<U>)) {
            std::shared_ptr<Rectangle<U>> square_ptr{std::dynamic_pointer_cast<Rectangle<U>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Rectangle<U>>(Rectangle<U>(*square_ptr));

        } else if (typeid(*array._figures[i]) == typeid(Trapezoid<U>)) {
            std::shared_ptr<Trapezoid<U>> square_ptr{std::dynamic_pointer_cast<Trapezoid<U>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Trapezoid<U>>(Trapezoid<U>(*square_ptr));

        } else {
            throw std::invalid_argument("Incorrect type");
        }
    }
    return *this;
}

template<typename T, typename U>
Array<T, U>& Array<T, U>::operator=(Array<T, U>&& array) {
    _figures = array._figures;
    _sz = array._sz;
    _capacity = array._capacity;
    array._figures = nullptr;
    array._sz = 0;
    array._capacity = 0;
    return *this;
}


// template<typename T, typename U>
// Array<T>::~Array() {
//     std::cout << "Destructor" << std::endl; // Можно поставить  = default
// }

template<typename T, typename U>
std::shared_ptr<T>& Array<T, U>::operator[](size_t idx) {
    if (!(0 <= idx && idx < _sz)) {
        throw std::invalid_argument("Index out of range");
    } 
    return _figures[idx];
}

template<typename T, typename U>
Array<T, U>& Array<T, U>::push_back(std::shared_ptr<T> const & figure_ptr) { 
    if (_sz == 0 && _capacity == 0) {
        _figures = std::make_shared< std::shared_ptr<T>[] >(++_capacity);
    }   
    if (_sz == _capacity) {
        _capacity *= 2;
        std::shared_ptr<std::shared_ptr<T>[]> temp;
        temp = std::make_shared< std::shared_ptr<T>[] >(_capacity);
        for (size_t i = 0; i < _sz; ++i) {
            temp[i] = _figures[i];
        }
        _figures = temp;
    }
    _figures[_sz++] = figure_ptr;
    return *this;
}

template<typename T, typename U>
Array<T, U>& Array<T, U>::insert(std::shared_ptr<T> const & figure_ptr, size_t idx) {
    if (!(0 <= idx && idx <= _sz)) {
        throw std::invalid_argument("Index out of range");
    }
    if (_sz == 0 && _capacity == 0) {
        _figures = std::make_shared< std::shared_ptr<T>[] >(++_capacity);
    }
    if (_sz == _capacity) {
        _capacity *= 2;
        std::shared_ptr<std::shared_ptr<T>[]> temp;
        temp = std::make_shared< std::shared_ptr<T>[] >(_capacity);
        for (size_t i = 0; i < _sz; ++i) {
            temp[i] = _figures[i];
        }
        _figures = temp;
    }
    for (size_t i = _sz; i > idx; --i) {
        _figures[i] = _figures[i - 1];
    }
    _figures[idx] = figure_ptr;
    ++_sz;
    return *this;
}

template<typename T, typename U>
Array<T, U>& Array<T, U>::remove(size_t idx) {
    if (!(0 <= idx && idx < _sz)) {
        throw std::invalid_argument("Index out of range");
    }
    --_sz;
    for (size_t i = idx; i < _sz; ++i) {
        _figures[i] = _figures[i + 1];
    }
    _figures[_sz] = nullptr;
    return *this;
}

template<typename T, typename U>
bool Array<T, U>::is_empty() const {
    return _sz == 0;
}

template<typename T, typename U>
size_t Array<T, U>::size() const {
    return _sz;
}

template<typename T, typename U>
void Array<T, U>::print() const {
    for (size_t i = 0; i < _sz; ++i) {
        std::cout << *_figures[i] << std::endl;
    }
}

#endif // ARRAY_H