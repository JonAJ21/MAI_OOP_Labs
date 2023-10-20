#include "trapezoid.h"


bool Trapezoid::is_trapezoid(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const {
   // Points must be in traversal order
    if (first.x == second.x && second.x == third.x) return false;
    if (first.y == second.y && second.y == third.y) return false;
    if (are_sides_parallel(first, second, third, fourth)) {
        return !(are_sides_parallel(second, third, fourth, first));
    }
    return are_sides_parallel(second, third, fourth, first);
}

Trapezoid::Trapezoid(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) {
    // std::cout << "Init_list constructor" << std::endl;

    if (!is_trapezoid(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a trapezoid");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

Trapezoid::Point2D Trapezoid::center() const noexcept{
    Point2D center;
    center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
    center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
    return center;
};

double Trapezoid::area() const noexcept{
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

Trapezoid::operator double() const noexcept {
    return area();
};

bool Trapezoid::operator==(Trapezoid const & tr) {
    return (_first.x == tr._first.x && _first.y == tr._first.x && 
            _second.x == tr._second.x && _second.y == tr._second.y && 
            _third.x == tr._third.x && _third.y == tr._third.y && 
            _fourth.x == tr._fourth.x && _fourth.y == tr._fourth.y);
}

std::istream& operator>>(std::istream& is, Trapezoid& tr) {
    Trapezoid::Point2D first, second, third, fourth;

    is >> first.x >> first.y;
    is >> second.x >> second.y;
    is >> third.x >> third.y;
    is >> fourth.x >> fourth.y;

    if (!tr.is_trapezoid(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a trapezoid");
    }
    tr._first = first;
    tr._second = second;
    tr._third = third;
    tr._fourth = fourth;
    return is;
}

std::ostream& operator<<(std::ostream& os, Trapezoid const & tr) {
    os << '{' << tr._first.x << ", " << tr._first.y << "} ";
    os << '{' << tr._second.x << ", " << tr._second.y << "} ";
    os << '{' << tr._third.x << ", " << tr._third.y << "} ";
    os << '{' << tr._fourth.x << ", " << tr._fourth.y << "} ";
    return os;
}