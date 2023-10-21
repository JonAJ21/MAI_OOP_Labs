#include "square.h"

bool Square::is_square(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const {
    double lens[6];

    lens[0] = get_len(first, second);
    lens[1] = get_len(first, third);   
    lens[2] = get_len(first, fourth);   
    lens[3] = get_len(second, third);   
    lens[4] = get_len(second, fourth);   
    lens[5] = get_len(third, fourth);            
    
    // Bubble sort
    for (size_t i = 0; i < 5; ++i) {
        int swapped = 0;
        for (size_t j = 0; j < 5 - i; ++j) {
            if (lens[j] > lens[j + 1]) {
                double temp = lens[j];
                lens[j] = lens[j + 1];
                lens[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }

    return (are_equal(lens[0], lens[1], 1e-6) && are_equal(lens[0], lens[2], 1e-6) && are_equal(lens[0], lens[3], 1e-6) &&
            are_equal(lens[4], lens[5], 1e-6) && are_equal(lens[4], lens[0] * sqrt(2), 1e-6));
}


Square::Square(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) {
    // std::cout << "Init_list constructor" << std::endl;

    if (!is_square(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a square");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

Square::Point2D Square::center() const noexcept {
    Point2D center;
    center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
    center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
    return center;
}

double Square::area() const noexcept {
    double len_1 = get_len(_first, _second);
    double len_2 = get_len(_first, _third);
    double len_3 = get_len(_first, _fourth);
    if (len_1 <= len_2 && len_1 <= len_3) return (len_1 * len_1);
    if (len_2 <= len_1 && len_2 <= len_3) return (len_2 * len_2);
    return (len_3 * len_3);

}

Square::operator double() const noexcept {
    return area();
}

bool Square::operator==(Square const & sq) const {
    return (_first.x == sq._first.x && _first.y == sq._first.x && 
            _second.x == sq._second.x && _second.y == sq._second.y && 
            _third.x == sq._third.x && _third.y == sq._third.y && 
            _fourth.x == sq._fourth.x && _fourth.y == sq._fourth.y);
}

void Square::input(std::istream& is) {
    Square::Point2D first, second, third, fourth;

    is >> first.x >> first.y;
    is >> second.x >> second.y;
    is >> third.x >> third.y;
    is >> fourth.x >> fourth.y;

    if (!is_square(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a square");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

void Square::print(std::ostream& os) const {
    os << '{' << _first.x << ", " << _first.y << "} ";
    os << '{' << _second.x << ", " << _second.y << "} ";
    os << '{' << _third.x << ", " << _third.y << "} ";
    os << '{' << _fourth.x << ", " << _fourth.y << "} ";
}



std::istream& operator>>(std::istream& is, Square& sq) {
    sq.input(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, Square const & sq) {
    sq.print(os);
    return os;
}