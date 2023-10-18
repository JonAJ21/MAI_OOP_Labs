#include "trapezoid.h"


bool Trapezoid::is_trapezoid(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const {
   // TODO
   return true;
}

Trapezoid::Trapezoid() : _first({0, 0}), _second({0, 0}), _third({0, 0}), _fourth({0, 0}) {
    std::cout << "Default constructor" << std::endl;
}

Trapezoid::Trapezoid(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) {
    std::cout << "Init_list constructor" << std::endl;

    if (!is_trapezoid(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a trapezoid");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

Trapezoid::Trapezoid(Trapezoid const & tr) : _first(tr._first), _second(tr._second), _third(tr._third), _fourth(tr._fourth) {
    std::cout << "Copy constructor" << std::endl;
}

Trapezoid::Trapezoid(Trapezoid&& tr) : _first(tr._first), _second(tr._second), _third(tr._third), _fourth(tr._fourth) {
    std::cout << "Move constructor" << std::endl;
    tr._first = {0, 0};
    tr._second = {0, 0};
    tr._third = {0, 0};
    tr._fourth = {0, 0};
}

Trapezoid& Trapezoid::operator=(Trapezoid const & tr) noexcept {
    std::cout << "Copy assignment operator" << std::endl;
    if (this == &tr) {
        return *this;
    }
    _first = tr._first;
    _second = tr._second;
    _third = tr._third;
    _fourth = tr._fourth;
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& tr) noexcept {
    std::cout << "Move assignment operator" << std::endl;
    if (this == &tr) {
        return *this;
    }
    _first = tr._first;
    _second = tr._second;
    _third = tr._third;
    _fourth = tr._fourth;

    tr._first = {0, 0};
    tr._second = {0, 0};
    tr._third = {0, 0};
    tr._fourth = {0, 0};
    return *this;
}


Trapezoid::~Trapezoid() noexcept {
    std::cout << "Destructor" << std::endl;
}


Trapezoid::Point2D Trapezoid::center() const noexcept{
    Point2D center;
    center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
    center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
    return center;
};

double Trapezoid::area() const noexcept{
    // TODO
    return 0;
};

Trapezoid::operator double() const noexcept {
    return area();
};

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
