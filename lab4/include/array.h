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
    size_t _sz;
    std::shared_ptr<std::shared_ptr<Figure<T>>[]> _figures;
public:
    Array();
    Array(std::initializer_list<std::shared_ptr<Figure<T>>> const & init_list);
    Array(Array<T> const & array);
    Array(Array<T>&& array);
    Array<T>& operator=(Array<T> const & array);
    Array<T>& operator=(Array<T>&& array);
    ~Array();

    std::shared_ptr<Figure<T>>& operator[](size_t i);
    Array<T>& push_back(std::shared_ptr<Figure<T>> const & figure_ptr);
    Array<T>& insert(std::shared_ptr<Figure<T>> const & figure_ptr, size_t idx);
    Array<T>& remove(size_t idx);
    bool is_empty() const;
    size_t size() const;


    void print() const;
};

template<typename T>
Array<T>::Array() : _sz(0), _figures(nullptr){
    std::cout << "Default constructor" << std::endl;
}

template<typename T>
Array<T>::Array(std::initializer_list<std::shared_ptr<Figure<T>>> const & init_list) : _sz(init_list.size()) {
    std::cout << "Init list constructor" << std::endl;
    _figures = std::make_shared< std::shared_ptr<Figure<T>>[] >(_sz);
    size_t i = 0;
    for (auto figure_ptr : init_list) {
        _figures[i] = figure_ptr;
        ++i;
    }
}

template<typename T>
Array<T>::Array(Array const & array) : _sz(array._sz) {
    _figures = std::make_shared< std::shared_ptr<Figure<T>>[] >(_sz);
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
Array<T>::Array(Array<T>&& array) : _sz(array._sz), _figures(array._figures) {
    array._figures = nullptr;
    array._sz = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T> const & array) {
    std::cout << "Copy assignment operator" << std::endl;
    _sz = array._sz;
    _figures = std::make_shared< std::shared_ptr<Figure<T>>[] >(_sz);
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