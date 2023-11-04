#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include "point2d.h"

template<typename T>
class Figure {
public:
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");
    virtual ~Figure() noexcept = default;

    virtual Point2D<T> center() const noexcept = 0;
    virtual double area() const noexcept = 0;
    explicit virtual operator double() const noexcept = 0;

    virtual void input(std::istream& is) = 0;
    virtual void print(std::ostream& os) const = 0;

    template<T> friend std::istream& operator>>(std::istream& is, Figure<T> & fig);
    template<T> friend std::ostream& operator<<(std::ostream& os, Figure<T> const & fig);

};

template<typename T>
std::istream& operator>>(std::istream& is, Figure<T> & fig) {
    fig.input(is);
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Figure<T> const & fig) {
    fig.print(os);
    return os;
}

#endif // FIGURE_H