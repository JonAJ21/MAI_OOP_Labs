#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

template<typename T>
class Trapezoid final : public Figure<T> {
private:
    Point2D<T> _first;
    Point2D<T> _second;
    Point2D<T> _third;
    Point2D<T> _fourth;

    bool is_trapezoid(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth) const;

public:
    explicit Trapezoid() = default;
    explicit Trapezoid(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth);

    Point2D<T> center() const noexcept override;
    double area() const noexcept override;
    explicit operator double() const noexcept override;
    bool operator==(Trapezoid<T> const & tr);

    void input(std::istream& is) override;
    void print(std::ostream& os) const override;

    template<T> friend std::istream& operator>>(std::istream& is, Trapezoid<T> & tr);
    template<T> friend std::ostream& operator<<(std::ostream& os, Trapezoid<T> const & tr); 
};

template<typename T>
bool Trapezoid<T>::is_trapezoid(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth) const {
   // Points must be in traversal order
    if (are_equal(first.x, second.x, 1e-6) && are_equal(second.x, third.x, 1e-6)) return false;
    if (are_equal(first.y, second.y, 1e-6) && are_equal(second.y, third.y, 1e-6)) return false;

    if (are_sides_parallel(first, second, third, fourth)) {
        return !(are_sides_parallel(second, third, fourth, first));
    }
    return are_sides_parallel(second, third, fourth, first);
}

template<typename T>
Trapezoid<T>::Trapezoid(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth) {
    if (!is_trapezoid(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a trapezoid");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

template<typename T>
Point2D<T> Trapezoid<T>::center() const noexcept{
    Point2D<T> center;
    center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
    center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
    return center;
};

template<typename T>
double Trapezoid<T>::area() const noexcept{
    double a, b, c, d;
    if (are_sides_parallel(_first, _second, _third, _fourth)) {
        a = get_len(_third, _fourth);
        b = get_len(_first, _second);
        c = get_len(_first, _fourth);
        d = get_len(_second, _third);
    } else {
        a = get_len(_first, _fourth);
        b = get_len(_second, _third);
        c = get_len(_first, _second);
        d = get_len(_third, _fourth);
    }
    double height = sqrt((c * c) - ((((a - b) * (a - b) + c * c - d * d)/(2 * (a - b))) * (((a - b) * (a - b) + c * c - d * d)/(2 * (a - b)))));
    return (a + b) * height * 0.5;
};

template<typename T>
Trapezoid<T>::operator double() const noexcept {
    return area();
};

template<typename T>
bool Trapezoid<T>::operator==(Trapezoid<T> const & tr) {
    return (are_equal(_first.x, tr._first.x, 1e-6) && are_equal(_first.y, tr._first.y, 1e-6) &&
            are_equal(_second.x, tr._second.x, 1e-6) && are_equal(_second.y, tr._second.y, 1e-6) &&
            are_equal(_third.x, tr._third.x, 1e-6) && are_equal(_third.y, tr._third.y, 1e-6) &&
            are_equal(_fourth.x, tr._fourth.x, 1e-6) && are_equal(_fourth.y, tr._fourth.y, 1e-6));
}

template<typename T>
void Trapezoid<T>::input(std::istream& is) {
    Point2D<T> first, second, third, fourth;

    is >> first.x >> first.y;
    is >> second.x >> second.y;
    is >> third.x >> third.y;
    is >> fourth.x >> fourth.y;

    if (!is_trapezoid(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a trapezoid");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

template<typename T>
void Trapezoid<T>::print(std::ostream& os) const {
    os << '{' << _first.x << ", " << _first.y << "} ";
    os << '{' << _second.x << ", " << _second.y << "} ";
    os << '{' << _third.x << ", " << _third.y << "} ";
    os << '{' << _fourth.x << ", " << _fourth.y << "} ";
}

template<typename T>
std::istream& operator>>(std::istream& is, Trapezoid<T>& tr) {
    tr.input(is);
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Trapezoid<T> const & tr) {
    tr.print(os);
    return os;
}

#endif // TRAPEZOID_H