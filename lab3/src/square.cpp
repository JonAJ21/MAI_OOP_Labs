#include "square.h"

bool Square::is_square(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const {
    double lens[6];

    lens[0] = get_len(first, second);
    lens[1] = get_len(first, third);   
    lens[2] = get_len(first, fourth);   
    lens[3] = get_len(second, third);   
    lens[4] = get_len(second, fourth);   
    lens[5] = get_len(third, fourth);            
    
    // Machine epsilon
    double epsilon = get_machine_epsilon();
    
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
    return ((lens[1] - lens[0] < epsilon) && (lens[2] - lens[0] < epsilon) && (lens[3] - lens[0] < epsilon) &&
            (lens[5] - lens[4] < epsilon) && (lens[4] - lens[0] * sqrt(2) < epsilon));
}


Square::Square() : _first({0, 0}), _second({0, 0}), _third({0, 0}), _fourth({0, 0}) {
    std::cout << "Default constructor" << std::endl;
}

Square::Square(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) {
    std::cout << "Init_list constructor" << std::endl;

    if (!is_square(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a square");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

Square::Square(Square const & sq) : _first(sq._first), _second(sq._second), _third(sq._third), _fourth(sq._fourth) {
    std::cout << "Copy constructor" << std::endl;
}

Square::Square(Square&& sq) : _first(sq._first), _second(sq._second), _third(sq._third), _fourth(sq._fourth) {
    std::cout << "Move constructor" << std::endl;
    sq._first = {0, 0};
    sq._second = {0, 0};
    sq._third = {0, 0};
    sq._fourth = {0, 0};
}

Square& Square::operator=(Square const & sq) noexcept {
    std::cout << "Copy assignment operator" << std::endl;
    if (this == &sq) {
        return *this;
    }
    _first = sq._first;
    _second = sq._second;
    _third = sq._third;
    _fourth = sq._fourth;
    return *this;
}

Square& Square::operator=(Square&& sq) noexcept {
    std::cout << "Move assignment operator" << std::endl;
    if (this == &sq) {
        return *this;
    }
    sq._first = {0, 0};
    sq._second = {0, 0};
    sq._third = {0, 0};
    sq._fourth = {0, 0};
    return *this;
}

Square::~Square() noexcept {
    std::cout << "Destructor" << std::endl;
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

bool Square::operator==(Square const & sq) {
    return abs(area() - sq.area()) < get_machine_epsilon();
}



std::istream& operator>>(std::istream& is, Square& sq) {
    Square::Point2D first, second, third, fourth;

    is >> first.x >> first.y;
    is >> second.x >> second.y;
    is >> third.x >> third.y;
    is >> fourth.x >> fourth.y;

    if (!sq.is_square(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a square");
    }
    sq._first = first;
    sq._second = second;
    sq._third = third;
    sq._fourth = fourth;
    return is;
}

std::ostream& operator<<(std::ostream& os, Square const & sq) {
    os << '{' << sq._first.x << ", " << sq._first.y << "} ";
    os << '{' << sq._second.x << ", " << sq._second.y << "} ";
    os << '{' << sq._third.x << ", " << sq._third.y << "} ";
    os << '{' << sq._fourth.x << ", " << sq._fourth.y << "} ";
    return os;
}
