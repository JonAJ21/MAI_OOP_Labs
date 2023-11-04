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


template<typename T>
class Array final {
private:
    size_t _capacity;
    size_t _sz;
    std::shared_ptr<std::shared_ptr<T>[]> _figures;
public:
    Array();
    Array(std::initializer_list<std::shared_ptr<T>> const & init_list);
    Array(Array<T> const & array);
    Array(Array<T>&& array);
    Array<T>& operator=(Array<T> const & array);
    Array<T>& operator=(Array<T>&& array);
    ~Array();

    std::shared_ptr<T>& operator[](size_t i);
    Array<T>& push_back(std::shared_ptr<T> const & figure_ptr);
    Array<T>& insert(std::shared_ptr<T> const & figure_ptr, size_t idx);
    Array<T>& remove(size_t idx);
    bool is_empty() const;
    size_t size() const;

    void print() const;
};

template<typename T>
Array<T>::Array() : _sz(0), _capacity(0), _figures(nullptr) {
    // _figures = std::make_shared< std::shared_ptr<T>[] >(_capacity);
}

template<typename T>
Array<T>::Array(std::initializer_list<std::shared_ptr<T>> const & init_list) : _sz(init_list.size()), _capacity(init_list.size() * 2) {
    std::cout << "Init list constructor" << std::endl;
    _figures = std::make_shared< std::shared_ptr<T>[] >(_capacity);
    size_t i = 0;
    for (auto figure_ptr : init_list) {
        _figures[i] = figure_ptr;
        ++i;
    }
    std::cout << "init" << std::endl;
}

template<typename T>
Array<T>::Array(Array const & array) : _sz(array._sz), _capacity(array._sz * 2) {
    _figures = std::make_shared< std::shared_ptr<T>[] >(_capacity);
    for (size_t i = 0; i < _sz; ++i) {
        if (typeid(*array._figures[i]) == typeid(Square<T>)) {
            std::shared_ptr<Square<T>> square_ptr{std::dynamic_pointer_cast<Square<T>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Square<T>>(Square<T>(*square_ptr));
        } else if (typeid(*array._figures[i]) == typeid(Rectangle<T>)) {
            std::shared_ptr<Rectangle<T>> square_ptr{std::dynamic_pointer_cast<Rectangle<T>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Rectangle<T>>(Rectangle<T>(*square_ptr));

        } else if (typeid(*array._figures[i]) == typeid(Trapezoid<T>)) {
            std::shared_ptr<Trapezoid<T>> square_ptr{std::dynamic_pointer_cast<Trapezoid<T>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Trapezoid<T>>(Trapezoid<T>(*square_ptr));

        } else {
            throw std::invalid_argument("Incorrect type");
        }
    }
}

template<typename T>
Array<T>::Array(Array<T>&& array) : _sz(array._sz), _capacity(array._capacity), _figures(array._figures) {
    array._figures = nullptr;
    array._sz = 0;
    array._capacity = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T> const & array) {
    std::cout << "Copy assignment operator" << std::endl;
    _sz = array._sz;
    _figures = std::make_shared< std::shared_ptr<T>[] >(_sz);
    for (size_t i = 0; i < _sz; ++i) {
        if (typeid(*array._figures[i]) == typeid(Square<T>)) {
            std::shared_ptr<Square<T>> square_ptr{std::dynamic_pointer_cast<Square<T>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Square<T>>(Square<T>(*square_ptr));
        } else if (typeid(*array._figures[i]) == typeid(Rectangle<T>)) {
            std::shared_ptr<Rectangle<T>> square_ptr{std::dynamic_pointer_cast<Rectangle<T>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Rectangle<T>>(Rectangle<T>(*square_ptr));

        } else if (typeid(*array._figures[i]) == typeid(Trapezoid<T>)) {
            std::shared_ptr<Trapezoid<T>> square_ptr{std::dynamic_pointer_cast<Trapezoid<T>>(array._figures[i])}; 
            _figures[i] = std::make_shared<Trapezoid<T>>(Trapezoid<T>(*square_ptr));

        } else {
            throw std::invalid_argument("Incorrect type");
        }
    }
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& array) {
    _figures = array._figures;
    _sz = array._sz;
    array._figures = nullptr;
    array._sz = 0;
    return *this;
}


template<typename T>
Array<T>::~Array() {
    std::cout << "Destructor" << std::endl; // Можно поставить  = default
}

template<typename T>
std::shared_ptr<T>& Array<T>::operator[](size_t idx) {
    if (!(0 <= idx && idx < _sz)) {
        throw std::invalid_argument("Index out of range");
    } 
    return _figures[idx];
}

template<typename T>
Array<T>& Array<T>::push_back(std::shared_ptr<T> const & figure_ptr) {
    
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

template<typename T>
Array<T>& Array<T>::insert(std::shared_ptr<T> const & figure_ptr, size_t idx) {
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

template<typename T>
Array<T>& Array<T>::remove(size_t idx) {
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

template<typename T>
bool Array<T>::is_empty() const {
    return _sz == 0;
}

template<typename T>
size_t Array<T>::size() const {
    return _sz;
}

template<typename T>
void Array<T>::print() const {
    for (size_t i = 0; i < _sz; ++i) {
        std::cout << *_figures[i] << std::endl;
    }
}

#endif // ARRAY_H